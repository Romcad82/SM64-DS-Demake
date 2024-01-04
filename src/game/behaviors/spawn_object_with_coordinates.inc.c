/*
Behavior Paramater 1: (What Object To Spawn)
	0: Bob-Omb
	
Behavior Paramater 2: (X Coordinates)
	0: TSOBF Bob-Omb 1
	1: TSOBF Bob-Omb 2

Behavior Paramater 3: (Y Coordinates)
	0: TSOBF Bob-Omb 1
	1: TSOBF Bob-Omb 2
	2: TSOBF Bob-Omb 3 (Different Angle than TSOBF Bob-Omb 2)

Behavior Paramater 4: (Z Coordinates)
	0: TSOBF Bob-Omb 1
	1: TSOBF Bob-Omb 2
*/

void bhv_collide_check_loop(void) {
	if (obj_check_if_collided_with_object(o, gMarioObject) && (o->oAction == 0)) {
		spawn_object_with_coordinates();
		o->oAction++;
	}
}

void spawn_object_with_coordinates(void) {
	struct Object *spawnedObj = NULL;

	if (GET_BPARAM1(o->oBehParams) == 0x00) { // Spawn Bob-Omb
		spawnedObj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvLitBobomb);
	}

	// X
	if (o->oBehParams2ndByte == 0x00) {
		spawnedObj->oPosX = -1300.0f;
	} else if (o->oBehParams2ndByte == 0x01) {
		spawnedObj->oPosX = 1400.0f;
	} else if (o->oBehParams2ndByte == 0x02) {
		spawnedObj->oPosX = -1750.0f;
	}

	// Y
	if (GET_BPARAM3(o->oBehParams) == 0x00) {
		SET_BPARAM4(spawnedObj->oBehParams, 0x01); // spawnedObj->oPosY = 1700.0f;
	} else if (GET_BPARAM3(o->oBehParams) == 0x01) {
		SET_BPARAM4(spawnedObj->oBehParams, 0x02); // spawnedObj->oPosY = 1500.0f;
	} else if (GET_BPARAM3(o->oBehParams) == 0x02) {
		SET_BPARAM4(spawnedObj->oBehParams, 0x03); // spawnedObj->oPosY = 1500.0f;
	}

	// Z
	if (GET_BPARAM4(o->oBehParams) == 0x00) {
		spawnedObj->oPosZ = -1300.0f;
	} else if (GET_BPARAM4(o->oBehParams) == 0x01) {
		spawnedObj->oPosZ = -1750.0f;
	} else if (GET_BPARAM4(o->oBehParams) == 0x02) {
		spawnedObj->oPosZ = 1600.0f;
	}
}
