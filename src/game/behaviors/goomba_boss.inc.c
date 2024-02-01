
/**
 * Hitbox for goomba.
 */
static struct ObjectHitbox sGoombaBossHitbox = {
	/* interactType:      */ INTERACT_SPINY_WALKING,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
	/* radius:            */ 43,
    /* height:            */ 70,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 60,
};

static struct ObjectHitbox sGoombaMinionHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

/**
 * Properties that vary based on goomba size.
 */
struct GoombaBossProperties {
    f32 scale;
    u32 deathSound;
    s16 drawDistance;
    s8 damage;
};

/**
 * Properties for regular, huge, and tiny goombas.
 */
static struct GoombaBossProperties sGoombaBossProperties[] = {
	{ 1.5f, SOUND_OBJ_ENEMY_DEATH_HIGH, 6000, 1 },
	{ 5.0f, SOUND_OBJ_ENEMY_DEATH_LOW, 8000, 2 },
	{ 7.5f, SOUND_OBJ_ENEMY_DEATH_LOW, 8000, 2 },
	{ 10.0f, SOUND_OBJ_ENEMY_DEATH_LOW, 8000, 2 },
};

static Vec2f sGoombaMinionSet[][10] = {
	{
		{ -46.0f, 349.406f },
		{ -306.8f, 279.525f },
		{ 214.8f, 419.287f },
	},

	{
		{ -81.4149f, 461.727f },
		{ -81.4149f, -461.727f },
		{ -335.132f, 369.382f },
		{ -335.132f, -369.382f },
		{ 172.302f, 554.073f },
		{ 172.302f, -554.073f },
	},

	{
		{ -93.8698f, 585.743f },
		{ -93.8698f, -585.743f },
		{ -343.901f, 469.152f },
		{ -343.901f, -469.152f },
		{ 156.161f, 702.335f },
		{ 156.161f, -702.335f },
		{ -218.885f, 527.448f },
		{ -218.885f, -527.448f },
		{ 31.146f, 644.039f },
		{ 31.146f, -644.039f },
	},
};

/**
 * Attack handlers for goombas.
 */
static u8 sGoombaBossAttackHandlers[][6] = {
    // regular and tiny
    {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
		/* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
		/* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
		/* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
		/* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
		/* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
    },
    // huge
    {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_SPECIAL_BOSS_GOOMBA_WEAKLY_ATTACKED,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_SPECIAL_BOSS_GOOMBA_SPAWN_MUSHROOM,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_SPECIAL_BOSS_GOOMBA_WEAKLY_ATTACKED,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_SPECIAL_BOSS_GOOMBA_WEAKLY_ATTACKED,
    },
};

static void set_goomba_properties(void) {
	o->oGoombaSize = o->oBehParams2ndByte & GOOMBA_BP_SIZE_MASK;

    o->oGoombaScale = sGoombaBossProperties[o->oGoombaSize].scale;
    o->oDeathSound = sGoombaBossProperties[o->oGoombaSize].deathSound;

    o->oDrawingDistance = sGoombaBossProperties[o->oGoombaSize].drawDistance;
    o->oDamageOrCoinValue = sGoombaBossProperties[o->oGoombaSize].damage;

	o->parentObj = cur_obj_nearest_object_with_behavior(bhvGoombaBossHandler);

	o->oHomeX = lateral_dist_between_objects(o, o->parentObj);
}

/**
 * Initialization function for goomba.
 */
void bhv_goomba_boss_init(void) {
	set_goomba_properties();

	obj_set_hitbox(o, &sGoombaBossHitbox);

	o->oGravity = -5.0f; // -2.0f / 3.0f * o->oGoombaScale

	o->oHitNumber = 0;
	o->oCurrDirection = 0x0;
	o->oAction = 5;
}

void bhv_goomba_minion_init(void) {
	set_goomba_properties();

	obj_set_hitbox(o, &sGoombaMinionHitbox);

	o->oGravity = -8.0f / 3.0f * o->oGoombaScale;
	spawn_mist_particles();
}

static void goomba_boss_turning(void) {
	u16 turnFactor = 0x0;

	// If walking fast enough, play footstep sounds
	if (o->oGoombaRelativeSpeed > 4.0f / 3.0f) {
		cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK);
	}

	if (o->oCurrDirection == 0x0) {
		if (o->oHitNumber == 0) {
			turnFactor = 0x3FAB;
		} else if (o->oHitNumber == 1) {
			turnFactor = 0x3FA2;
		} else if (o->oHitNumber == 2) {
			turnFactor = 0x3F96;
		}
	} else {
		if (o->oHitNumber == 0) {
			turnFactor = 0x4064;
		} else if (o->oHitNumber == 1) {
			turnFactor = 0x406D;
		} else if (o->oHitNumber == 2) {
			turnFactor = 0x4079;
		}
	}

	o->oGoombaTargetYaw = (obj_angle_to_object(o, o->parentObj) + o->oCurrDirection) + turnFactor;

	cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x5000);

	if (cur_obj_is_within_rectangle(-1800.0f, 1800.0f, -5.0f, 5.0f)) {
		o->oPosX = (o->oPosX >= 0.0f) ? o->oHomeX : -o->oHomeX;
	} else if (cur_obj_is_within_rectangle(-5.0f, 5.0f, -1800.0f, 1800.0f)) {
		o->oPosZ = (o->oPosZ >= 0.0f) ? o->oHomeX : -o->oHomeX;
	}
}

/**
 * Enter the jump action and set initial y velocity.
 */
static void goomba_boss_begin_jump(void) {
	if (!(mario_inbetween_cur_obj_angles(o->oGoombaTargetYaw - 0x4000, o->oGoombaTargetYaw + 0x4000))) {
		o->oCurrDirection += (o->oCurrDirection == 0x0) ? 0x8000 : -0x8000;
		o->oGoombaTargetYaw += 0x8000;
	}

    cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);

    o->oAction = GOOMBA_ACT_JUMP;
    o->oForwardVel = 0.0f;

	if (cur_obj_has_behavior(bhvGoombaBoss)) {
		o->oVelY = 52.5f; // 50.0f = 21.0f / 3.0f * o->oGoombaScale
	} else {
		o->oVelY = 50.0f / 3.0f * o->oGoombaScale;
	}
}

/**
 * If spawned by a triplet spawner, mark the flag in the spawner to indicate that
 * this goomba died. This prevents it from spawning again when mario leaves and
 * comes back.
 */
static void mark_goomba_boss_as_dead(void) {
	if (cur_obj_has_behavior(bhvGoombaBoss)) {
		while (cur_obj_nearest_object_with_behavior(bhvGoombaMinion)) {
			spawn_mist_particles_variable_at_obj(20, 0, 46.0f, cur_obj_nearest_object_with_behavior(bhvGoombaMinion));
			obj_mark_for_deletion(cur_obj_nearest_object_with_behavior(bhvGoombaMinion));
		}

		while (cur_obj_nearest_object_with_behavior(bhvGoomba)) {
			spawn_mist_particles_variable_at_obj(20, 0, 46.0f, cur_obj_nearest_object_with_behavior(bhvGoomba));
			obj_mark_for_deletion(cur_obj_nearest_object_with_behavior(bhvGoomba));
		}
	}
}

static void hit_goomba_boss(void) {
	if (o->oHitNumber == 2) {
		if (o->oTimer == 15) {
			spawn_mist_particles();
			o->oAction = 6;
		}
	} else {
		if (o->oTimer == 15) {
			o->oHitNumber++;
			o->oGoombaScale = sGoombaBossProperties[o->oGoombaSize + o->oHitNumber].scale;
			goomba_boss_begin_jump();
			spawn_mist_particles();
		}
		else if (o->oTimer == 14) {
			o->oPosY += 10.0f;
		}
	}
}

static void goomba_boss_act_walk(void) {
	o->oGoombaRelativeSpeed = 20.0f;
	
	u16 bossAngle = 0x0;
	f32 bossSpeed = 0.0f;
	if (o->oHitNumber == 0) {
		bossAngle = 0x0AAB;
		bossSpeed = 0.4f;
	} else if (o->oHitNumber == 1) {
		bossAngle = 0x0E39;
		bossSpeed = 0.5f;
	} else if (o->oHitNumber == 2) {
		bossAngle = 0x11C7;
		bossSpeed = 0.75f;
	}
	
	// u16 bossAngle = ((((o->oHitNumber * 5) + 15) / 360) * 0x10000); // For some reason, this doesn't work? It always outputs zero.
	// f32 bossSpeed = ((1.0f / 11.4285f) * sqr(o->oHitNumber)) + 0.4f; // This one does, but it's simpler to manually assign the values

	if (cur_obj_has_behavior(bhvGoombaMinion)) {
		f32 posSpeed = sqr(lateral_dist_between_objects(o, o->parentObj) / lateral_dist_between_objects(cur_obj_nearest_object_with_behavior(bhvGoombaBoss), o->parentObj));
		s32 handler2GoomBossAng = obj_angle_to_object(o->parentObj, cur_obj_nearest_object_with_behavior(bhvGoombaBoss)); // Crashes if Goomboss is killed before minion is killed, but logistically, it should never happen

		if (o->oCurrDirection == 0x0) {
			if (cur_obj_inbetween_obj_angles(o->parentObj, (handler2GoomBossAng - bossAngle), handler2GoomBossAng)) {
				obj_forward_vel_approach(500.0f, posSpeed);
			} else if (cur_obj_inbetween_obj_angles(o->parentObj, (handler2GoomBossAng + bossAngle), ((handler2GoomBossAng + bossAngle) * 2))) {
				obj_forward_vel_approach(500.0f, posSpeed);
			}
		} else {
			if (cur_obj_inbetween_obj_angles(o->parentObj, handler2GoomBossAng, (handler2GoomBossAng + bossAngle))) {
				obj_forward_vel_approach(500.0f, posSpeed);
			} else if (cur_obj_inbetween_obj_angles(o->parentObj, ((handler2GoomBossAng - bossAngle) * 2), (handler2GoomBossAng - bossAngle))) {
				obj_forward_vel_approach(500.0f, posSpeed);
			}
		}
	} else {
		obj_forward_vel_approach(500.0f, bossSpeed);
	}

	s32 minAngle = o->oGoombaTargetYaw - 0x5000;
	s32 maxAngle = (o->oCurrDirection == 0x0) ? (o->oGoombaTargetYaw + 0x5000) : (o->oGoombaTargetYaw - 0xB000);
	/*
	if (o->oCurrDirection == 0x8000) {
		maxAngle -= 0x10000;
	}
	*/
	if ((!(mario_inbetween_cur_obj_angles(minAngle, maxAngle)) && (o->oDistanceToMario <= 1000.0f)) && (cur_obj_has_behavior(bhvGoombaBoss)) && (o->oTimer > 30) && (gMarioState->hurtCounter == 0)) {
		o->oAction = GOOMBA_ACT_WAIT;
		set_action_for_all_objects_with_behavior_not_dead(bhvGoombaMinion, GOOMBA_ACT_WAIT);
	}

	goomba_boss_turning();
	
	/* Reference:
    //! By strategically hitting a wall, steep slope, or another goomba, we can
    //  prevent the goomba from turning back toward home for a while (goomba
    //  chase extension)
    //! It seems theoretically possible to get 2-3 goombas to repeatedly touch
    //  each other and move arbitrarily far from their home, but it's
    //  extremely precise and chaotic in practice, so probably can't be performed
    //  for nontrivial distances
    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }

        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 500.0f) {
                // If close to mario, begin chasing him. If not already chasing
                // him, jump first

                if (o->oGoombaRelativeSpeed <= 2.0f) {
                    goomba_boss_begin_jump();
                }

                o->oGoombaTargetYaw = o->oAngleToMario;
                o->oGoombaRelativeSpeed = 20.0f;
            } else {
                // If mario is far away, walk at a normal pace, turning randomly
                // and occasionally jumping

                o->oGoombaRelativeSpeed = 4.0f / 3.0f;

                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer--;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        goomba_boss_begin_jump();
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200);
    }
	*/
}

static void goomba_boss_act_wait(void) {
	if ((cur_obj_has_behavior(bhvGoombaMinion)) && (o->oForwardVel <= 1.0f)) {
		struct Object *regGoomba = spawn_object_abs_with_rot(o, 0, MODEL_GOOMBA, bhvGoomba, o->oPosX, o->oPosY, o->oPosZ, o->oFaceAnglePitch, o->oFaceAngleYaw, o->oFaceAngleRoll);
		regGoomba->parentObj = regGoomba;
		obj_mark_for_deletion(o);
	}
	if ((!cur_obj_nearest_object_with_behavior(bhvGoomba)) && (o->oForwardVel == 0.0f)) {
		goomba_boss_begin_jump();
	} else {
		goomba_boss_turning();
		if (o->oForwardVel <= 0.0f) {
			o->oForwardVel = 0.0f;
		} else {
			o->oForwardVel -= 0.25f;
		}
	}
}

static void spawn_minion_group(void) {
	u8 goombaCount = count_objects_with_behavior(bhvGoombaMinion);
	u8 goombaMax = 3 + (u8)(o->oHitNumber * 3.5f);
	s8 direction = (o->oCurrDirection == 0x0) ? 1 : -1;

	while (goombaCount < goombaMax) {
		struct Object* goombaMinion = spawn_object_relative(0x00, (direction * sGoombaMinionSet[o->oHitNumber][goombaCount][0]), 0, sGoombaMinionSet[o->oHitNumber][goombaCount][1], o, MODEL_GOOMBA, bhvGoombaMinion);
		goombaMinion->oHitNumber = o->oHitNumber;
		goombaMinion->oCurrDirection = o->oCurrDirection;
		goombaCount++;
	}
}

static void goomba_boss_act_spawn_minions(void) {
	if (o->oTimer == 5) {
		spawn_minion_group();
	}
	if (o->oTimer == 15) {
		cur_obj_become_tangible();
		o->oAction = GOOMBA_ACT_WALK;
	}
}

/**
 * This action occurs when either the goomba attacks mario normally, or mario
 * attacks a huge goomba with an attack that doesn't kill it.
 */
static void goomba_boss_act_attacked_mario(void) {
	//! This can happen even when the goomba is already in the air. It's
		//  hard to chain these in practice
	//goomba_boss_begin_jump();
	//o->oGoombaTurningAwayFromWall = FALSE;
	goomba_boss_turning();
	o->oAction = o->oGoombaPrevAction;
}

/**
 * Move until landing, and rotate toward target yaw.
 */
static void goomba_boss_act_jump(void) {
    obj_resolve_object_collisions(NULL);

    //! If we move outside the goomba's drawing radius the frame it enters the
    //  jump action, then it will keep its velY, but it will still be counted
    //  as being on the ground.
    //  Next frame, the jump action will think it has already ended because it is
    //  still on the ground.
    //  This puts the goomba back in the walk action, but the positive velY will
    //  make it hop into the air. We can then trigger another jump.
    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
        o->oAction = 4;
		// o->oAction = GOOMBA_ACT_WALK;
    } else {
		cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x800);
	}
}

static void goomba_boss_act_start(void) {
	if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_181)) {
		o->oGoombaTargetYaw = (obj_angle_to_object(o, o->parentObj) + o->oCurrDirection) + 0x3FAB;
		goomba_boss_begin_jump();
	}
}

static void goomba_boss_act_death(void) {
	if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_182)) {
		o->oNumLootCoins = 0;
		spawn_mist_particles();
		spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
		cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
		obj_mark_for_deletion(o);
	}
}

/**
 * Attack handler for when mario attacks a huge goomba with an attack that
 * doesn't kill it.
 * From the goomba's perspective, this is the same as the goomba attacking
 * mario.
 */
void boss_goomba_weakly_attacked(void) {
	o->oGoombaPrevAction = o->oAction;
    o->oAction = GOOMBA_ACT_ATTACKED_MARIO;
}

void boss_goomba_spawn_mushroom(void) {
	if (o->oNumLootCoins == 1) {
		struct Object *superMushroom = spawn_object(o, MODEL_SUPER, bhv1upWalking);
		SET_BPARAM3(superMushroom->oBehParams, 0x01);
		vec3f_copy(&superMushroom->oPosVec, &gMarioObject->oPosVec);
		o->oNumLootCoins = 0;
	}
	o->oGoombaPrevAction = o->oAction;
	o->oAction = GOOMBA_ACT_ATTACKED_MARIO;
}

static void goomba_hit_boss(struct Object *goomba) {
	if ((lateral_dist_between_objects(o, goomba) < (45.0f * o->oGoombaScale)) &&
		((goomba->oAction == OBJ_ACT_HORIZONTAL_KNOCKBACK) || (goomba->oAction == OBJ_ACT_VERTICAL_KNOCKBACK)) &&
		((o->oAction == GOOMBA_ACT_WALK) || (o->oAction == GOOMBA_ACT_WAIT))) {
		obj_set_squished_action();
		mark_goomba_boss_as_dead();
	}
}

/**
 * Update function for goomba.
 */
void bhv_goomba_boss_update(void) {
    // PARTIAL_UPDATE

	if ((o->oAction == OBJ_ACT_SQUISHED) && (cur_obj_has_behavior(bhvGoombaBoss))) {
		hit_goomba_boss();

		if (cur_obj_nearest_object_with_behavior(bhvGoombaMinion)) {
			obj_mark_for_deletion(cur_obj_nearest_object_with_behavior(bhvGoombaMinion));
		}

		if (cur_obj_nearest_object_with_behavior(bhvGoomba)) {
			obj_mark_for_deletion(cur_obj_nearest_object_with_behavior(bhvGoomba));
		}
	}
	
    f32 animSpeed;

    if (obj_update_standard_actions(o->oGoombaScale)) {
        cur_obj_scale(o->oGoombaScale);
        obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);

        cur_obj_update_floor_and_walls();

        if (o->oGoombaScale == 0.0f || (animSpeed = (o->oForwardVel / o->oGoombaScale * 0.4f)) < 1.0f) {
            animSpeed = 1.0f;
        }

        cur_obj_init_animation_with_accel_and_sound(GOOMBA_ANIM_DEFAULT, animSpeed);

        switch (o->oAction) {
            case GOOMBA_ACT_WALK:
                goomba_boss_act_walk();
                break;
            case GOOMBA_ACT_ATTACKED_MARIO:
                goomba_boss_act_attacked_mario();
                break;
            case GOOMBA_ACT_JUMP:
                goomba_boss_act_jump();
                break;
			case GOOMBA_ACT_WAIT:
				goomba_boss_act_wait();
				break;
			case 4:
				goomba_boss_act_spawn_minions();
				break;
			case 5:
				goomba_boss_act_start();
				break;
			case 6:
				goomba_boss_act_death();
				break;
        }

		if (cur_obj_has_behavior(bhvGoombaBoss)) {
			if (obj_handle_attacks(&sGoombaBossHitbox, GOOMBA_ACT_ATTACKED_MARIO,
				sGoombaBossAttackHandlers[o->oGoombaSize & 0x1])
				&& (o->oAction != GOOMBA_ACT_ATTACKED_MARIO)) {
				mark_goomba_boss_as_dead();
			}
		} else {
			if (obj_handle_attacks(&sGoombaMinionHitbox, GOOMBA_ACT_ATTACKED_MARIO,
				sGoombaBossAttackHandlers[o->oGoombaSize & 0x1])
				&& (o->oAction != GOOMBA_ACT_ATTACKED_MARIO)) {
				mark_goomba_boss_as_dead();
			}
		}
		
		if ((cur_obj_has_behavior(bhvGoombaBoss)) && (cur_obj_nearest_object_with_behavior(bhvGoombaMinion))) {
			goomba_hit_boss(cur_obj_nearest_object_with_behavior(bhvGoombaMinion));
		}
		if ((cur_obj_has_behavior(bhvGoombaBoss)) && (cur_obj_nearest_object_with_behavior(bhvGoomba))) {
			goomba_hit_boss(cur_obj_nearest_object_with_behavior(bhvGoomba));
		}

        cur_obj_move_standard(-78);
    } else {
        o->oAnimState = GOOMBA_ANIM_STATE_EYES_CLOSED;
    }

	if ((o->oPosY <= 250.0f) && (cur_obj_has_behavior(bhvGoombaMinion))) {
		obj_die_if_health_non_positive();
	}
}

void bhv_goomba_boss_handler_update(void) {
	if (!cur_obj_nearest_object_with_behavior(bhvGoombaBoss)) {
		obj_mark_for_deletion(o);
		cur_obj_nearest_object_with_behavior(bhvSpawnObjectFromAnother)->oPosY += 400.0f;
	}
}