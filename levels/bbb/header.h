#ifndef BBB_HEADER_H
#define BBB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_bbb_entry[];

// geo
extern const GeoLayout geo_bbb_0005E0[];
extern const GeoLayout geo_bbb_0005F8[];

// leveldata
extern const Gfx bbb_seg7_dl_0701F7E8[];
extern const Gfx bbb_seg7_dl_0701FAB0[];
extern const Collision bbb_seg7_collision_07026B1C[];

#include "levels/bbb/header.inc.h"

#include "levels/bbb/bbb_path_controlled_lift/collision_header.h"

#include "levels/bbb/bbb_path_controlled_lift/geo_header.h"

#include "levels/bbb/bbb_merry_go_round/collision_header.h"

#include "levels/bbb/bbb_merry_go_round/geo_header.h"

#include "levels/bbb/bbb_trap_door/collision_header.h"

#include "levels/bbb/bbb_trap_door/geo_header.h"

#endif
