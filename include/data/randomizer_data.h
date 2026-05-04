#ifndef RANDOMIZER_DATA_H
#define RANDOMIZER_DATA_H

#include "types.h"

#include "constants/clipdata.h"
#include "constants/menus/pause_screen.h"

#include "structs/randomizer.h"

#define MINOR_LOC_KEY(area, room, blockX, blockY) ((area << 24) | (room << 16) | (blockY << 8) | blockX)

// New data

extern const u8 sRandoEmptyGfx[384];
extern const u8 sRandoMainMissilesGfx[384];
extern const u8 sRandoMainSuperMissilesGfx[384];
extern const u8 sRandoMainPowerBombsGfx[384];
extern const u8 sRandoLongBeamGfx[384];
extern const u8 sRandoChargeBeamGfx[384];
extern const u8 sRandoIceBeamGfx[384];
extern const u8 sRandoWaveBeamGfx[384];
extern const u8 sRandoPlasmaBeamGfx[384];
extern const u8 sRandoBombsGfx[384];
extern const u8 sRandoVariaSuitGfx[384];
extern const u8 sRandoGravitySuitGfx[384];
extern const u8 sRandoMorphBallGfx[384];
extern const u8 sRandoSpeedBoosterGfx[384];
extern const u8 sRandoHiJumpGfx[384];
extern const u8 sRandoScrewAttackGfx[384];
extern const u8 sRandoSpaceJumpGfx[384];
extern const u8 sRandoPowerGripGfx[384];
extern const u8 sRandoFullyPoweredGfx[384];
extern const u8 sRandoZiplinesGfx[384];
extern const u8 sRandoInfantMetroidGfx[384];
extern const u8 sRandoAnonymousGfx[384];

extern const u16 sMissingRoomName[];

extern const u16 sBreakableBlockBg1[CLIPDATA_COUNT];

// From patcher

extern const u8 sRandoGoal;
extern const u8 sRandoDifficultyOptions;
extern const boolu8 sRandoDefaultStereo;
extern const boolu8 sRandoBlackPiratesRequirePlasma;
extern const boolu8 sRandoSkipDoorTransitions;
extern const boolu8 sRandoBallLauncherWithoutBombs;
extern const boolu8 sRandoDisableMidAirBombJump;
extern const boolu8 sRandoDisableWallJump;
extern const boolu8 sRandoRevealBreakableBlocks;
extern const boolu8 sRandoRemoveCutscenes;
extern const boolu8 sRandoFastItemGrab;
extern const boolu8 sRandoSkipSuitlessSequence; // Unused

extern const struct TankIncreaseAmounts sRandoTankIncreaseAmounts;

extern const struct StartingInfo sStartingInfo;

extern const u8* const sRandoTitleLines[20];

extern const u16 sRandoSeedHash[12];

extern const u16* const* const sRoomNames[AREA_NORMAL_COUNT];

extern const struct MajorLocation sMajorLocations[ITEM_SOURCE_COUNT];
extern const struct MinorLocation sMinorLocations[MINOR_LOCATION_COUNT];

#endif // RANDOMIZER_DATA_H
