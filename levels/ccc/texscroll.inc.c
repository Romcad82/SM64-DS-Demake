void scroll_ccc_dl_Ignore_Collision_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 13;

	static s16 rot;
	s16 rotspeed = 100;
	float scale = 2929.69;
	float radius = 22500.0;
	float offsetX = 500.0;
	float offsetY = 500.0;
	Vtx* vertices = segmented_to_virtual(ccc_dl_Ignore_Collision_mesh_layer_5_vtx_0);

	for (i = 0; i < count; i++) {
		s16 rotOffset = atan2s(vertices[i].n.ob[2], vertices[i].n.ob[0]);
		float hypotenuse = sqrtf(sqr(vertices[i].n.ob[0]) + sqr(vertices[i].n.ob[2]));

		s16 s = scale * sins(rot + rotOffset) * (hypotenuse / radius);
		s16 t = scale * coss(rot + rotOffset) * (hypotenuse / radius);

		vertices[i].n.tc[0] = s + offsetX;
		vertices[i].n.tc[1] = t + offsetY;
	}
	rot += rotspeed;
}

void scroll_ccc_dl_Ignore_Collision_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccc_dl_Ignore_Collision_mesh_layer_5_vtx_1);

	deltaX = (int)(-1.2999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccc_dl_Ignore_Collision_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 7;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccc_dl_Ignore_Collision_001_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.25 * 0x20) % width;
	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_ccc_dl_r0_node_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 127;

	static s16 rot;
	s16 rotspeed = 120;
	float scale = 6861.33;
	float radius = 22705.1;
	float offsetX = 500.0;
	float offsetY = 500.0;
	Vtx* vertices = segmented_to_virtual(ccc_dl_r0_node_001_mesh_layer_5_vtx_0);

	for (i = 0; i < count; i++) {
		s16 rotOffset = atan2s(vertices[i].n.ob[2], vertices[i].n.ob[0]);
		float hypotenuse = sqrtf(sqr(vertices[i].n.ob[0]) + sqr(vertices[i].n.ob[2]));

		s16 s = scale * sins(rot + rotOffset) * (hypotenuse / radius);
		s16 t = scale * coss(rot + rotOffset) * (hypotenuse / radius);

		vertices[i].n.tc[0] = s + offsetX;
		vertices[i].n.tc[1] = t + offsetY;
	}
	rot += rotspeed;
}

void scroll_ccc() {
	scroll_ccc_dl_Ignore_Collision_mesh_layer_5_vtx_0();
	scroll_ccc_dl_Ignore_Collision_mesh_layer_5_vtx_1();
	scroll_ccc_dl_Ignore_Collision_001_mesh_layer_5_vtx_0();
	scroll_ccc_dl_r0_node_001_mesh_layer_5_vtx_0();
};
