#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_14_Scrolls[SCROLL_DATA_SIZE(1)] = {
	43, // Room
	1, // Number of scrolls
	
	// Scroll 0
	16, 46, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

#ifdef RANDOMIZER
const u8 sNorfair_43_Clipdata[] = INCBIN_U8("data_rando/rooms/norfair_43_clipdata.rlebg");
#else // !RANDOMIZER
const u8 sNorfair_43_Clipdata[] = INCBIN_U8("data/rooms/norfair/norfair_43_clipdata.gfx");
#endif // RANDOMIZER

const u8 sNorfair_43_Bg2[1237] = INCBIN_U8("data/rooms/norfair/norfair_43_bg2.gfx");

#ifdef RANDOMIZER
const u8 sNorfair_43_Bg1[] = INCBIN_U8("data_rando/rooms/norfair_43_bg1.rlebg");
#else // !RANDOMIZER
const u8 sNorfair_43_Bg1[] = INCBIN_U8("data/rooms/norfair/norfair_43_bg1.gfx");
#endif // RANDOMIZER

#ifdef RANDOMIZER
const u8 sNorfair_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
#else // !RANDOMIZER
const u8 sNorfair_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
#endif // RANDOMIZER
	2, 23, SPRITESET_IDX(0),
#ifndef RANDOMIZER
	17, 33, SPRITESET_IDX(1),
#endif // !RANDOMIZER
	ROOM_SPRITE_DATA_TERMINATOR
};

#ifdef RANDOMIZER
const u8 sNorfair_43_Bg0[] = INCBIN_U8("data_rando/rooms/norfair_43_bg0.rlebg");
#else // !RANDOMIZER
const u8 sNorfair_43_Bg0[] = INCBIN_U8("data/rooms/norfair/norfair_43_bg0.gfx");
#endif // RANDOMIZER

