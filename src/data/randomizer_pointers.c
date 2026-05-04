#include "data/randomizer_pointers.h"

#include "data/animated_graphics_data.h"
#include "data/audio.h"
#include "data/cutscenes/statue_opening_data.h"
#include "data/ending_and_gallery_data.h"
#include "data/hatch_data.h"
#include "data/in_game_cutscene_data.h"
#include "data/menus/file_select_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/projectile_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/samus/samus_palette_data.h"
#include "data/sprite_data.h"
#include "data/sprites/gunship.h"
#include "data/text_data.h"

#include "structs/animated_graphics.h"
#include "structs/connection.h"

#ifdef RANDOMIZER

extern const struct RoomEntryRom* sAreaRoomEntryPointers[AREA_ENTRY_COUNT];
extern const u32* sMinimapDataPointers[AREA_COUNT];
extern const struct Door* sAreaDoorsPointers[AREA_ENTRY_COUNT];
extern const u16** sStoryTextPointers[7];

// The pointers in this file are written to 0x7D0000 (see linker.ld)

// --------------------------------
// Existing data
// --------------------------------

static const struct RoomEntryRom** sAreaRoomEntryPointers_Pointer = sAreaRoomEntryPointers;
const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
const u8 (*sAnimatedTilesetEntries_Pointer)[3*16] = sAnimatedTilesetEntries;
static const u32** sMinimapDataPointers_Pointer = sMinimapDataPointers;
static const struct Door** sAreaDoorsPointers_Pointer = sAreaDoorsPointers;
static const u8 (*sAreaConnections_Pointer)[AREA_CONNECTION_FIELD_COUNT] = sAreaConnections;
static const struct AnimatedPaletteData* sAnimatedPaletteEntries_Pointer = sAnimatedPaletteEntries;
static const u32** sSpritesGraphicsPointers_Pointer = sSpritesGraphicsPointers;
static const u16** sSpritesPalettePointers_Pointer = sSpritesPalettePointers;
static const u16* sGunshipFlashingPal_Pointer = sGunshipFlashingPal;
static const u8** sSpritesetPointers_Pointer = sSpritesetPointers;
static const u16* sSamusPalettes_Pointer = sSamusPal_PowerSuit_Default;
static const u16* sHelmetCursorPalettes_Pointer = sFileSelectIconsPal;
static const u16* sBeamPalettes_Pointer = sBeamPal;
static const u16* sStatueCutscenePalette_Pointer = sStatueOpeningPal;
static const u16*** sMessageTextPointers_Pointer = sMessageTextPointers;
static const u16*** sStoryTextPointers_Pointer = sStoryTextPointers;
static const u8* sCharacterWidths_Pointer = sCharacterWidths;
static const struct SoundEntry* sSoundDataEntries_Pointer = sSoundDataEntries;
static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;
const struct CreditsEntry* sCredits_Pointer = sCredits;

// --------------------------------
// Rando data
// --------------------------------

// Need to write starting area to cutscene data entry
static const struct InGameCutsceneData* sIntroCutsceneData_Pointer = &sInGameCutsceneData[IGC_CLOSE_UP];

static const struct StartingInfo* sStartingInfo_Pointer = &sStartingInfo;

static const struct MajorLocation* sMajorLocations_Pointer = sMajorLocations;
static const struct MinorLocation* sMinorLocations_Pointer = sMinorLocations;

static const struct TankIncreaseAmounts* sRandoTankIncreaseAmounts_Pointer = &sRandoTankIncreaseAmounts;

static const u8* const* sRandoTitleLines_Pointer = sRandoTitleLines;
static const u16* sRandoSeedHash_Pointer = sRandoSeedHash;
static const u16* const* const* sRoomNames_Pointer = sRoomNames;


// --------------------------------
// Rando options
// --------------------------------

static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;
static const boolu8* sRandoDefaultStereo_Pointer = &sRandoDefaultStereo;
static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];
static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;
static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;
static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;
static const boolu8* sRandoDisableMidAirBombJump_Pointer = &sRandoDisableMidAirBombJump;
static const boolu8* sRandoDisableWallJump_Pointer = &sRandoDisableWallJump;
static const boolu8* sRandoRemoveCutscenes_Pointer = &sRandoRemoveCutscenes;
static const boolu8* sRandoFastItemGrab_Pointer = &sRandoFastItemGrab;
static const boolu8* sRandoSkipSuitlessSequence_Pointer = &sRandoSkipSuitlessSequence;

#endif
