
/**
 * Behavior for bhvMerryGoRound.
 * This is the merry-go-round in BBB.
 */

/**
 * This function handles the merry-go-round's music.
 * It starts the music when Mario enters the room around the
 * merry-go-round's enclosure, and ends the music when he's neither
 * in the enclosure nor in the room around it.
 */
static void handle_bbb_merry_go_round_music(void) {
	// Get Mario's floor and floor surface type
    struct Surface *marioFloor = gMarioState->floor;
    u16 marioFloorType;

    if (marioFloor == NULL) {
		marioFloorType = SURFACE_DEFAULT;
    } else {
		marioFloorType = marioFloor->type;
    }

	// There's a sign in first room. This is so if you stand on it, the music still plays.
	s32 onSign = FALSE;
	if ((gMarioCurrentRoom == 0) && (mario_is_within_rectangle(-100.0f, 100.0f, 200.0f, 400.0f))) {
		onSign = TRUE;
	}

    // If the music should play, play it and check whether it still should.
    // Otherwise, don't play it and check whether it should.
    if (o->oMerryGoRoundMusicShouldPlay == FALSE) {
        if ((marioFloorType == SURFACE_MGR_MUSIC) || (marioFloorType == SURFACE_0008) || (marioFloorType == SURFACE_0006) || onSign) {
            // Play the merry-go-round and BBH music at the same time
            play_secondary_music(SEQ_EVENT_MERRY_GO_ROUND, 45, 20, 200);
            // Set to TRUE
            o->oMerryGoRoundMusicShouldPlay++;
        }
    } else {
        // All floors in the merry-go-round's enclosure have surface type 0x1A.
        // The cur_obj_is_mario_on_platform check is redundant since the merry-go-round
        // has surface type 0x1A, so Mario cannot be on the merry-go-round
        // without being on a floor with surface type 0x1A (SURFACE_MGR_MUSIC).
        if (cur_obj_is_mario_on_platform() || marioFloorType == SURFACE_MGR_MUSIC || onSign) {
            // If Mario is in the merry-go-round's enclosure, play only the merry-go-round music.
            play_secondary_music(SEQ_EVENT_MERRY_GO_ROUND, 0, 78, 50);
            gMarioOnMerryGoRound = TRUE;
        } else {
            // If Mario is not in the merry-go-round's enclosure,
            // i.e. he's around it, play both the merry-go-round music and the BBH music.
            play_secondary_music(SEQ_EVENT_MERRY_GO_ROUND, 45, 20, 200);
            gMarioOnMerryGoRound = FALSE;
        }

        // If Mario is not in the merry-go-round's area of the basement anymore,
        // stop playing the music.
        // If he is, play the creaking sound.
        if (
            // The merry-go-round is a dynamic surface.
			(!((marioFloorType == SURFACE_MGR_MUSIC) || (marioFloorType == SURFACE_0008) || (marioFloorType == SURFACE_0006) || onSign))) {
            func_80321080(300); //! Switch to BBH music? FIXME: Audio needs labelling
            o->oMerryGoRoundMusicShouldPlay = FALSE;
        } else {
            cur_obj_play_sound_1(SOUND_ENV_MERRY_GO_ROUND_CREAKING);
        }
    }
}

/**
 * Merry-go-round update function.
 */
void bhv_bbb_merry_go_round_loop(void) {
    // Rotate the merry-go-round and play appropriate music if it's not stopped.
    if (!o->oMerryGoRoundStopped) {
        o->oAngleVelYaw = 0x80;
        o->oMoveAngleYaw += o->oAngleVelYaw;
        o->oFaceAngleYaw += o->oAngleVelYaw;
		if (gCurrLevelNum == LEVEL_BBB) {
			handle_bbb_merry_go_round_music();
		}
    } else {
        o->oAngleVelYaw = 0;
        func_80321080(300); //! Switch to BBH music? FIXME: Audio needs labelling
    }
}
