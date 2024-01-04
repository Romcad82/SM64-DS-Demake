void bhv_squish_mario_loop(void) {
	vec3f_copy(&o->oPosVec, &o->parentObj->oPosVec);
	o->oPosY -= 200.0f;
}
