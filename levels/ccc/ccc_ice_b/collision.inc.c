const Collision ccc_ice_b_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-957, -250, 367),
	COL_VERTEX(957, -250, 367),
	COL_VERTEX(-957, 200, 367),
	COL_VERTEX(957, 200, 367),
	COL_VERTEX(-957, 250, 367),
	COL_VERTEX(957, 250, 367),
	COL_VERTEX(652, 250, -367),
	COL_VERTEX(652, 200, -367),
	COL_VERTEX(-652, 250, -367),
	COL_VERTEX(-652, 200, -367),
	COL_VERTEX(-652, -250, -367),
	COL_VERTEX(652, -250, -367),
	COL_TRI_INIT(SURFACE_HARD_VERY_SLIPPERY, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 2, 1),
	COL_TRI(2, 3, 4),
	COL_TRI(5, 4, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(7, 6, 5),
	COL_TRI(8, 9, 2),
	COL_TRI(10, 2, 9),
	COL_TRI(2, 10, 0),
	COL_TRI(10, 11, 0),
	COL_TRI(1, 0, 11),
	COL_TRI(5, 3, 7),
	COL_TRI(11, 7, 3),
	COL_TRI(10, 9, 11),
	COL_TRI(7, 11, 9),
	COL_TRI(9, 8, 7),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 4),
	COL_TRI(2, 4, 8),
	COL_TRI(1, 11, 3),
	COL_TRI_STOP(),
	COL_END()
};
