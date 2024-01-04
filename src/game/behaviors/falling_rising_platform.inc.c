// falling_rising_platform.inc.c

void bhv_squishable_platform_loop(void) {
    o->header.gfx.scale[1] = (sins(o->oBitfsPlatformTimer) + 1.0f) * 0.3f + 0.4f;
    o->oBitfsPlatformTimer += 0x80;
}

void bhv_bitfs_sinking_platform_loop(void) {
    o->oPosY -= sins(o->oBitfsPlatformTimer) * 0.58f;
    o->oBitfsPlatformTimer += 0x100;
}

// TODO: Named incorrectly. fix
void bhv_ddd_moving_pole_loop(void) {
    obj_copy_pos_and_angle(o, o->parentObj);
}

void bhv_bitfs_sinking_cage_platform_loop(void) {
    if (o->oBehParams2ndByte != 0) {
        if (o->oTimer == 0) {
            o->oPosY -= 300.0f;
        }
        o->oPosY += sins(o->oBitfsPlatformTimer) * 7.0f;
    } else {
        o->oPosY -= sins(o->oBitfsPlatformTimer) * 3.0f;
    }

    o->oBitfsPlatformTimer += 0x100;
}

/* GB Up-Down Log
// BParam2 = Height (Each Unit of Bparam2 is +5 Units to Height) (0 - 1275 Units) (Example: Bparam2 = A0 [A0 * 5.0f = 800 Units])

// BParam3 = Timing of Y Pos (0x00 - 0x80 [0x00 Lowest Y Pos] [0x80 Highest Y Pos])
*/

void bhv_gb_up_down_log_init(void) {
	o->oBitfsPlatformTimer = ((GET_BPARAM3(o->oBehParams)) * 0x100);

	o->oPosY += (GET_BPARAM3(o->oBehParams)) * ((o->oBehParams2ndByte * 5.0f) / 0x80);

	/*
	if (o->oBehParams2ndByte == 0) {
		o->oPosY += (GET_BPARAM3(o->oBehParams)) * 6.25f; // Using Bparam to fix y pos works, but is slightly inaccurate
	} else if (o->oBehParams2ndByte == 1) {
		o->oPosY += (GET_BPARAM3(o->oBehParams)) * 4.296875f;
	} else if (o->oBehParams2ndByte == 2) {
		o->oPosY += (GET_BPARAM3(o->oBehParams)) * 9.375f;
	} else if (o->oBehParams2ndByte == 3) {
		o->oPosY += (GET_BPARAM3(o->oBehParams)) * 9.6875f;
	}
	*/
}

void bhv_gb_up_down_log_loop(void) {

	o->oPosY += sins(o->oBitfsPlatformTimer) * ((o->oBehParams2ndByte * 5.0f) / 40.71246819338422f);

	/*
	if (o->oBehParams2ndByte == 0) {
		o->oPosY += sins(o->oBitfsPlatformTimer) * 19.65f;
	} else if (o->oBehParams2ndByte == 1) {
		o->oPosY += sins(o->oBitfsPlatformTimer) * 13.509375f;
	} else if (o->oBehParams2ndByte == 2) {
		o->oPosY += sins(o->oBitfsPlatformTimer) * 29.475f;
	} else if (o->oBehParams2ndByte == 3) {
		o->oPosY += sins(o->oBitfsPlatformTimer) * 30.4575f;
	}
	*/

	o->oBitfsPlatformTimer += 0x200;
}
