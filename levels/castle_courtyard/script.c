#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/castle_courtyard/header.h"

static const LevelScript script_func_local_1[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/     0, 200, -1652, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvAmbientSounds),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -2700,   0, -1652, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBirdsSoundLoop),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  2700,   0, -1652, /*angle*/ 0, 0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvBirdsSoundLoop),
    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    OBJECT(/*model*/ MODEL_BOO, /*pos*/ -3217, 100,  -101, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvCourtyardBooTriplet),
    OBJECT(/*model*/ MODEL_BOO, /*pos*/  3317, 100, -1701, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvCourtyardBooTriplet),
    OBJECT(/*model*/ MODEL_BOO, /*pos*/   -71,   1, -1387, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvCourtyardBooTriplet),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ -870, 102, -3052, /*angle*/ 0, 29.9982, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ 709, 102, -2747, /*angle*/ 0, -180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ -2047, -102, -717, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ 2048, -102, -2559, /*angle*/ 0, -45, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ 1843, -102, -717, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ -2635, -102, -2961, /*angle*/ 0, -45, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ 1296, 102, -1737, /*angle*/ 0, -34.9970, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
	OBJECT(/*model*/ MODEL_BOO, /*pos*/ -961, 102, -1094, /*angle*/ 0, 59.9963, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoinBoo),
    RETURN(),
};

const LevelScript level_castle_courtyard_entry[] = {
    INIT_LEVEL(),
    LOAD_YAY0(        /*seg*/ 0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd),
    LOAD_YAY0(        /*seg*/ 0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd),
    LOAD_YAY0_TEXTURE(/*seg*/ 0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd),
    LOAD_YAY0(        /*seg*/ 0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0C, _group9_geoSegmentRomStart,  _group9_geoSegmentRomEnd),
    LOAD_YAY0(        /*seg*/ 0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_10),
    LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE,  spiky_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_WOODEN_DOOR, wooden_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,     castle_courtyard_geo_000200),

    AREA(/*index*/ 1, castle_courtyard_geo_000218),
        OBJECT(/*model*/ MODEL_BOO,  /*pos*/ -2360, -100, -2712, /*angle*/ 0,   0, 0, /*behParam*/ 0x01050000, /*beh*/ bhvBooWithCage),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/     0,   51, -1000, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvLaunchStarCollectWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/     0,   51, -1000, /*angle*/ 0, 180, 0, /*behParam*/ 0x000B0000, /*beh*/ bhvLaunchDeathWarp),
		OBJECT(/*model*/ MODEL_NONE, /*pos*/     3327, 100, -2864, /*angle*/ 0, 180, 0, /*behParam*/ 0x00140000, /*beh*/ bhvLaunchStarCollectWarp),
		OBJECT(/*model*/ MODEL_NONE, /*pos*/     3327, 100, -2864, /*angle*/ 0, 180, 0, /*behParam*/ 0x001E0000, /*beh*/ bhvLaunchDeathWarp),
		OBJECT(/*model*/ MODEL_NONE, /*pos*/ 3327, -205, -2764, /*angle*/ 0, 0, 0, /*behParam*/ 0x16020000, /*beh*/ bhvWarp),
		OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, 200, -3276, /*angle*/ 0, 0, 0, /*behParam*/ 0x06000000, /*beh*/ bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_YELLOW_COIN, 3225, 102, 358, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3071, 102, 512, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3378, 102, 205, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3071, 102, 512, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3225, 102, 358, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3378, 102, 205, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_BREAKABLE_BOX, 3327, 0, -2764, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 3277, 0, -2564, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 3477, 0, -2564, 0, 0, 0, 0x00010000, bhvBreakableBox),
		WARP_NODE(/*id*/ 0x02, /*destLevel*/ LEVEL_TSOBF, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x05, /*destLevel*/ LEVEL_BBH, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*flags*/ WARP_NO_CHECKPOINT),
		WARP_NODE(/*id*/ 0x14, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 0x01, /*destNode*/ 0x14, /*flags*/ WARP_NO_CHECKPOINT),
		WARP_NODE(/*id*/ 0x1E, /*destLevel*/ LEVEL_CASTLE_COURTYARD, /*destArea*/ 0x01, /*destNode*/ 0x1E, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x01, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x02, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE_GROUNDS, /*destArea*/ 0x01, /*destNode*/ 0x03, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_func_local_1),
        JUMP_LINK(script_func_local_2),
        TERRAIN(/*terrainData*/ castle_courtyard_seg7_collision),
        MACRO_OBJECTS(/*objList*/ castle_courtyard_seg7_macro_objs),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_SOUND_PLAYER),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 0, /*pos*/ -14, 0, -201),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
