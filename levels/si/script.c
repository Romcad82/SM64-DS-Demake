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
#include "levels/si/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_si_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _si_segment_7SegmentRomStart, _si_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, si_area_1),
		WARP_NODE(0x0A, LEVEL_SI, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x04, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x04, 0x1E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, 1300, 550, -3500, 0, 0, 0, 0x00030000, bhvExclamationBox),
		OBJECT(MODEL_1UP, 3480, 1100, -280, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_GOOMBA, -100, 845, -2000, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -2900, 410, -2600, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -849, 582, -1370, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_KLEPTO, 1100, 300, 1200, 0, 0, 0, 0x00020000, bhvKlepto),
		OBJECT(MODEL_ENEMY_LAKITU, -1900, 600, -3700, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, 400, 600, 2100, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_PIRANHA_PLANT, 169, 360, -1153, 0, 45, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_NONE, -827, 1114, -2169, 0, 0, 0, 0x00540000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -2460, 410, -2830, 0, 0, 0, 0x00470000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 240, 100, 3420, 0, 0, 0, 0x00490000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 3563, 100, 617, 0, 0, 0, 0x00610000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 3480, 100, -280, 0, 0, 0, 0x00550000, bhvPoleGrabbing),
		OBJECT(MODEL_SILVER_STAR, -850, 100, -2300, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_NONE, 0, -250, 0, 0, 0, 0, 0x00000001, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -2700, 400, 2100, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -2460, 1350, -2830, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -626, 1200, -1952, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_STAR_CRYSTAL, 3541, 350, 201, 0, 0, 0, 0x00000000, bhvSilversHiddenStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, 3300, 100, 500, 0, -30, 0, 0x00AA0000, bhvMessagePanel),
		OBJECT(MODEL_YELLOW_COIN, 3629, 115, 25, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2294, 210, -3357, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1200, 100, -2600, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1000, 100, -2700, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -800, 100, -2800, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3636, 115, 384, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3429, 115, 368, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3435, 115, 42, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3734, 115, 219, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 3342, 115, 213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 3200, 100, 800, 0, -130, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 155, 0),
		TERRAIN(si_area_1_collision),
		MACRO_OBJECTS(si_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SI),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 155, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
