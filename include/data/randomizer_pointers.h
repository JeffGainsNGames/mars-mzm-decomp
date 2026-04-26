#ifndef RANDOMIZER_POINTERS_H
#define RANDOMIZER_POINTERS_H

#include "types.h"
#include "structs/room.h"

extern const struct TilesetEntry* sTilesetEntries_Pointer;
extern const u8 (*sAnimatedTilesetEntries_Pointer)[3*16];
extern const struct CreditsEntry* sCredits_Pointer;

#endif /* RANDOMIZER_POINTERS_H */
