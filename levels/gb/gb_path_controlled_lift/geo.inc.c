#include "src/game/envfx_snow.h"

const GeoLayout gb_path_controlled_lift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gb_path_controlled_lift_world_root_node_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gb_path_controlled_lift_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
