#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

#ifdef RANDOMIZER
const u8 sChozodia_57_Clipdata[] = INCBIN_U8("data_rando/rooms/chozodia_57_clipdata.rlebg");
#else // !RANDOMIZER
const u8 sChozodia_57_Clipdata[] = INCBIN_U8("data/rooms/chozodia/chozodia_57_clipdata.gfx");
#endif // RANDOMIZER

const u8 sChozodia_57_Bg2[128] = INCBIN_U8("data/rooms/chozodia/chozodia_57_bg2.gfx");

#ifdef RANDOMIZER
const u8 sChozodia_57_Bg1[] = INCBIN_U8("data_rando/rooms/chozodia_57_bg1.rlebg");
#else // !RANDOMIZER
const u8 sChozodia_57_Bg1[] = INCBIN_U8("data/rooms/chozodia/chozodia_57_bg1.gfx");
#endif // RANDOMIZER

#ifdef RANDOMIZER
const u8 sChozodia_57_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
#else // !RANDOMIZER
const u8 sChozodia_57_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
#endif // RANDOMIZER
#ifndef RANDOMIZER
	57, 6, SPRITESET_IDX(0),
#endif // !RANDOMIZER
	62, 13, SPRITESET_IDX(0),
	78, 11, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_57_Bg0[456] = INCBIN_U8("data/rooms/chozodia/chozodia_57_bg0.gfx");

