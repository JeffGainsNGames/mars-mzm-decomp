#ifndef RANDOMIZER_STRUCT_H
#define RANDOMIZER_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/randomizer.h"
#include "constants/samus.h"

#ifdef RANDOMIZER

struct MajorLocation {
    /* 0 */ RandoItemType item;
    /* 1 */ RandoItemJingle jingle;
    /* 2 */ u8 hintedBy;
    /* 3 */ u8 messageId;
    /* 4 */ const u16 *(*customMessage)[LANGUAGE_COUNT];
}; // Size: 8

struct MinorLocation {
    /* 0 */ u32 key; // See MINOR_LOC_KEY macro
    /* 4 */ u16 bg1Value; // Needed for hidden items
    /* 6 */ RandoItemType item;
    /* 7 */ RandoItemJingle jingle;
    /* 8 */ u8 hintedBy;
    /* 9 */ u8 messageId;
    /* C */ const u16 *(*customMessage)[LANGUAGE_COUNT];
}; // Size: 0x10

struct CurrentRandoItem {
    /* 0 */ boolu8 isMinor;
    /* 1 */ RandoItemType item;
    /* 2 */ RandoItemJingle jingle;
    /* 3 */ u8 messageId;
    /* 4 */ const u16 *(*customMessage)[LANGUAGE_COUNT];
}; // Size: 8

struct TankIncreaseAmounts {
    /* 0 */ u16 energyTank;
    /* 2 */ u16 missileTank;
    /* 4 */ u8 superMissileTank;
    /* 5 */ u8 powerBombTank;
    /* 6 */ u16 mainMissiles;
    /* 8 */ u8 mainSuperMissiles;
    /* 9 */ u8 mainPowerBombs;
};

struct StartingInfo {
    // Location
    /* 00 */ Area area;
    /* 01 */ u8 room;
    /* 02 */ u8 door;
    /* 03 */ u8 blockX;
    /* 04 */ u8 blockY;
    // Equipment
    /* 06 */ u16 maxEnergy;
    /* 08 */ u16 maxMissiles;
    /* 0A */ u8 maxSuperMissiles;
    /* 0B */ u8 maxPowerBombs;
    /* 0C */ BeamBombFlags beamBombs;
    /* 0D */ SuitMiscFlags suitMisc;
    /* 0E */ MainItemFlags mainItems;
    /* 0F */ u8 downloadedMapStatus;
    /* 10 */ SuitType suitType;
    /* 11 */ boolu8 ziplinesActivated;
    // Disabled hints
    /* 12 */ u8 disabledHints;
};

extern struct CurrentRandoItem gCurrentRandoItem;

#endif // RANDOMIZER

#endif // RANDOMIZER_STRUCT_H
