#include "src/game/envfx_snow.h"

const GeoLayout bbb_path_controlled_lift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbb_path_controlled_lift_world_root_node_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbb_path_controlled_lift_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
