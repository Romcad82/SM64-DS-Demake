void scroll_si_dl_Ignore_Collision_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 10.0;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(si_dl_Ignore_Collision_mesh_layer_5_vtx_1);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_si() {
	scroll_si_dl_Ignore_Collision_mesh_layer_5_vtx_1();
}
