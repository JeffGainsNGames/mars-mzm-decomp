#include "macros.h"

#include "data/randomizer_data.h"

#include "constants/event.h"
#include "constants/menus/pause_screen.h"
#include "constants/randomizer.h"
#include "constants/text.h"

#ifdef RANDOMIZER

// New data

const u8 sRandoEmptyGfx[384] = INCBIN_U8("data_rando/animated_gfx/empty.gfx");
const u8 sRandoMainMissilesGfx[384] = INCBIN_U8("data_rando/animated_gfx/main_missiles.gfx");
const u8 sRandoMainSuperMissilesGfx[384] = INCBIN_U8("data_rando/animated_gfx/main_super_missiles.gfx");
const u8 sRandoMainPowerBombsGfx[384] = INCBIN_U8("data_rando/animated_gfx/main_power_bombs.gfx");
const u8 sRandoLongBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/long_beam.gfx");
const u8 sRandoChargeBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/charge_beam.gfx");
const u8 sRandoIceBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/ice_beam.gfx");
const u8 sRandoWaveBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/wave_beam.gfx");
const u8 sRandoPlasmaBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/plasma_beam.gfx");
const u8 sRandoBombsGfx[384] = INCBIN_U8("data_rando/animated_gfx/bombs.gfx");
const u8 sRandoVariaSuitGfx[384] = INCBIN_U8("data_rando/animated_gfx/varia_suit.gfx");
const u8 sRandoGravitySuitGfx[384] = INCBIN_U8("data_rando/animated_gfx/gravity_suit.gfx");
const u8 sRandoMorphBallGfx[384] = INCBIN_U8("data_rando/animated_gfx/morph_ball.gfx");
const u8 sRandoSpeedBoosterGfx[384] = INCBIN_U8("data_rando/animated_gfx/speed_booster.gfx");
const u8 sRandoHiJumpGfx[384] = INCBIN_U8("data_rando/animated_gfx/hi_jump.gfx");
const u8 sRandoScrewAttackGfx[384] = INCBIN_U8("data_rando/animated_gfx/screw_attack.gfx");
const u8 sRandoSpaceJumpGfx[384] = INCBIN_U8("data_rando/animated_gfx/space_jump.gfx");
const u8 sRandoPowerGripGfx[384] = INCBIN_U8("data_rando/animated_gfx/power_grip.gfx");
const u8 sRandoFullyPoweredGfx[384] = INCBIN_U8("data_rando/animated_gfx/fully_powered.gfx");
const u8 sRandoZiplinesGfx[384] = INCBIN_U8("data_rando/animated_gfx/ziplines.gfx");
const u8 sRandoInfantMetroidGfx[384] = INCBIN_U8("data_rando/animated_gfx/infant_metroid.gfx");
const u8 sRandoAnonymousGfx[384] = INCBIN_U8("data_rando/animated_gfx/anonymous.gfx");

const u16 sMissingRoomName[] = INCTEXT("Room name not provided");

// From patcher

const u8 sRandoGoal = GOAL_INFANT_METROIDS;
const u8 sRandoDifficultyOptions = DIFF_OPT_UNCHANGED;
const boolu8 sRandoDefaultStereo = TRUE;
const boolu8 sRandoBlackPiratesRequirePlasma = TRUE;
const boolu8 sRandoSkipDoorTransitions = FALSE;
const boolu8 sRandoBallLauncherWithoutBombs = FALSE;
const boolu8 sRandoDisableMidAirBombJump = FALSE;
const boolu8 sRandoDisableWallJump = FALSE;
const boolu8 sRandoRemoveCutscenes = FALSE;
const boolu8 sRandoSkipSuitlessSequence = FALSE;

const struct TankIncreaseAmounts sRandoTankIncreaseAmounts = {
    .energyTank = 100,
    .missileTank = 5,
    .superMissileTank = 5,
    .powerBombTank = 2,
    .mainMissiles = 5,
    .mainSuperMissiles = 5,
    .mainPowerBombs = 2
};

const struct StartingInfo sStartingInfo = {
    // Location
    .area = AREA_BRINSTAR,
    .room = 0,
    .door = 0,
    .blockX = 39,
    .blockY = 29,
    // Equipment
    .maxEnergy = 99,
    .maxMissiles = 0,
    .maxSuperMissiles = 0,
    .maxPowerBombs = 0,
    .beamBombs = BBF_NONE,
    .suitMisc = SMF_NONE,
    .mainItems = MIF_NONE,
    .downloadedMapStatus = 0,
    .suitType = SUIT_FULLY_POWERED,
    // Disabled hints
    .disabledHints = 0
};

static const u8 sRandoTitleLine00[31] = "";
static const u8 sRandoTitleLine01[31] = "";
static const u8 sRandoTitleLine02[31] = "";
static const u8 sRandoTitleLine03[31] = "";
static const u8 sRandoTitleLine04[31] = "";
static const u8 sRandoTitleLine05[31] = "";
static const u8 sRandoTitleLine06[31] = "";
static const u8 sRandoTitleLine07[31] = "";
static const u8 sRandoTitleLine08[31] = "";
static const u8 sRandoTitleLine09[31] = "";
static const u8 sRandoTitleLine10[31] = "";
static const u8 sRandoTitleLine11[31] = "";
#ifdef DEBUG
static const u8 sRandoTitleLine12[31] = "         DEBUG BUILD";
#else // !DEBUG
static const u8 sRandoTitleLine12[31] = "";
#endif // DEBUG
static const u8 sRandoTitleLine13[31] = "";
static const u8 sRandoTitleLine14[31] = "";
static const u8 sRandoTitleLine15[31] = "";
static const u8 sRandoTitleLine16[31] = "";
static const u8 sRandoTitleLine17[31] = "";
static const u8 sRandoTitleLine18[31] = "";
static const u8 sRandoTitleLine19[31] = "";

const u8* const sRandoTitleLines[20] = {
    sRandoTitleLine00, sRandoTitleLine01, sRandoTitleLine02, sRandoTitleLine03,
    sRandoTitleLine04, sRandoTitleLine05, sRandoTitleLine06, sRandoTitleLine07,
    sRandoTitleLine08, sRandoTitleLine09, sRandoTitleLine10, sRandoTitleLine11,
    sRandoTitleLine12, sRandoTitleLine13, sRandoTitleLine14, sRandoTitleLine15,
    sRandoTitleLine16, sRandoTitleLine17, sRandoTitleLine18, sRandoTitleLine19,
};

const u16 sRandoSeedHash[12] = INCTEXT("");

static const u16* const sBrinstarRoomNames[0x2A] = {0};
static const u16* const sKraidRoomNames[0x2A] = {0};
static const u16* const sNorfairRoomNames[0x39] = {0};
static const u16* const sRidleyRoomNames[0x21] = {0};
static const u16* const sTourianRoomNames[0x14] = {0};
static const u16* const sCrateriaRoomNames[0x16] = {0};
static const u16* const sChozodiaRoomNames[0x63] = {0};

const u16* const* const sRoomNames[AREA_NORMAL_COUNT] = {
    [AREA_BRINSTAR] = sBrinstarRoomNames,
    [AREA_KRAID] = sKraidRoomNames,
    [AREA_NORFAIR] = sNorfairRoomNames,
    [AREA_RIDLEY] = sRidleyRoomNames,
    [AREA_TOURIAN] = sTourianRoomNames,
    [AREA_CRATERIA] = sCrateriaRoomNames,
    [AREA_CHOZODIA] = sChozodiaRoomNames,
};

const struct MajorLocation sMajorLocations[ITEM_SOURCE_COUNT] = {
    [ITEM_SOURCE_LONG_BEAM] = {
        .item = RIT_LONG_BEAM,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_CHARGE_BEAM] = {
        .item = RIT_CHARGE_BEAM,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_ICE_BEAM] = {
        .item = RIT_ICE_BEAM,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_WAVE_BEAM] = {
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_PLASMA_BEAM] = {
        .item = RIT_PLASMA_BEAM,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_BOMBS] = {
        .item = RIT_BOMBS,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_VARIA_SUIT] = {
        .item = RIT_VARIA_SUIT,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_GRAVITY_SUIT] = {
        .item = RIT_GRAVITY_SUIT,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_MORPH_BALL] = {
        .item = RIT_MORPH_BALL,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_SPEED_BOOSTER] = {
        .item = RIT_SPEED_BOOSTER,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_HI_JUMP] = {
        .item = RIT_HI_JUMP,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_SCREW_ATTACK] = {
        .item = RIT_SCREW_ATTACK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_SPACE_JUMP] = {
        .item = RIT_SPACE_JUMP,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_POWER_GRIP] = {
        .item = RIT_POWER_GRIP,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_FULLY_POWERED] = {
        .item = RIT_FULLY_POWERED,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    [ITEM_SOURCE_ZIPLINES] = {
        .item = RIT_ZIPLINES,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
};

// NOTE: These need to be ordered by increasing key value (area, room, block y, block x)
const struct MinorLocation sMinorLocations[MINOR_LOCATION_COUNT] = {
    { // Brinstar 0x1 at 13, 7
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x1, 13, 7),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x2 at 28, 2
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x2, 28, 2),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0xC at 54, 6
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0xC, 54, 6),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0xE at 14, 23
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0xE, 14, 23),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0xF at 4, 6
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0xF, 4, 6),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x13 at 39, 6
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x13, 39, 6),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x13 at 11, 10
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x13, 11, 10),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x15 at 39, 5
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x15, 39, 5),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x17 at 18, 16
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x17, 18, 16),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x19 at 11, 5
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x19, 11, 5),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x1D at 4, 10
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x1D, 4, 10),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x28 at 7, 4
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x28, 7, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x29 at 5, 18
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x29, 5, 18),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Brinstar 0x29 at 5, 25
        .key = MINOR_LOC_KEY(AREA_BRINSTAR, 0x29, 5, 25),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x1 at 24, 4
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x1, 24, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x2 at 9, 33
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x2, 9, 33),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x4 at 22, 6
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x4, 22, 6),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x7 at 38, 14
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x7, 38, 14),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x8 at 74, 20
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x8, 74, 20),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x9 at 60, 9
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x9, 60, 9),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0xA at 9, 9
        .key = MINOR_LOC_KEY(AREA_KRAID, 0xA, 9, 9),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x11 at 2, 4
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x11, 2, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x15 at 20, 3
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x15, 20, 3),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x1A at 7, 10
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x1A, 7, 10),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Kraid 0x26 at 5, 4
        .key = MINOR_LOC_KEY(AREA_KRAID, 0x26, 5, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x1 at 65, 4
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x1, 65, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x3 at 72, 4
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x3, 72, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x4 at 74, 9
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x4, 74, 9),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x5 at 14, 79
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x5, 14, 79),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x5 at 8, 111
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x5, 8, 111),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0xA at 11, 4
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0xA, 11, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x11 at 17, 4
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x11, 17, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x1C at 28, 3
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x1C, 28, 3),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x1C at 54, 4
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x1C, 54, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x20 at 45, 3
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x20, 45, 3),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x20 at 4, 5
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x20, 4, 5),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x25 at 21, 3
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x25, 21, 3),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x26 at 5, 6
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x26, 5, 6),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x2A at 33, 5
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x2A, 33, 5),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x2F at 24, 3
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x2F, 24, 3),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x37 at 8, 14
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x37, 8, 14),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Norfair 0x37 at 30, 23
        .key = MINOR_LOC_KEY(AREA_NORFAIR, 0x37, 30, 23),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x4 at 6, 8
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x4, 6, 8),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x6 at 8, 33
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x6, 8, 33),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x9 at 9, 4
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x9, 9, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0xA at 27, 6
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0xA, 27, 6),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0xA at 15, 15
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0xA, 15, 15),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0xD at 8, 7
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0xD, 8, 7),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0xE at 27, 9
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0xE, 27, 9),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x10 at 54, 6
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x10, 54, 6),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x11 at 28, 20
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x11, 28, 20),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x12 at 72, 6
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x12, 72, 6),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x13 at 7, 21
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x13, 7, 21),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x16 at 11, 6
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x16, 11, 6),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x16 at 8, 16
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x16, 8, 16),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x17 at 8, 4
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x17, 8, 4),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x17 at 13, 13
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x17, 13, 13),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x1D at 24, 3
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x1D, 24, 3),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x1D at 20, 15
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x1D, 20, 15),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x1E at 4, 13
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x1E, 4, 13),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Ridley 0x1F at 42, 7
        .key = MINOR_LOC_KEY(AREA_RIDLEY, 0x1F, 42, 7),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Tourian 0x7 at 14, 8
        .key = MINOR_LOC_KEY(AREA_TOURIAN, 0x7, 14, 8),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Tourian 0x8 at 11, 109
        .key = MINOR_LOC_KEY(AREA_TOURIAN, 0x8, 11, 109),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Crateria 0x0 at 20, 37
        .key = MINOR_LOC_KEY(AREA_CRATERIA, 0x0, 20, 37),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Crateria 0x7 at 3, 27
        .key = MINOR_LOC_KEY(AREA_CRATERIA, 0x7, 3, 27),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Crateria 0x9 at 90, 9
        .key = MINOR_LOC_KEY(AREA_CRATERIA, 0x9, 90, 9),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Crateria 0x9 at 64, 34
        .key = MINOR_LOC_KEY(AREA_CRATERIA, 0x9, 64, 34),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Crateria 0xE at 8, 10
        .key = MINOR_LOC_KEY(AREA_CRATERIA, 0xE, 8, 10),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0xA at 19, 4
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0xA, 19, 4),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0xE at 13, 5
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0xE, 13, 5),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x18 at 10, 13
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x18, 10, 13),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x1A at 44, 8
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x1A, 44, 8),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x22 at 34, 14
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x22, 34, 14),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x2F at 9, 17
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x2F, 9, 17),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x31 at 10, 7
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x31, 10, 7),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x36 at 59, 20
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x36, 59, 20),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x41 at 9, 3
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x41, 9, 3),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x42 at 16, 13
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x42, 16, 13),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x47 at 59, 19
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x47, 59, 19),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x49 at 9, 6
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x49, 9, 6),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x4E at 44, 8
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x4E, 44, 8),
        .bg1Value = 0x49,
        .item = RIT_ENERGY_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x57 at 18, 18
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x57, 18, 18),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x59 at 6, 27
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x59, 6, 27),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x5A at 56, 24
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x5A, 56, 24),
        .bg1Value = 0x48,
        .item = RIT_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x5A at 56, 40
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x5A, 56, 40),
        .bg1Value = 0x4B,
        .item = RIT_SUPER_MISSILE_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
    { // Chozodia 0x5F at 24, 6
        .key = MINOR_LOC_KEY(AREA_CHOZODIA, 0x5F, 24, 6),
        .bg1Value = 0x4A,
        .item = RIT_POWER_BOMB_TANK,
        .jingle = RIJ_DEFAULT,
        .hintedBy = UCHAR_MAX,
        .messageId = UCHAR_MAX,
        .customMessage = NULL,
    },
};

#endif // RANDOMIZER
