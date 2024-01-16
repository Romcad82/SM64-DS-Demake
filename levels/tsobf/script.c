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

#include "actors/common0.h"
#include "actors/common1.h"
#include "actors/group1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/tsobf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_tsobf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _tsobf_segment_7SegmentRomStart, _tsobf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0xc, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, tsobf_area_1),
		WARP_NODE(0x0A, LEVEL_TSOBF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x01, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_COURTYARD, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, -1050, 250, 1000, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BREAKABLE_BOX, 1800, 0, -1750, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -2900, 400, 2700, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1050, 0, 100, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1050, 0, -100, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -2700, 400, 2900, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -2700, 400, 2700, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 100, 0, -1050, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -100, 0, -1050, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -300, 0, -1050, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1100, 400, -2500, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1700, 0, -300, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1500, 0, -300, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1700, 0, 1400, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1700, 0, -100, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1700, 0, 1600, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 250, 0, 1500, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 450, 0, 1500, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1600, 0, -1750, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 2900, 400, 2900, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 2700, 400, 2900, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -2900, 400, 2900, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1050, 0, -300, 0, 0, 0, 0x00010000, bhvBreakableBox),
		OBJECT(MODEL_CHUCKYA, -400, 1300, -400, 0, -135, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_GOOMBA, -1750, 0, -150, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -750, 400, -2050, 0, 135, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 2850, 400, 1950, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -100, 0, 1500, 0, 45, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 0, 0, -1800, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1000, 400, -1050, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2800, 400, 2050, 0, -45, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1050, 400, 1000, 0, 90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 0, 0, -50, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 2850, 400, -1550, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1950, 400, 2800, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1850, 400, -850, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_HEAVE_HO, 2800, 400, 450, 0, -180, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -1500, 800, -1500, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 200, 400, 2800, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_NONE, 2700, 400, 2900, 0, 0, 0, 0x00010000, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, -2850, 0, 1000, 0, 90, 0, 0x00050000, bhvThiBowlingBallSpawner),
		OBJECT(MODEL_NONE, 1000, 0, 2850, 0, 180, 0, 0x00060000, bhvThiBowlingBallSpawner),
		OBJECT(MODEL_NONE, 400, 0, 400, 0, 0, 0, 0x00960000, bhvPoleGrabbing),
		OBJECT(MODEL_SILVER_STAR, 600, 1555, 600, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000001, bhvSilverStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000001, bhvSilverStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000001, bhvSilverStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000001, bhvSilverStar),
		OBJECT(MODEL_NONE, 2850, 400, 1950, 0, 0, 0, 0x00000100, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, 1800, 0, -1750, 0, 0, 0, 0x00000000, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, -2900, 400, 2900, 0, 0, 0, 0x00000000, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, 0, 0, -50, 0, 0, 0, 0x00000100, bhvSpawnObjectFromAnother),
		OBJECT(MODEL_NONE, -1700, 1300, -1700, 0, 0, 0, 0x00000000, bhvSpawnObjectWithCoordinates),
		OBJECT(MODEL_NONE, 500, 0, -1700, 0, 0, 0, 0x00010101, bhvSpawnObjectWithCoordinates),
		OBJECT(MODEL_NONE, -1750, 0, 550, 0, 0, 0, 0x00020202, bhvSpawnObjectWithCoordinates),
		OBJECT(MODEL_STAR_CRYSTAL, -2800, 1500, -2800, 0, 0, 0, 0x00000000, bhvSilversHiddenStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, -2800, 1300, -2600, 0, 45, 0, 0x00AA0000, bhvMessagePanel),
		OBJECT(MODEL_YELLOW_COIN, -450, 1125, -450, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -300, 1125, -300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -150, 1125, -150, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 0, 1125, 0, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 150, 1125, 150, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -150, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1900, 250, 1000, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1750, 250, 1000, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1600, 250, 1000, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 50, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 250, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1000, 250, -1900, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1000, 250, -1750, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1000, 250, -1600, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1950, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1750, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1550, 200, 2300, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, -1950, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, -1750, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, -1550, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, -150, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, 50, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2250, 200, 250, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -2400, 2500, -1700, 0, 45, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 0, 0),
		TERRAIN(tsobf_area_1_collision),
		MACRO_OBJECTS(tsobf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
		TERRAIN_TYPE(TERRAIN_GRASS),
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
