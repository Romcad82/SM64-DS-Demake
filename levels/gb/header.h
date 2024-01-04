#ifndef GB_HEADER_H
#define GB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const LevelScript level_gb_entry[];

// geo
extern const GeoLayout gb_geo_000BF8[];

// leveldata
extern const Gfx gb_seg7_dl_0701A1F0[];
extern const Collision gb_seg7_collision_inverted_pyramid[];

#include "levels/gb/header.inc.h"

#include "levels/gb/gb_path_controlled_lift/geo_header.h"

#include "levels/gb/gb_path_controlled_lift/collision_header.h"

#include "levels/gb/gb_path_controlled_lift_90/geo_header.h"

#include "levels/gb/gb_up_down_log/collision_header.h"

#include "levels/gb/gb_up_down_log/geo_header.h"

#endif
