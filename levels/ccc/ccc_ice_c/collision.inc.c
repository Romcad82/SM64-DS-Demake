const Collision ccc_ice_c_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-1148, -250, 231),
	COL_VERTEX(1148, -250, 231),
	COL_VERTEX(-1148, 200, 231),
	COL_VERTEX(1148, 200, 231),
	COL_VERTEX(-1148, 250, 231),
	COL_VERTEX(1148, 250, 231),
	COL_VERTEX(957, 250, -231),
	COL_VERTEX(957, 200, -231),
	COL_VERTEX(-957, -250, -231),
	COL_VERTEX(-957, 200, -231),
	COL_VERTEX(-957, 250, -231),
	COL_VERTEX(957, -250, -231),
	COL_TRI_INIT(SURFACE_HARD_VERY_SLIPPERY, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 2, 1),
	COL_TRI(2, 3, 4),
	COL_TRI(5, 4, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(7, 6, 5),
	COL_TRI(8, 0, 9),
	COL_TRI(2, 9, 0),
	COL_TRI(9, 2, 10),
	COL_TRI(4, 10, 2),
	COL_TRI(10, 4, 6),
	COL_TRI(10, 6, 9),
	COL_TRI(7, 9, 6),
	COL_TRI(9, 7, 8),
	COL_TRI(11, 8, 7),
	COL_TRI(8, 11, 0),
	COL_TRI(1, 0, 11),
	COL_TRI(5, 3, 7),
	COL_TRI(11, 7, 3),
	COL_TRI(1, 11, 3),
	COL_TRI_STOP(),
	COL_END()
};
