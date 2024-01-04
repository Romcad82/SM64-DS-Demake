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
#include "levels/bbb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bbb_segment_7SegmentRomStart, _bbb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x5, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd), 
	LOAD_RAW(0xc, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0xd, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBB_TUMBLING_PLATFORM, geo_bbb_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBB_TUMBLING_PLATFORM_PART, geo_bbb_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBB_TILTING_FLOOR_PLATFORM, bbb_trap_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBB_MERRY_GO_ROUND, bbb_merry_go_round_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBB_PATH_CONTROLLED_LIFT, bbb_path_controlled_lift_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbb_area_1),
		WARP_NODE(0x0A, LEVEL_BBB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x01, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BBB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_BBB, 0x01, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1E, LEVEL_BBB, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BBB, 0x01, 0x14, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 0, 0, 1755, 0, 180, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 0, 0, -1755, 0, 0, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, -1760, 0, 0, 0, 90, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 1750, 0, 0, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BBB_MERRY_GO_ROUND, 0, -18, 0, 0, 0, 0, 0x00000000, bhvBbbMerryGoRound),
		OBJECT(MODEL_BOO, 400, 80, -300, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_RED_COIN, 0, 0, -1500, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, 0, 1600, 0, 180, 0, 0x00140100, bhvCustomDoorWarp),
		OBJECT(MODEL_NONE, 0, 800, 750, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_WOODEN_SIGNPOST, 0, 0, 300, 0, 0, 0, 0x00AE0000, bhvMessagePanel),
		OBJECT(MODEL_1UP, 4800, 0, -200, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 5255, 0, 0, 0, -90, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 3500, 0, 1755, 0, 180, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 3500, 0, -1755, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 3500, -10, -748, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 4248, -10, 0, 0, -90, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 3500, -10, 748, 0, 180, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 2752, -10, 0, 0, 90, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BOO, 3700, 80, 1500, 0, 180, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_NONE, 3500, 0, 0, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_RED_COIN, 3150, 0, -400, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3500, 100, 900, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_EXCLAMATION_BOX, 3500, 250, -3500, 0, 0, 0, 0x00020000, bhvExclamationBox),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 4900, -20, -4900, 0, 90, 0, 0x3C010000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 3500, 0, -5255, 0, 0, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 1745, 0, -3500, 0, 90, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 5245, 0, -3500, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BBB_TILTING_FLOOR_PLATFORM, 3500, 0, -3500, 0, 0, 0, 0x00000000, bhvBbbTiltingTrapPlatform),
		OBJECT(MODEL_BOO, 4900, 80, -3400, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2300, 80, -3800, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_RED_COIN, 4700, 0, -3300, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4900, 700, -4900, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_YELLOW_COIN, 3800, 750, -3800, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4000, 750, -3500, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3800, 750, -3200, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3500, 750, -3000, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3200, 750, -3200, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3000, 750, -3500, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3200, 750, -3800, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3500, 750, -4000, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_1UP, 8350, 95, -2650, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 6200, -20, -3500, 0, 0, 0, 0x8C000000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 7000, -20, -2700, 0, 90, 0, 0x96000000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 7800, -20, -3500, 0, 180, 0, 0x96000000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 7000, -20, -4300, 0, -90, 0, 0x96000000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 8755, 0, -3500, 0, -90, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 7000, 0, -5255, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BOBOMB_BUDDY, 5400, 0, -4000, 0, 0, 0, 0x00AB0000, bhvBobombBuddy),
		OBJECT(MODEL_BOO, 7400, 80, -4200, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6400, 80, -3600, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 7400, 80, -3000, 0, -90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 7000, 0, -1745, 0, 180, 0, 0x00020000, bhvDoorWarp),
		OBJECT(MODEL_RED_COIN, 6150, 95, -2200, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7850, 95, -4750, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 7530, 680, -10700, 0, 0, 0, 0x31010000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 6550, 190, -9960, 0, 0, 0, 0x35010000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_PATH_CONTROLLED_LIFT, 6550, 680, -10340, 0, 90, 0, 0x62000000, bhvBbbPathControlledLift),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 7000, -10, -7073, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 7000, -10, -8520, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 7000, -10, -6349, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 7000, -10, -9244, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BOO, 7600, 50, -8200, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6500, 50, -8800, 0, -90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BBB_TUMBLING_PLATFORM, 7000, -10, -7796, 0, 0, 0, 0x00000000, bhvBbbTumblingBridge),
		OBJECT(MODEL_BREAKABLE_BOX, 7750, 0, -5600, 0, 0, 0, 0x00040000, bhvBreakableBox),
		OBJECT(MODEL_BOO, 6800, 50, -7200, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_1UP, 7000, 40, -8500, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_STAR, 7000, 280, -11650, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_RED_COIN, 7750, 10, -5597, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 6300, 150, -6100, 0, 0, 0, 0x01000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 7000, 1000, -12150, 0, 0, 0, 0x0B010000, bhvWarp),
		OBJECT(MODEL_NONE, 7000, 1155, -12150, 0, -180, 0, 0x001E0000, bhvLaunchDeathWarp),
		TERRAIN(bbb_area_1_collision),
		ROOMS(bbb_area_1_collision_rooms),
		MACRO_OBJECTS(bbb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bbb_area_2),
		WARP_NODE(0x0A, LEVEL_BBB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBB, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOO, -400, 0, 900, 0, 90, 0, 0x02000000, bhvKingBoo),
		OBJECT(MODEL_BOO, 400, 0, 900, 0, -90, 0, 0x00000000, bhvKingBooMirror),
		OBJECT(MODEL_LAKITU, 0, 0, 0, 0, -90, 0, 0x02000000, bhvCameraLakitu),
		OBJECT(MODEL_NONE, 0, 100, 0, 0, 0, 0, 0x02030201, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, -950, 400, 0, 0, 0, 0, 0x00000000, bhvStarReference),
		OBJECT(MODEL_NONE, -1500, 1700, 0, 0, 90, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(MODEL_YELLOW_COIN, -1300, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1100, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -900, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -700, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -500, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -300, 0, -1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1300, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1100, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -900, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -700, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -500, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -300, 0, 1350, 0, 0, 0, 0x00000000, bhvYellowCoin),
		TERRAIN(bbb_area_2_collision),
		ROOMS(bbb_area_2_collision_rooms),
		MACRO_OBJECTS(bbb_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
