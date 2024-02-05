// bully.inc.c

static struct ObjectHitbox sSmallBullyHitbox = {
    /* interactType:      */ INTERACT_BULLY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 73,
    /* height:            */ 123,
    /* hurtboxRadius:     */ 63,
    /* hurtboxHeight:     */ 113,
};

static struct ObjectHitbox sBigBullyHitbox = {
    /* interactType:      */ INTERACT_BULLY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 115,
    /* height:            */ 235,
    /* hurtboxRadius:     */ 105,
    /* hurtboxHeight:     */ 225,
};

void bhv_small_bully_init(void) {
    cur_obj_init_animation(0);
    vec3f_copy(&o->oHomeVec, &o->oPosVec);
    o->oBehParams2ndByte = BULLY_BP_SIZE_SMALL;
    o->oGravity = 4.0f;
    o->oFriction = 0.91f;
    o->oBuoyancy = 1.3f;

    obj_set_hitbox(o, &sSmallBullyHitbox);
}

void bhv_big_bully_init(void) {
    cur_obj_init_animation(0);
    vec3f_copy(&o->oHomeVec, &o->oPosVec);
    o->oBehParams2ndByte = BULLY_BP_SIZE_BIG;
    o->oGravity = 5.0f;
    o->oFriction = 0.93f;
    o->oBuoyancy = 1.3f;

    obj_set_hitbox(o, &sBigBullyHitbox);
}

void bhv_chief_chilly_init(void) {
	cur_obj_init_animation(0);
	vec3f_copy(&o->oHomeVec, &o->oPosVec);
	o->oBehParams2ndByte = BULLY_BP_SIZE_BIG;
	o->oGravity = 5.0f;
	o->oFriction = 0.95f;
	o->oBuoyancy = 1.3f;

	o->oCCHealth = 2;
	o->oCanDropCoins = TRUE;
	o->oCoinChanceMult = 1;
	o->oFinalDeathCheck = FALSE;
	o->prevObj = cur_obj_nearest_object_with_behavior(bhvSquishMarioObj);

	obj_set_hitbox(o, &sBigBullyHitbox);

	o->oAction = 6;
}

void bully_check_mario_collision(void) {
    if (o->oAction != OBJ_ACT_LAVA_DEATH && o->oAction != OBJ_ACT_DEATH_PLANE_DEATH && o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oBehParams2ndByte == BULLY_BP_SIZE_SMALL) {
            cur_obj_play_sound_2(SOUND_OBJ2_SMALL_BULLY_ATTACKED);
        } else {
            cur_obj_play_sound_2(SOUND_OBJ2_LARGE_BULLY_ATTACKED);
        }

        o->oInteractStatus &= ~INT_STATUS_INTERACTED;
        o->oAction = BULLY_ACT_KNOCKBACK;
        o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
        cur_obj_init_animation(3);
        o->oBullyMarioCollisionAngle = o->oMoveAngleYaw;
    }
}

void bully_act_chase_mario(void) {
    f32 homeX = o->oHomeX;
    f32 posY = o->oPosY;
    f32 homeZ = o->oHomeZ;

    if (o->oTimer < 10) {
        o->oForwardVel = 3.0f;
        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x1000);
    } else if (o->oBehParams2ndByte == BULLY_BP_SIZE_SMALL) {
        o->oForwardVel = 20.0f;
        if (o->oTimer > 30) {
            o->oTimer = 0;
        }
    //
    } else if (cur_obj_has_behavior(bhvChiefChilly)) {
		o->oForwardVel = 30.0f;
		obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x100);
		if (!(obj_inbetween_cur_obj_angles(gMarioObject, (o->oFaceAngleYaw - 0x3000), (o->oFaceAngleYaw + 0x3000)))) { // Figure out some way to incorporate this: lateral_dist_between_objects(o, gMarioObject) > 2000.0f
			o->oTimer = 0;
		}
    //
    } else {
        o->oForwardVel = 30.0f;
        if (o->oTimer > 35) {
            o->oTimer = 0;
        }
    }

    if ((!is_point_within_radius_of_mario(homeX, posY, homeZ, 1000)) && !(cur_obj_has_behavior(bhvChiefChilly))) { // Original: if (!is_point_within_radius_of_mario(homeX, posY, homeZ, 1000))
        o->oAction = BULLY_ACT_PATROL;
        cur_obj_init_animation(0);
    }
}

void bully_act_knockback(void) {
    if (o->oForwardVel < 10.0f && (s32) o->oVelY == 0) {
        o->oForwardVel = 1.0f;
        o->oBullyKBTimerAndMinionKOCounter++;
        o->oFlags |= OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
        o->oMoveAngleYaw = o->oFaceAngleYaw;
        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 1280);
    } else {
        o->header.gfx.animInfo.animFrame = 0;
    }

    if (o->oBullyKBTimerAndMinionKOCounter == 18) {
        o->oAction = BULLY_ACT_CHASE_MARIO;
        o->oBullyKBTimerAndMinionKOCounter = 0;
        cur_obj_init_animation(1);
    }
}

void bully_act_back_up(void) {
    if (o->oTimer == 0) {
        o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
        o->oMoveAngleYaw += 0x8000;
    }

    o->oForwardVel = 5.0f;

    //! bully_backup_check() happens after this function, and has the potential to reset
    //  the bully's action to BULLY_ACT_BACK_UP. Because the back up action is only
    //  set to end when the timer EQUALS 15, if this happens on that frame, the bully
    //  will be stuck in BULLY_ACT_BACK_UP forever until Mario hits it or its death
    //  conditions are activated. However because its angle is set to its facing angle,
    //  it will walk forward instead of backing up.

    if (o->oTimer == 15) {
        o->oMoveAngleYaw = o->oFaceAngleYaw;
        o->oFlags |= OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
        o->oAction = BULLY_ACT_PATROL;
    }
}

void bully_backup_check(s16 collisionFlags) {
    if (!(collisionFlags & OBJ_COL_FLAG_NO_Y_VEL) && o->oAction != BULLY_ACT_KNOCKBACK) {
        o->oPosX = o->oBullyPrevX;
        o->oPosZ = o->oBullyPrevZ;
        o->oAction = BULLY_ACT_BACK_UP;
    }
}

void bully_play_stomping_sound(void) {
    s16 animFrame = o->header.gfx.animInfo.animFrame;

    switch (o->oAction) {
        case BULLY_ACT_PATROL:
            if (animFrame == 0 || animFrame == 12) {
                if (o->oBehParams2ndByte == BULLY_BP_SIZE_SMALL) {
                    cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALK_SMALL);
                } else {
                    cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALK_LARGE);
                }
            }
            break;

        case BULLY_ACT_CHASE_MARIO:
        case BULLY_ACT_BACK_UP:
            if (animFrame == 0 || animFrame == 5) {
                if (o->oBehParams2ndByte == BULLY_BP_SIZE_SMALL) {
                    cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALK_SMALL);
                } else {
                    cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALK_LARGE);
                }
            }
            break;
    }
}

void bully_step(void) {
    s16 collisionFlags = object_step();

    bully_backup_check(collisionFlags);
    bully_play_stomping_sound();
    obj_check_floor_death(collisionFlags, sObjFloor);

    if (o->oBullySubtype & BULLY_STYPE_CHILL) {
        if ((o->oPosY < 1030.0f) && (gCurrLevelNum != LEVEL_CCC)) {
            o->oAction = OBJ_ACT_LAVA_DEATH;
		} else if ((o->oPosY < -8.0f) && ((gCurrLevelNum == LEVEL_CCC) && (gCurrAreaIndex == 2))){
			o->oAction = OBJ_ACT_LAVA_DEATH;
		}
        /* Original:
        if (o->oPosY < 1030.0f) {
            o->oAction = OBJ_ACT_LAVA_DEATH;
        }
        */
    }
    //
	if ((cur_obj_has_behavior(bhvChiefChilly)) && (!(collisionFlags & OBJ_COL_FLAG_GROUNDED)) && (o->oAction == BULLY_ACT_KNOCKBACK) && (o->oCCHealth == 0) && (o->oFinalDeathCheck == FALSE)) {
		o->oFinalDeathCheck = TRUE;
		o->oAction = 8;
	}
    //
}

void bully_spawn_coin(void) {
    struct Object *coin = spawn_object(o, MODEL_YELLOW_COIN, bhvMovingYellowCoin);

    cur_obj_play_sound_2(SOUND_GENERAL_COIN_SPURT);

    coin->oForwardVel = 10.0f;
    coin->oVelY = 100.0f;
    coin->oPosY = o->oPosY + 310.0f;
    coin->oMoveAngleYaw = (f32)(o->oBullyMarioCollisionAngle + 0x8000) + random_float() * 1024.0f;
}

static void chief_chilly_jumping(void) {
	struct Object *icePlatform = NULL;

	s16 collisionFlags = object_step();
	s8 addedSpeed = 0;

	if (o->oJumpCount >= 8) {
		icePlatform = cur_obj_nearest_object_with_behavior(bhvFallingIcePlatformA);
		
		addedSpeed = (o->oCCHealth == 2) ? 0 : -25;
	} else if (o->oCCHealth == 1) {
		icePlatform = cur_obj_nearest_object_with_behavior(bhvFallingIcePlatformB);

		addedSpeed = (o->oJumpCount == 0) ? 25 : 15;
	} else if (o->oCCHealth == 2) {
		icePlatform = cur_obj_nearest_object_with_behavior(bhvFallingIcePlatformC);
		
		addedSpeed = (o->oJumpCount == 0) ? 25 : 20;
	}

	if (o->oTimer == 0) {
		o->oFlags |= OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
		obj_turn_toward_object(o, icePlatform, O_MOVE_ANGLE_YAW_INDEX, 0x7FFF);
		o->oVelY = 120.0f; // o->oVelY = 120.0f;
	} else if (!(collisionFlags & OBJ_COL_FLAG_GROUNDED) && (o->oTimer > 15) && !(o->oJumpCount >= 9)) {
		obj_turn_toward_object(o, icePlatform, O_MOVE_ANGLE_YAW_INDEX, 0x7FFF);
		o->oForwardVel = (lateral_dist_between_objects(o, icePlatform) / 15.0f) + addedSpeed;

		if (cur_obj_is_within_rectangle((icePlatform->oPosX - 15.0f), (icePlatform->oPosX + 15.0f), (icePlatform->oPosZ - 15.0f), (icePlatform->oPosZ + 15.0f))) {
			o->oPosX = icePlatform->oPosX;
			o->oPosZ = icePlatform->oPosZ;
			o->oForwardVel = 0;
			o->oMoveAngleYaw = o->oStoredAngle; // This is so CC will keep looking towards center
		} else {
			o->oStoredAngle = o->oMoveAngleYaw;
		}

		if ((o->oJumpCount == 8) && (o->oVelY < 0.0f)) {
			o->prevObj->oCollisionDistance = 1000.0f;
		}
	}

	if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && !(o->oJumpCount >= 8)) {
		o->oJumpCount += 1;
		icePlatform->oBreakAndFall = TRUE;
		o->oVelY = 80.0f; // o->oVelY = 80.0f;
		spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_LIGHT_BLUE);
	} else if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && (o->oJumpCount == 8)) {
		o->oJumpCount += 1;
		if (o->oCCHealth == 1) {
			icePlatform->oBreakAndFall = TRUE;
		}
		spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_LIGHT_BLUE);
		cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
		o->oVelY = 0.0f;
	} else if ((o->oJumpCount >= 9)) {
		if (o->oCCHealth > 1) {
			o->oJumpCount = 0;
			o->oCCHealth--;
			cur_obj_become_tangible();
			cur_obj_init_animation(1);
			o->oAction = BULLY_ACT_CHASE_MARIO;
		} else if ((o->oCCHealth == 1) && (icePlatform->oBreakAndFall == FALSE) && (collisionFlags & OBJ_COL_FLAG_GROUNDED)) {
			o->oJumpCount = 0;
			o->oCCHealth--;
			o->oVelY = 0.0f;
			cur_obj_become_tangible();
			cur_obj_init_animation(1);
			o->oAction = BULLY_ACT_CHASE_MARIO;
		} else {
			o->oForwardVel = 0;
			o->oMoveAngleYaw = o->oStoredAngle; // This is so CC will keep looking at last angle
			o->prevObj->oCollisionDistance = 0.0f;
		}
	}

	if (((o->oTimer % 8) == 0) && (o->oTimer < 30)) {
		cur_obj_play_sound_2(SOUND_OBJ_BULLY_EXPLODE_LAVA);
	}
}

void bully_act_level_death(void) {
    if (obj_lava_death() == TRUE) {
        if (o->oBehParams2ndByte == BULLY_BP_SIZE_SMALL) {
            if (o->oBullySubtype == BULLY_STYPE_MINION) {
                o->parentObj->oBullyKBTimerAndMinionKOCounter++;
            }
            bully_spawn_coin();
        } else {
            spawn_mist_particles();

            if (o->oBullySubtype == BULLY_STYPE_CHILL) {
                spawn_default_star(130.0f, 1600.0f, -4335.0f);
            } else {
                spawn_default_star(0, 950.0f, -6800.0f);
                spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvLllTumblingBridge,
                                          0, 154, -5631, 0, 0, 0);
            }
        }
    }
}

void chief_chilly_act_lava_hit(void) {
	if (o->oCCHealth == 0) {
		cur_obj_become_intangible();
		if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_186)) {
			o->oAction = 7;
		}
	} else {
		cur_obj_become_intangible();
		chief_chilly_jumping();
	}
}

void bhv_bully_loop(void) {
    vec3f_copy(&o->oBullyPrevVec, &o->oPosVec);

    //! Because this function runs no matter what, Mario is able to interrupt the bully's
    //  death action by colliding with it. Since the bully hitbox is tall enough to collide
    //  with Mario even when it is under a lava floor, this can get the bully stuck OOB
    //  if there is nothing under the lava floor.
    bully_check_mario_collision();

    switch (o->oAction) {
        case BULLY_ACT_PATROL:
            o->oForwardVel = 5.0f;

            if (obj_return_home_if_safe(o, o->oHomeX, o->oPosY, o->oHomeZ, 800) == TRUE) {
                o->oAction = BULLY_ACT_CHASE_MARIO;
                cur_obj_init_animation(1);
            }

            bully_step();
            break;

        case BULLY_ACT_CHASE_MARIO:
            bully_act_chase_mario();
            bully_step();
            break;

        case BULLY_ACT_KNOCKBACK:
            bully_act_knockback();
            bully_step();
            break;

        case BULLY_ACT_BACK_UP:
            bully_act_back_up();
            bully_step();
            break;

        case OBJ_ACT_LAVA_DEATH:
            bully_act_level_death();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            break;
    }

    set_object_visibility(o, 3000);
}

static void cc_final_hit_stun(void) {
    s16 collisionFlags = object_step();
	o->oCanDropCoins = FALSE;

	if (o->oTimer == 0) {
		o->oPosX = o->oBullyPrevX * 0.97f;
		o->oPosY = o->oBullyPrevY;
		o->oPosZ = o->oBullyPrevZ * 0.97f;
		o->oFlags |= OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
		obj_turn_toward_object(o, cur_obj_nearest_object_with_behavior(bhvFallingIcePlatformA), O_MOVE_ANGLE_YAW_INDEX, 0x7FFF);
		o->oForwardVel = 0.0f;
		o->oVelY = 0.0f;
	} else if (o->oTimer < 90) {
		o->oPosY = o->oBullyPrevY;
		o->oGravity = 0.0f;
	} else if (o->oTimer == 90) {
		o->oGravity = 5.0f;
		cur_obj_become_intangible();
		o->oForwardVel = 40.0f;
		o->oVelY = 80.0f;
	} else if ((o->oTimer > 90) && !(collisionFlags & OBJ_COL_FLAG_GROUNDED)) {
		if (o->oVelY < 0.0f) {
			o->prevObj->oCollisionDistance = 1000.0f;
		}
		cur_obj_become_intangible();
	} else if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
		o->oFinalDeathCheck = FALSE;
		cur_obj_become_tangible();
		spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_LIGHT_BLUE);
		cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
		o->oVelY = 0.1f;
		o->oAction = BULLY_ACT_PATROL;
	}
}

void bhv_chief_chilly_loop(void) {
    vec3f_copy(&o->oBullyPrevVec, &o->oPosVec);

    //! Because this function runs no matter what, Mario is able to interrupt the bully's
    //  death action by colliding with it. Since the bully hitbox is tall enough to collide
    //  with Mario even when it is under a lava floor, this can get the bully stuck OOB
    //  if there is nothing under the lava floor.
    bully_check_mario_collision();

    switch (o->oAction) {
        case BULLY_ACT_PATROL:
            o->oForwardVel = 5.0f;

            if (obj_return_home_if_safe(o, o->oHomeX, o->oPosY, o->oHomeZ, 99999) == TRUE) {
                o->oAction = BULLY_ACT_CHASE_MARIO;
                cur_obj_init_animation(1);
            }

            bully_step();
            break;

        case BULLY_ACT_CHASE_MARIO:
			o->oCanDropCoins = TRUE;
			o->oCoinChanceMult = 1;
			o->oFinalDeathCheck = FALSE;
			o->prevObj->oCollisionDistance = 0.0f;

            bully_act_chase_mario();
            bully_step();
            break;

        case BULLY_ACT_KNOCKBACK:
			if (o->oFinalDeathCheck == TRUE) {
				if (o->oTimer == 0) {
					obj_turn_toward_object(o, cur_obj_nearest_object_with_behavior(bhvFallingIcePlatformA), O_MOVE_ANGLE_YAW_INDEX, 0x7FFF);
					o->oFaceAngleYaw = o->oMoveAngleYaw;
					o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
					o->oMoveAngleYaw += 0x8000;

					o->oGravity = 5.0f;
					o->oForwardVel = 30.0f;
					o->oVelY = 50.0f;
				}
				o->oFaceAnglePitch -= 0x100;
				cur_obj_become_intangible();
			}

            bully_act_knockback();
            bully_step();
            break;

        case BULLY_ACT_BACK_UP:
            bully_act_back_up();
            bully_step();
            break;

		case 6:
			bully_step();
			cur_obj_init_animation(1);
			if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_185)) {
				o->oAction = BULLY_ACT_CHASE_MARIO;
			}
			break;

		case 7:
			cur_obj_become_intangible();
			if (obj_lava_death() == TRUE) {
				o->oPosX = o->oPosY = o->oPosZ = 0.0f;
				spawn_default_star(0.0f, 640.0f, 0.0f);
			}
			break;

		case 8:
			cc_final_hit_stun();
			break;

        case OBJ_ACT_LAVA_DEATH:
			chief_chilly_act_lava_hit();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            break;
    }

    set_object_visibility(o, 99999);
}

void big_bully_spawn_minion(s32 x, s32 y, s32 z, s16 yaw) {
    struct Object *bully =
        spawn_object_abs_with_rot(o, 0, MODEL_BULLY, bhvSmallBully, x, y, z, 0, yaw, 0);
    bully->oBullySubtype = BULLY_STYPE_MINION;
    bully->oBehParams2ndByte = BULLY_BP_SIZE_SMALL;
}

void bhv_big_bully_with_minions_init(void) {
    big_bully_spawn_minion(4454, 307, -5426, 0);
    big_bully_spawn_minion(3840, 307, -6041, 0);
    big_bully_spawn_minion(3226, 307, -5426, 0);

    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;

    cur_obj_become_intangible();

    o->oAction = BULLY_ACT_INACTIVE;
}

void big_bully_spawn_star(void) {
    if (obj_lava_death() == TRUE) {
        spawn_mist_particles();
        spawn_default_star(3700.0f, 600.0f, -5500.0f);
    }
}

void bhv_big_bully_with_minions_loop(void) {
    s16 collisionFlags = 0;
    vec3f_copy(&o->oBullyPrevVec, &o->oPosVec);

    bully_check_mario_collision();

    switch (o->oAction) {
        case BULLY_ACT_PATROL:
            o->oForwardVel = 5.0f;

            if (obj_return_home_if_safe(o, o->oHomeX, o->oPosY, o->oHomeZ, 1000) == TRUE) {
                o->oAction = BULLY_ACT_CHASE_MARIO;
                cur_obj_init_animation(1);
            }

            bully_step();
            break;

        case BULLY_ACT_CHASE_MARIO:
            bully_act_chase_mario();
            bully_step();
            break;

        case BULLY_ACT_KNOCKBACK:
            bully_act_knockback();
            bully_step();
            break;

        case BULLY_ACT_BACK_UP:
            bully_act_back_up();
            bully_step();
            break;

        case BULLY_ACT_INACTIVE:
            //! The Big Bully that spawns from killing its 3 minions uses the knockback timer
            //  for counting the number of dead minions. This means that when it activates,
            //  the knockback timer is at 3 instead of 0. So the bully knockback time will
            //  be reduced by 3 frames (16.67%) on the first hit.
            if (o->oBullyKBTimerAndMinionKOCounter == 3) {
                play_puzzle_jingle();

                if (o->oTimer > 90) {
                    o->oAction = BULLY_ACT_ACTIVATE_AND_FALL;
                }
            }
            break;

        case BULLY_ACT_ACTIVATE_AND_FALL:
            collisionFlags = object_step();
            if ((collisionFlags & OBJ_COL_FLAGS_LANDED) == OBJ_COL_FLAGS_LANDED) {
                o->oAction = BULLY_ACT_PATROL;
            }

            if (collisionFlags == OBJ_COL_FLAG_GROUNDED) {
                cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
                set_camera_shake_from_point(SHAKE_POS_SMALL, o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
            }

            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_become_tangible();
            break;

        case OBJ_ACT_LAVA_DEATH:
            big_bully_spawn_star();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            break;
    }
}
