/*
Behavior Paramater 1: (For Power Stars)

Behavior Paramater 2: (What Object To Spawn)
	0: Silver Star
	1: 1-Up Mushroom
	2: Super Mushroom
	3: Power Star

Behavior Paramater 3: (What Object To Follow)
	0: Breakable Box
	1: Goomba
	2: King Boo
	3: Goomba Boss

Behavior Paramater 4: (Copy Position or Not)
	0: Copy
	1: Don't Copy
*/

void bhv_spawn_object_from_another_init(void) {
	if (GET_BPARAM3(o->oBehParams) == 0x00) {			// Set Breakable Box As Parent
		o->parentObj = cur_obj_nearest_object_with_behavior(bhvBreakableBox);
	} else if (GET_BPARAM3(o->oBehParams) == 0x01) {	// Set Goomba As Parent
		o->parentObj = cur_obj_nearest_object_with_behavior(bhvGoomba);
	} else if (GET_BPARAM3(o->oBehParams) == 0x02) {	// Set King Boo As Parent
		o->parentObj = cur_obj_nearest_object_with_behavior(bhvKingBoo);
	} else if (GET_BPARAM3(o->oBehParams) == 0x03) {	// Set Goomba Boss Handler As Parent
		o->parentObj = cur_obj_nearest_object_with_behavior(bhvGoombaBossHandler);
	}
}

void bhv_follow_object_loop(void) {
	if (o->oBehParams2ndByte == 0x00) {	// Special Functionality for Silver Star
		if (GET_BPARAM3(o->oBehParams) == 0x00) {			// Breakable Box
			if ((o->oTimer % 2) == 0) {
				struct Object *sparkleObj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
				obj_translate_xyz_random(sparkleObj, 240.0f);
				sparkleObj->oPosY += 50.0f;
			}
		} else if (GET_BPARAM3(o->oBehParams) == 0x01) {	// Goomba
			if ((o->oTimer % 4) == 0) {
				struct Object *sparkleObj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
				sparkleObj->oPosY += 10.0f;
			}
		}
	}

	if (GET_BPARAM3(o->oBehParams) == 0x00) {			// Follow Breakable Box
		if (cur_obj_nearest_object_with_behavior(bhvBreakableBox) != o->parentObj) {
			spawn_object_from_another();
		}
	} else if (GET_BPARAM3(o->oBehParams) == 0x01) {	// Follow Goomba
		if (cur_obj_nearest_object_with_behavior(bhvGoomba) != o->parentObj) {
			spawn_object_from_another();
		}
	} else if (GET_BPARAM3(o->oBehParams) == 0x02) {	// Follow King Boo
		if (cur_obj_nearest_object_with_behavior(bhvKingBoo) != o->parentObj) {
			spawn_object_from_another();
		}
	} else if (GET_BPARAM3(o->oBehParams) == 0x03) {	// Follow Goomba Boss Handler
		if (cur_obj_nearest_object_with_behavior(bhvGoombaBossHandler) != o->parentObj) {
			spawn_object_from_another();
		}
	}

	if (GET_BPARAM4(o->oBehParams) == 0x00) { // Copy Followed Object's Position
		vec3f_copy(&o->oPosVec, &o->parentObj->oPosVec);
	}
	else if (GET_BPARAM4(o->oBehParams) == 0x02) {
		if (cur_obj_nearest_object_with_behavior(bhvGoombaBoss)) {
			vec3f_copy(&o->oPosVec, &cur_obj_nearest_object_with_behavior(bhvGoombaBoss)->oPosVec);
		}
	}
}

void spawn_object_from_another(void) {
	if (o->oBehParams2ndByte == 0x00) {			// Spawn Silver Star
		struct Object *silverStar = spawn_object(o, MODEL_SILVER_STAR, bhvSilverStar);
		silverStar->oBehParams2ndByte = 0x01;
		silverStar->oPosY += 100.0f;

		obj_mark_for_deletion(o);
	} else if (o->oBehParams2ndByte == 0x01) {	// Spawn 1-Up Mushroom
		spawn_object(o, MODEL_1UP, bhvHidden1up);

		obj_mark_for_deletion(o);
	} else if (o->oBehParams2ndByte == 0x02) {	// Spawn Super Mushroom
		struct Object *superMushroom = spawn_object(o, MODEL_SUPER, bhv1upWalking);
		SET_BPARAM3(superMushroom->oBehParams, 0x01);

		obj_mark_for_deletion(o);
	} else if (o->oBehParams2ndByte == 0x03) {	// Spawn Power Star
		if (o->oTimer == 1) { // Wait 1 frame to let object collisions update because certain objects like breakable boxes causes weird shadows if they don't update in time
			if (cur_obj_nearest_object_with_behavior(bhvStarReference)) {	// If there is a reference object to spawn the star in a certain position
				struct Object *starReference = cur_obj_nearest_object_with_behavior(bhvStarReference);
				spawn_default_star(starReference->oPosX, starReference->oPosY, starReference->oPosZ);
				obj_mark_for_deletion(starReference);
			} else {														// Else spawn star at object at original position
				spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
			}

			obj_mark_for_deletion(o);
		} else {
			o->oTimer = 0;
		}
	}
}
