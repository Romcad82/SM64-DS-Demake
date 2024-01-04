// 0x0701D510 - 0x0701D55E
const Collision ccc_seg7_collision_inverted_pyramid[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0x5),
    COL_VERTEX(0, 0, 0),
    COL_VERTEX(307, 307, 307),
    COL_VERTEX(-306, 307, 307),
    COL_VERTEX(307, 307, -306),
    COL_VERTEX(-306, 307, -306),
    COL_TRI_INIT(SURFACE_NOISE_DEFAULT, 6),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 3, 1),
    COL_TRI(1, 4, 2),
    COL_TRI(1, 3, 4),
    COL_TRI(0, 4, 3),
    COL_TRI(0, 2, 4),
    COL_TRI_STOP(),
    COL_END(),
};
