void scroll_gb_dl_Ignore_Collision_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 23;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(gb_dl_Ignore_Collision_mesh_layer_5_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gb_dl_Ignore_Collision_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 9;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(gb_dl_Ignore_Collision_001_mesh_layer_5_vtx_0);

	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gb() {
	scroll_gb_dl_Ignore_Collision_mesh_layer_5_vtx_0();
	scroll_gb_dl_Ignore_Collision_001_mesh_layer_5_vtx_0();
};
