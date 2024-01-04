#include "src/game/envfx_snow.h"

const GeoLayout gb_up_down_log_geo[] = {
	GEO_CULLING_RADIUS(2300),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gb_up_down_log_world_root_node_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gb_up_down_log_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
