#include "src/game/envfx_snow.h"

const GeoLayout ccc_ice_c_geo[] = {
	GEO_CULLING_RADIUS(2300),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccc_ice_c_world_root_node_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccc_ice_c_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
