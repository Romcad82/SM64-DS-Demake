// hidden_star.inc.c

void bhv_hidden_star_init(void) {
    s16 remainingTriggers = count_objects_with_behavior(bhvHiddenStarTrigger);
    if (remainingTriggers == 0) {
        struct Object *starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        starObj->oBehParams = o->oBehParams;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    o->oHiddenStarTriggerCounter = 5 - remainingTriggers;
}

void bhv_silvers_hidden_star_init(void) {
	s16 remainingTriggers = count_objects_with_behavior(bhvSilverStar);
	if (remainingTriggers == 0) {
		struct Object* starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
		starObj->oBehParams = o->oBehParams;
		o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
	}

	o->oHiddenStarTriggerCounter = 5 - remainingTriggers;

	o->oSpawnSilverStar = FALSE;
}

void bhv_hidden_star_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter == 5) {
                o->oAction = 1;
            }
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_red_coin_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}

void bhv_silvers_hidden_star_loop(void) {
	switch (o->oAction) {
	case 0:
		if (o->oHiddenStarTriggerCounter == 5) {
			o->oAction = 1;
		}
		
		/*
			If Mario gets hit, spawn a silver star (& silver number) where Mario is.
			
			Note: Following files were changed so Silver Stars could work:
				interaction.c: 718
		*/

		if (o->oHiddenStarTriggerCounter == 0) {
			o->oSpawnSilverStar = FALSE;
		}

		// Spawn Silver Star if Mario gets knocked down onto ground. Also check if Silver Star should be spawned
		if (((gMarioState->action >= ACT_HARD_BACKWARD_GROUND_KB) && (gMarioState->action <= ACT_SOFT_FORWARD_GROUND_KB)) && (o->oSpawnSilverStar == TRUE)) {
			o->oHiddenStarTriggerCounter--;
			o->oPlayUpdatedMusic--;

			struct Object *silverStar = spawn_object_relative(0x01, (-o->oPosX + gMarioObject->oPosX), (-o->oPosY + gMarioObject->oPosY), (-o->oPosZ + gMarioObject->oPosZ), o, MODEL_SILVER_STAR, bhvSilverStar);
			silverStar->oMoveAngleYaw = o->oAngleToMario + 0x8000;
			silverStar->oForwardVel = 15.0f;

			#ifdef DIALOG_INDICATOR
			spawn_orange_number((o->oHiddenStarTriggerCounter + (ORANGE_NUMBER_F + 1)), (-o->oPosX + gMarioObject->oPosX), (-o->oPosY + gMarioObject->oPosY), (-o->oPosZ + gMarioObject->oPosZ));
			#else
			spawn_orange_number((o->oHiddenStarTriggerCounter + (ORANGE_NUMBER_9 + 1)), (-o->oPosX + gMarioObject->oPosX), (-o->oPosY + gMarioObject->oPosY), (-o->oPosZ + gMarioObject->oPosZ));
			#endif

			play_silver_star_music(TRUE, 0);

			// Don't let silver star spawn multiple times
			o->oSpawnSilverStar = FALSE;
		}
		break;

	case 1:
		if (o->oTimer > 15) {
			o->parentObj = spawn_and_return_silver_star_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
			o->oAction = 2;
		}
		break;

	case 2:
		if (gMarioState->action & ACT_FLAG_AIR) {
			cur_obj_become_intangible();
		} else {
			cur_obj_become_tangible();
		}

		if (o->parentObj->oInteractStatus & INT_STATUS_INTERACTED) {
			spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_LIGHT_BLUE);
			cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX); // temp
			o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
		}
	}
}

void bhv_hidden_switch_star_init(void) {
	struct Object *starObj = spawn_and_return_switch_star_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
	o->parentObj = starObj;
	SET_BPARAM1(starObj->oBehParams, GET_BPARAM1(o->oBehParams));
	starObj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE; // Hide
	starObj->oIntangibleTimer = -1; // Intangible

	if (cur_obj_nearest_object_with_behavior(bhvStarSwitch)) {
		o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvStarSwitch);
	}
}

void bhv_hidden_switch_star_loop(void) {
	switch (o->oAction) {
	case 0:
		if ((o->oHiddenObjectSwitchObj != NULL) && (o->parentObj != NULL) && (o->oHiddenObjectSwitchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
			o->parentObj->oAction = 4;
			o->oAction = 1;
		}
		break;

	case 1:
		if ((o->oHiddenObjectSwitchObj != NULL) && (o->parentObj != NULL) && (o->oHiddenObjectSwitchObj->oAction == PURPLE_SWITCH_ACT_IDLE)) {
			if (!(o->parentObj->oInteractStatus & INT_STATUS_INTERACTED)) {
				o->parentObj->oAction = 5;
				o->oAction = 0;
			}
		}
		break;
	}

	if (o->parentObj->oIntangibleTimer == 0) {
		if (gMarioState->action & ACT_FLAG_AIR) {
			cur_obj_become_intangible();
		}
		else {
			cur_obj_become_tangible();
		}
	}
	else {
		cur_obj_become_tangible();
	}

	if (o->parentObj->oInteractStatus & INT_STATUS_INTERACTED) {
		o->oHiddenObjectSwitchObj->oBehParams2ndByte = PURPLE_SWITCH_BP_NO_TICK;
		o->oHiddenObjectSwitchObj->oAction = PURPLE_SWITCH_ACT_PRESSED;

		spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_LIGHT_BLUE);
		cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX); // temp
		obj_mark_for_deletion(o);
	}
}

void bhv_hidden_star_trigger_loop(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        struct Object *hiddenStar = cur_obj_nearest_object_with_behavior(bhvHiddenStar);

        if (hiddenStar != NULL) {
            hiddenStar->oHiddenStarTriggerCounter++;

            if (hiddenStar->oHiddenStarTriggerCounter != 5) {
                spawn_orange_number(hiddenStar->oHiddenStarTriggerCounter, 0, 0, 0);
            }

            play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) hiddenStar->oHiddenStarTriggerCounter - 1) << 16), gGlobalSoundSource);
        }

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void bhv_silver_star_init(void) {
	o->parentObj = cur_obj_nearest_object_with_behavior(bhvSilversHiddenStar);

	o->oPosY -= 50.0f;
	vec3f_copy(&o->oHomeVec, &o->oPosVec);

	if (o->oBehParams2ndByte != 0) {
		o->oVelY = 25.0f;
	}
	else {
		o->oGravity = -2.5f;
	}
}

static void mark_silver_star_as_collected(void) {
	struct Object *hiddenStar = o->parentObj;

	if (hiddenStar != NULL) {
		hiddenStar->oHiddenStarTriggerCounter++;

		if (!(hiddenStar->oHiddenStarTriggerCounter >= 6)) {
#ifdef DIALOG_INDICATOR
			spawn_orange_number((hiddenStar->oHiddenStarTriggerCounter + (ORANGE_NUMBER_F + 1)), 0, 0, 0);
#else
			spawn_orange_number((hiddenStar->oHiddenStarTriggerCounter + (ORANGE_NUMBER_9 + 1)), 0, 0, 0);
#endif
		}
	}

	o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}

void bhv_silver_star_loop(void) {
	if (GET_BPARAM4(o->oBehParams) != 0x00) {
		obj_mark_for_deletion(o);
	}

	if ((o->oInteractStatus & INT_STATUS_INTERACTED) && (o->oTimer > 10)) {
		if (o->oCollectedWithShell == FALSE) {
			o->oAction = 1;
		} else {
			o->oAction = 2;
		}
	}

	if (o->oAction == 0) {
		if ((o->oBehParams2ndByte != 0) && (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_UNDERWATER_ON_GROUND))) {
			if (o->oDistanceToMario < 1125.0f) {
				o->oMoveAngleYaw = o->oAngleToMario + 0x8000;
			} else {
				o->oMoveAngleYaw = o->oAngleToMario;
			}
			o->oForwardVel = 15.0f;
			o->oVelY = 25.0f;
			cur_obj_play_sound_2(SOUND_MENU_STAR_SOUND);
		} else if ((o->oBehParams2ndByte == 0) && (o->oPosY <= o->oHomeY)) {
			o->oVelY = 15.0f;
		}

		/* // To test shadows for shadow clipping into floor
		if (o->oBehParams2ndByte != 0) {
			vec3f_copy(&o->oPosVec, &gMarioObject->oPosVec);
			o->oPosX += 250.0f;
		}
		*/

		cur_obj_update_floor_and_walls();
		cur_obj_if_hit_wall_bounce_away();
		cur_obj_move_standard(-90); // There may be a bug where when underwater, y pos gets stuck to floor for few secs. Only happened once, so need to check further. Fix may be in "cur_obj_move_y" in object_helpers.c (o->oPosY = o->oFloorHeight;)

		if ((o->oTimer % 4) == 0) {
			struct Object *sparkleObj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
			sparkleObj->oPosY += 10.0f;
		}

		o->oFaceAngleYaw += 0x800;
	} else if (o->oAction == 1) {
		if (cur_obj_nearest_object_with_behavior(bhvCelebrationStar)) {
			vec3f_copy(&o->oPosVec, &cur_obj_nearest_object_with_behavior(bhvCelebrationStar)->oPosVec);
		}
		cur_obj_hide();

		if (gMarioState->action & ACT_FLAG_IDLE) {
			mark_silver_star_as_collected();
		}
	} else {
		cur_obj_become_intangible();
		vec3f_copy(&o->oPosVec, &gMarioObject->oPosVec);
		o->oPosY += 250.0f;
		o->oFaceAngleYaw += 0x1000;

		cur_obj_update_floor_and_walls();

		if (o->oTimer == 30) {
			mark_silver_star_as_collected();
		}
	}
}

void bhv_bowser_course_red_coin_star_loop(void) {
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;

    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter == 8) {
                o->oAction = 1;
            }
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_no_exit_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}
