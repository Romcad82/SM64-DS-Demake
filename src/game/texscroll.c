#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "tile_scroll.h"
#include "texscroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/si_texscroll.inc.c"
#include "src/game/texscroll/gb_texscroll.inc.c"
#include "src/game/texscroll/ccc_texscroll.inc.c"
void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_si_segment_7SegmentRomStart)) {
		scroll_textures_si();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_gb_segment_7SegmentRomStart)) {
		scroll_textures_gb();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ccc_segment_7SegmentRomStart)) {
		scroll_textures_ccc();
	}

}
