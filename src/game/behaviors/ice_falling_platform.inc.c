// ice_falling_platform.inc.c

struct IceFallingPlatformData {
    const Collision *collision;
    s16 posX;
    s16 posZ;
    s16 angle;
};

struct IceFallingPlatformData sIceFallingPlatform[] = {
    { NULL, 0, 0, 0 },
    { ccc_ice_a_collision,  0, 0, 0 },
    { ccc_ice_b_collision, 0, 0, 0x100 },
    { ccc_ice_c_collision, 0, 0, 0x100 },
};

void falling_ice_plat_act_start(void) {
    o->oBitsPlatformBowser = cur_obj_nearest_object_with_behavior(bhvChiefChilly);
    obj_set_collision_data(o, sIceFallingPlatform[o->oBehParams2ndByte].collision);

	o->oBitsPlatformTimer = 34000;

    if (o->oBitsPlatformBowser != NULL) {
        o->oAction = BOWSER_BITS_PLAT_ACT_CHECK;
    }
}

void falling_ice_plat_act_check(void) {
    //struct Object *chiefChilly = o->oBitsPlatformBowser;

    if (o->oBreakAndFall == TRUE) { // This is set in chief_chilly_jumping() in bully.inc.c
        if (!(cur_obj_has_behavior(bhvFallingIcePlatformA))) {
            o->oAction = BOWSER_BITS_PLAT_ACT_FALL;
			cur_obj_set_behavior(bhvFallingIcePlatform);
		} else if (o->oPosY > 0.0f) {
			o->oFaceAnglePitch = (0.5 * coss(o->oBitsPlatformTimer) + 0.5) * 0x800;
			if (o->oTimer == 100) {
				o->oFaceAnglePitch = 0x0;
				o->oAction = BOWSER_BITS_PLAT_ACT_FALL;
			}
			o->oBitsPlatformTimer += 2000; // displace timer to fix
		}
	} else {
		o->oTimer = 0;
	}
}

void falling_ice_plat_act_fall(void) {
    if (o->oTimer == 0 || o->oTimer == 22) {
        cur_obj_play_sound_2(SOUND_GENERAL_BOWSER_PLATFORM_FALL);
    }

    if ((o->oTimer < 22) && !(cur_obj_has_behavior(bhvFallingIcePlatformA))) {
        //set_environmental_camera_shake(SHAKE_ENV_FALLING_BITS_PLAT);
        o->oVelY = -6.0f;
        o->oGravity = 0.0f;
    } else {
		if (cur_obj_has_behavior(bhvFallingIcePlatformA)) {
			o->oGravity = -4.0f;
		} else {
			o->oGravity = -0.5f;
		}
    }

	if ((o->oPosY <= 0.0f) && (cur_obj_has_behavior(bhvFallingIcePlatformA))) {
		o->oBreakAndFall = FALSE;
		o->oVelY = 0.0f;
		o->oGravity = 0.0f;
		o->oAction = BOWSER_BITS_PLAT_ACT_CHECK;
	}

    if (!(o->oTimer & 1) && o->oTimer >= 22) {
        s16 angle = sIceFallingPlatform[o->oBehParams2ndByte].angle
                    + (gDebugInfo[DEBUG_PAGE_EFFECTINFO][1] << 8);
		o->oFaceAnglePitch += angle;
    }

    cur_obj_move_using_fvel_and_gravity();

    if (o->oTimer > 300) {
        obj_mark_for_deletion(o);
    }
}

ObjActionFunc sFallingIcePlatformActions[] = {
    falling_ice_plat_act_start,
    falling_ice_plat_act_check,
    falling_ice_plat_act_fall,
};

void bhv_falling_ice_platform_loop(void) {
    cur_obj_call_action_function(sFallingIcePlatformActions);
}
