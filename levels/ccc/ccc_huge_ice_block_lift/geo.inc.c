#include "src/game/envfx_snow.h"

const GeoLayout ccc_huge_ice_block_lift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccc_huge_ice_block_lift_world_root_node_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccc_huge_ice_block_lift_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
