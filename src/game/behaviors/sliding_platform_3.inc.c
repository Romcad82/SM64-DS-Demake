// sliding_platform_3.inc.c

static Collision const *sSlidingPlatforms3CollisionData[] = {
	gb_path_controlled_lift_collision,
	ccc_huge_ice_block_lift_collision,
	NULL,
	NULL,
	NULL,
	NULL,
    NULL,
	NULL,
};

/*
BParam 1: (Type of Collision)
	0: GB Path Controlled Lift
	1: CCC Huge Ice Block Lift

BParam 2: (Distance) (50 (Units) * BParam 2)

BParam 3: (Travel Positive or Negative)
	0: Travel Positive
	1: Travel Negative

BParam 4: (Side to Side or Up & Down)
	0: Side to Side
	1: Up & Down
*/

void bhv_sliding_platform_3_init(void) {
    s32 collisionDataIndex = GET_BPARAM1(o->oBehParams) & SLIDING_PLATFORM_BP1_TYPES_MASK;

    o->collisionData = segmented_to_virtual(sSlidingPlatforms3CollisionData[collisionDataIndex]);
    o->oBackAndForthPlatformPathLength = 50.0f * GET_BPARAM2(o->oBehParams);

    if (GET_BPARAM4(o->oBehParams) == 0x00) {	// Side to Side
        o->oBackAndForthPlatformVel = 10.0f;
    } else {									// Up & Down
        o->oBackAndForthPlatformVel = 10.0f;
        if (GET_BPARAM3(o->oBehParams) == 0x00) {	// Travel Positive Y
            o->oBackAndForthPlatformDirection = -1.0f;
        } else {									// Travel Negative Y
            o->oBackAndForthPlatformDirection = 1.0f;
        }
    }

	o->oDrawingDistance = 7000.0f;
}

void bhv_sliding_platform_3_loop(void) {
	o->oBackAndForthPlatformDistance += o->oBackAndForthPlatformVel;
	if (clamp_f32(&o->oBackAndForthPlatformDistance, -o->oBackAndForthPlatformPathLength, 0.0f)) {
		o->oBackAndForthPlatformVel = -o->oBackAndForthPlatformVel;
		o->oTimer = 0;
	}

    obj_perform_position_op(POS_OP_SAVE_POSITION);

    if (o->oBackAndForthPlatformDirection != 0.0f) {
        o->oPosY = o->oHomeY + o->oBackAndForthPlatformDistance * o->oBackAndForthPlatformDirection;
    } else {
		if (GET_BPARAM3(o->oBehParams) == 0x00) {
			obj_set_dist_from_home(o->oBackAndForthPlatformDistance);		// Travel Positive X
		} else {
			obj_set_dist_from_home(-(o->oBackAndForthPlatformDistance));	// Travel Negative X
		}
    }

    obj_perform_position_op(POS_OP_COMPUTE_VELOCITY);
}

void bhv_ccc_sliding_platform_special_init(void) {
	o->oBackAndForthPlatformVel = 10.0f;
	o->oBackAndForthPlatformDirection = 1.0f;
	o->oAction = 0;
	o->oDrawingDistance = 7000.0f;
}

void bhv_ccc_sliding_platform_special_loop(void) {
	switch (o->oAction) {
	case 0:
		if (o->oPosY == (o->oHomeY + 800.0f)) {
			o->oBackAndForthPlatformDirection = -o->oBackAndForthPlatformDirection;
			o->oAction++;
		}

		break;

	case 1:
		if (o->oPosY == (o->oHomeY - 800.0f)) {
			o->oBackAndForthPlatformDirection = -o->oBackAndForthPlatformDirection;
			o->oAction++;
		}

		break;

	case 2:
		if (o->oPosY == (o->oHomeY + 800.0f)) {
			o->oBackAndForthPlatformDirection = -o->oBackAndForthPlatformDirection;
			o->oAction++;
		}

		break;

	case 3:
		if (o->oPosY == o->oHomeY) {
			o->oBackAndForthPlatformDirection = -o->oBackAndForthPlatformDirection;
			o->oAction = 0;
		}

		break;
	}

	o->oBackAndForthPlatformDistance += (o->oBackAndForthPlatformVel * o->oBackAndForthPlatformDirection);

	obj_perform_position_op(POS_OP_SAVE_POSITION);

	o->oPosY = o->oHomeY + o->oBackAndForthPlatformDistance;

	obj_perform_position_op(POS_OP_COMPUTE_VELOCITY);
}
