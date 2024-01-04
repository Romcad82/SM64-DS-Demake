
/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

	if (o->oBehParams2ndByte != 0x01) {
		obj_set_hitbox(o, &sRedCoinHitbox);
	}
    // Original: obj_set_hitbox(o, &sRedCoinHitbox);

}

void dropped_coin(void) {
	cur_obj_update_floor_and_walls();
	cur_obj_if_hit_wall_bounce_away();

	if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
		cur_obj_play_sound_2(SOUND_GENERAL_COIN_DROP);
	}

	if (o->oTimer > 90 || o->oMoveFlags & OBJ_MOVE_LANDED) {
		obj_set_hitbox(o, &sRedCoinHitbox);
		cur_obj_become_tangible();
	}

	cur_obj_move_standard(-30);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != 8) {
                spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
            }

            // On all versions but the JP version, each coin collected plays a higher noise.
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                       + (((u8) o->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                       gGlobalSoundSource);
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    }

	if (o->oBehParams2ndByte == 0x01) {
		dropped_coin();
	}
}
