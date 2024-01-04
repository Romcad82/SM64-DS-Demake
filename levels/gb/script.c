#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/gb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_gb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _gb_segment_7SegmentRomStart, _gb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _gb_custom_skybox_mio0SegmentRomStart, _gb_custom_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	LOAD_RAW(0xc, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_MIO0(0x6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0xd, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_GB_TILTING_SQUARE_PLATFORM, gb_geo_000BF8), 
	LOAD_MODEL_FROM_GEO(MODEL_GB_PATH_CONTROLLED_LIFT, gb_path_controlled_lift_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GB_PATH_CONTROLLED_LIFT_90, gb_path_controlled_lift_90_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GB_UP_DOWN_LOG, gb_up_down_log_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, gb_area_1),
		WARP_NODE(0x0A, LEVEL_GB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x04, 0x28, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x04, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_GB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_GB, 0x01, 0x14, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -250, 4250, -1450, 0, 0, 0, 0x000F0000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 4400, 4400, -200, 0, 0, 0, 0x00020000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 2100, 5200, 2500, 0, 0, 0, 0x00020000, bhvExclamationBox),
		OBJECT(MODEL_1UP, 3700, 3950, 3250, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_1UP, -3700, 6250, -5700, 0, 0, 0, 0x00010000, bhvHidden1upInPole),
		OBJECT(MODEL_NONE, -3700, 6350, -5700, 0, 0, 0, 0x00000000, bhvHidden1upInPoleTrigger),
		OBJECT(MODEL_1UP, -2100, 4000, -4900, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_1UP, -3200, 4350, -600, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BOBOMB_BUDDY, 2150, 4050, 1750, 0, -130, 0, 0x00AB0000, bhvBobombBuddy),
		OBJECT(MODEL_BREAKABLE_BOX, -1500, 4000, -900, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1100, 4000, -5100, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -500, 4000, -5700, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -2100, 4000, -2100, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1300, 4000, 300, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -7350, 4100, -3200, 0, 0, 0, 0x00040000, bhvBreakableBox),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT, -5790, 4000, -3600, 0, -180, 0, 0x00100000, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT_90, -2000, 4000, -1200, 0, -180, 0, 0x00100000, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT_90, -2000, 4000, 0, 0, -180, 0, 0x00100000, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT_90, -2000, 4000, -2400, 0, -180, 0, 0x00100000, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT, -1200, 4000, -600, 0, -180, 0, 0x00100100, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT, -1200, 4000, 600, 0, -180, 0, 0x00100100, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT, -1200, 4000, -1800, 0, -180, 0, 0x00100100, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_PATH_CONTROLLED_LIFT, -5790, 4000, -3200, 0, -180, 0, 0x00100100, bhvSlidingPlatform3),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 800, 4050, -6450, 0, 0, 0, 0x00F00000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 2800, 4275, 1676, 0, 0, 0, 0x00F80000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 3453, 5535, 1947, 0, 0, 0, 0x00F88000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, -4500, 3825, 185, 0, 0, 0, 0x006E0000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, -4500, 3825, -900, 0, 0, 0, 0x006E4000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, -4500, 3825, -2000, 0, 0, 0, 0x006E8000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 1723, 4200, -2900, 0, 0, 0, 0x00A00000, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 2647, 4200, -2900, 0, 0, 0, 0x00A02B00, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 3571, 4200, -2900, 0, 0, 0, 0x00A05500, bhvGbUpDownLog),
		OBJECT(MODEL_GB_UP_DOWN_LOG, 4495, 4200, -2900, 0, 0, 0, 0x00A08000, bhvGbUpDownLog),
		OBJECT(MODEL_GOOMBA, -1750, 4000, -2050, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2000, 4000, 300, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -4500, 4000, -3000, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -300, 4000, -800, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1400, 4600, 6000, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -4500, 4000, 1200, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1700, 4000, 1400, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -7600, 4100, -2950, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -4500, 4000, 3250, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1600, 4600, 6250, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1600, 4100, 2700, 0, -70, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1100, 4000, -1500, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1250, 4000, -1450, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -3700, 4000, -3750, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2700, 4000, 2200, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -550, 7126, -5450, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 850, 7298, -5500, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1850, 6495, -5550, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 450, 4000, 2750, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2300, 4000, -3450, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 300, 4000, -3900, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -500, 4000, -4000, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 200, 4000, -4800, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1400, 4000, -5800, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2800, 4000, 1050, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1050, 4000, -100, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2000, 4000, -900, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1150, 4000, -300, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1850, 4100, 3300, 0, -70, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1150, 4000, -2850, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_ENEMY_LAKITU, -3400, 4400, -5700, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -3000, 3700, 3200, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, 1850, 3700, -200, 0, 45, 0, 0x00010000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, 2700, 3700, -200, 0, 45, 0, 0x00010000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, 3550, 3700, -200, 0, 45, 0, 0x00010000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, 400, 3800, -800, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -4500, 3700, 2000, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -1300, 4300, 4000, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -700, 4300, 4700, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -1300, 4300, 5400, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_GB_TILTING_SQUARE_PLATFORM, -1950, 4300, 4700, 0, 0, 0, 0x00000000, bhvGbTiltingInvertedPyramid),
		OBJECT(MODEL_PIRANHA_PLANT, -3700, 4000, -4700, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -100, 4000, -2900, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -1300, 4600, 3300, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -3200, 4000, -100, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 5415, 4800, -2900, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 2450, 7200, -5525, 0, -90, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_NONE, -3700, 4200, -5700, 0, 0, 0, 0x00C80000, bhvPoleGrabbing),
		OBJECT(MODEL_HEART, 2900, 4700, 6100, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_HEART, 3150, 7400, -4800, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_RED_COIN, -7350, 4100, -3200, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2200, 5000, 2700, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3200, 4200, -1550, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 800, 5500, -6450, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2800, 7250, 2600, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 400, 4450, -800, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5750, 5050, -2900, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5100, 6300, -7100, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 800, 4350, -2900, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR_CRYSTAL, 4250, 7450, 6100, 0, 0, 0, 0x01000000, bhvHiddenSwitchStar),
		OBJECT(MODEL_STAR_SWITCH, 300, 4600, 6700, 0, 180, 0, 0x00000000, bhvStarSwitch),
		OBJECT(MODEL_NONE, -1500, 4000, -900, 0, 0, 0, 0x00020000, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, 3950, 6861, -5450, 0, 0, 0, 0x15010000, bhvWarp),
		OBJECT(MODEL_NONE, 4150, 7250, -5450, 0, 90, 0, 0x00140000, bhvLaunchDeathWarp),
		OBJECT(MODEL_WOODEN_POST, 400, 4200, 1200, 0, 0, 0, 0x00050000, bhvWoodenPost),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4525, 4150, -475, 0, -23, 0, 0x003F0000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 100, 4600, 6450, 0, 180, 0, 0x00AC0000, bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 2800, 4600, 5900, 0, -90, 0, 0x00AD0000, bhvMessagePanel),
		OBJECT(MODEL_YELLOW_COIN, -3200, 4200, -2050, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3200, 4200, -1800, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3200, 4200, -1300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3200, 4200, -1050, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -3800, 6700, 7500, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 3800, 0),
		TERRAIN(gb_area_1_collision),
		MACRO_OBJECTS(gb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, gb_area_2),
		WARP_NODE(0x0A, LEVEL_GB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x04, 0x28, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_GB, 0x01, 0x14, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 300, 0, 0, 0, 0, 0x00000000, bhvGoombaBossHandler),
		OBJECT(MODEL_GOOMBA, 517, 300, 1247, 0, -68, 0, 0x00010000, bhvGoombaBoss),
		OBJECT(MODEL_NONE, 517, 300, 1247, 0, -68, 0, 0x02030302, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, 0, 1000, 1350, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(gb_area_2_collision),
		MACRO_OBJECTS(gb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_BOSS_INTRO),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 3800, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
