#include "randomizer.h"

#include "audio_wrappers.h"
#include "event.h"
#include "in_game_cutscene.h"
#include "particle.h"
#include "projectile_util.h"
#include "samus.h"
#include "sprite.h"

#include "data/randomizer_data.h"
#include "data/text_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/in_game_cutscene.h"
#include "constants/menus/pause_screen.h"
#include "constants/particle.h"
#include "constants/randomizer.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/game_state.h"
#include "structs/samus.h"

#ifdef RANDOMIZER

static u8 sRandoHintEvents[TARGET_ITEM_COUNT][2] = {
    [TARGET_LONG_BEAM] = {
        EVENT_STATUE_LONG_BEAM_GRABBED,
        EVENT_COLLECTED_LONG_BEAM_HINT
    },
    [TARGET_BOMBS] = {
        EVENT_STATUE_BOMBS_GRABBED,
        EVENT_COLLECTED_BOMBS_HINT
    },
    [TARGET_ICE_BEAM] = {
        EVENT_STATUE_ICE_BEAM_GRABBED,
        EVENT_COLLECTED_ICE_BEAM_HINT
    },
    [TARGET_SPEED_BOOSTER] = {
        EVENT_STATUE_SPEEDBOOSTER_GRABBED,
        EVENT_COLLECTED_SPEED_BOOSTER_HINT
    },
    [TARGET_HIGH_JUMP] = {
        EVENT_STATUE_HIGH_JUMP_GRABBED,
        EVENT_COLLECTED_HI_JUMP_HINT
    },
    [TARGET_VARIA] = {
        EVENT_STATUE_VARIA_SUIT_GRABBED,
        EVENT_COLLECTED_VARIA_SUIT_HINT
    },
    [TARGET_WAVE_BEAM] = {
        EVENT_STATUE_WAVE_BEAM_GRABBED,
        EVENT_COLLECTED_WAVE_BEAM_HINT
    },
    [TARGET_SCREW_ATTACK] = {
        EVENT_STATUE_SCREW_ATTACK_GRABBED,
        EVENT_COLLECTED_SCREW_ATTACK_HINT
    },
};

/**
 * @brief Finds a minor location using binary search
 */
const struct MinorLocation* RandoGetMinorLocation(Area area, u8 room, u8 blockX, u8 blockY)
{
    u32 key;
    u32 left;
    u32 right;
    u32 mid;

    key = MINOR_LOC_KEY(area, room, blockX, blockY);
    left = 0;
    right = MINOR_LOCATION_COUNT - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        
        if (sMinorLocations[mid].key < key)
            left = mid + 1;
        else if (sMinorLocations[mid].key > key)
            right = mid - 1;
        else
            return &sMinorLocations[mid];
    }

    return NULL;
}

/**
 * @brief Handles collecting an item, including updating equipment, spawning
 * a message banner, and updating events
 */
static void RandoCollectItem(RandoItemType item, u8 hintedBy)
{
    boolu8 isFirstTank;
    // message is for spawning the message banner, the actual text can be
    // overridden with custom text
    s32 message;
    s32 amount;

    message = MESSAGE_NONE;

    // Update equipment
    switch (item)
    {
        case RIT_NONE:
            message = MESSAGE_NOTHING_ACQUIRED;
            break;

        case RIT_ENERGY_TANK:
            message = MESSAGE_ENERGY_TANK_ACQUIRED;

            gEquipment.maxEnergy += sRandoTankIncreaseAmounts.energyTank;
            if (gEquipment.maxEnergy > MAX_ENERGY_CAPACITY)
                gEquipment.maxEnergy = MAX_ENERGY_CAPACITY;

            gEquipment.currentEnergy = gEquipment.maxEnergy;
            break;

        case RIT_MISSILE_TANK:
        case RIT_MAIN_MISSILES:
            if (item == RIT_MAIN_MISSILES)
            {
                gEquipment.mainItems |= MIF_MISSILES;
                gEquipment.mainItemsActivation |= MIF_MISSILES;
                amount = sRandoTankIncreaseAmounts.mainMissiles;
                message = MESSAGE_FIRST_MISSILE_TANK;
            }
            else
            {
                amount = sRandoTankIncreaseAmounts.missileTank;
                message = MESSAGE_MISSILE_TANK_ACQUIRED;
            }

            gEquipment.maxMissiles += amount;
            if (gEquipment.maxMissiles > MAX_MISSILE_CAPACITY)
                gEquipment.maxMissiles = MAX_MISSILE_CAPACITY;

            gEquipment.currentMissiles += amount;
            if (gEquipment.currentMissiles > MAX_MISSILE_CAPACITY)
                gEquipment.currentMissiles = MAX_MISSILE_CAPACITY;
            break;

        case RIT_SUPER_MISSILE_TANK:
        case RIT_MAIN_SUPER_MISSILES:
            if (item == RIT_MAIN_SUPER_MISSILES)
            {
                gEquipment.mainItems |= MIF_SUPER_MISSILES;
                gEquipment.mainItemsActivation |= MIF_SUPER_MISSILES;
                amount = sRandoTankIncreaseAmounts.mainSuperMissiles;
                message = MESSAGE_FIRST_SUPER_MISSILE_TANK;
            }
            else
            {
                amount = sRandoTankIncreaseAmounts.superMissileTank;
                message = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED;
            }

            gEquipment.maxSuperMissiles += amount;
            if (gEquipment.maxSuperMissiles > MAX_SUPER_MISSILE_CAPACITY)
                gEquipment.maxSuperMissiles = MAX_SUPER_MISSILE_CAPACITY;

            gEquipment.currentSuperMissiles += amount;
            if (gEquipment.currentSuperMissiles > MAX_SUPER_MISSILE_CAPACITY)
                gEquipment.currentSuperMissiles = MAX_SUPER_MISSILE_CAPACITY;
            break;

        case RIT_POWER_BOMB_TANK:
        case RIT_MAIN_POWER_BOMBS:
            if (item == RIT_MAIN_POWER_BOMBS)
            {
                gEquipment.mainItems |= MIF_POWER_BOMBS;
                gEquipment.mainItemsActivation |= MIF_POWER_BOMBS;
                amount = sRandoTankIncreaseAmounts.mainPowerBombs;
                message = MESSAGE_FIRST_POWER_BOMB_TANK;
            }
            else
            {
                amount = sRandoTankIncreaseAmounts.powerBombTank;
                message = MESSAGE_POWER_BOMB_TANK_ACQUIRED;
            }

            gEquipment.maxPowerBombs += amount;
            if (gEquipment.maxPowerBombs > MAX_POWER_BOMB_CAPACITY)
                gEquipment.maxPowerBombs = MAX_POWER_BOMB_CAPACITY;

            gEquipment.currentPowerBombs += amount;
            if (gEquipment.currentPowerBombs > MAX_POWER_BOMB_CAPACITY)
                gEquipment.currentPowerBombs = MAX_POWER_BOMB_CAPACITY;
            break;
        
        case RIT_LONG_BEAM:
            message = MESSAGE_LONG_BEAM;
            gEquipment.beamBombs |= BBF_LONG_BEAM;
            break;

        case RIT_CHARGE_BEAM:
            message = MESSAGE_CHARGE_BEAM;
            gEquipment.beamBombs |= BBF_CHARGE_BEAM;
            break;

        case RIT_ICE_BEAM:
            message = MESSAGE_ICE_BEAM;
            gEquipment.beamBombs |= BBF_ICE_BEAM;
            break;

        case RIT_WAVE_BEAM:
            message = MESSAGE_WAVE_BEAM;
            gEquipment.beamBombs |= BBF_WAVE_BEAM;
            break;

        case RIT_PLASMA_BEAM:
            message = MESSAGE_UKNOWN_ITEM_PLASMA;
            gEquipment.beamBombs |= BBF_PLASMA_BEAM;
            break;

        case RIT_BOMBS:
            message = MESSAGE_BOMB;
            gEquipment.beamBombs |= BBF_BOMBS;
            break;

        case RIT_VARIA_SUIT:
            message = MESSAGE_VARIA_SUIT;
            gEquipment.suitMisc |= SMF_VARIA_SUIT;
            break;

        case RIT_GRAVITY_SUIT:
            message = MESSAGE_UNKNOWN_ITEM_GRAVITY;
            gEquipment.suitMisc |= SMF_GRAVITY_SUIT;
            break;

        case RIT_MORPH_BALL:
            message = MESSAGE_MORPH_BALL;
            gEquipment.suitMisc |= SMF_MORPH_BALL;
            break;

        case RIT_SPEED_BOOSTER:
            message = MESSAGE_SPEED_BOOSTER;
            gEquipment.suitMisc |= SMF_SPEEDBOOSTER;
            break;

        case RIT_HI_JUMP:
            message = MESSAGE_HIGH_JUMP;
            gEquipment.suitMisc |= SMF_HIGH_JUMP;
            break;

        case RIT_SCREW_ATTACK:
            message = MESSAGE_SCREW_ATTACK;
            gEquipment.suitMisc |= SMF_SCREW_ATTACK;
            break;

        case RIT_SPACE_JUMP:
            message = MESSAGE_UNKNOWN_ITEM_SPACE_JUMP;
            gEquipment.suitMisc |= SMF_SPACE_JUMP;
            break;

        case RIT_POWER_GRIP:
            message = MESSAGE_POWER_GRIP;
            gEquipment.suitMisc |= SMF_POWER_GRIP;
            break;

        case RIT_FULLY_POWERED:
            message = MESSAGE_FULLY_POWERED_SUIT;
            gEquipment.suitType = SUIT_FULLY_POWERED;
            // Activate unknown items if obtained
            gEquipment.beamBombsActivation |= gEquipment.beamBombs & BBF_PLASMA_BEAM;
            gEquipment.suitMiscActivation |= gEquipment.suitMisc & (SMF_SPACE_JUMP | SMF_GRAVITY_SUIT);
            ProjectileLoadGraphics();
            break;

        case RIT_ZIPLINES:
            message = MESSAGE_ZIPLINES;
            SET_EVENT(EVENT_ZIPLINES_ACTIVATED);
            break;
        
        case RIT_ICE_TRAP:
            message = MESSAGE_ICE_TRAP;
            // Play freeze sound
            SoundPlayNotAlreadyPlaying(SOUND_FREEZING_SPRITE);
            // Add charged ice beam effect
            ParticleSet(gSamusData.yPosition + (gSamusPhysics.hitboxTop / 2),
                gSamusData.xPosition, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
            // TODO: Freeze Samus
            SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
            break;
    }

    // Spawn the message banner
    if (message != MESSAGE_NONE)
    {
        SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, message, SPRITE_GFX_SLOT_SPECIAL,
            gSamusData.yPosition, gSamusData.xPosition, 0);
    }

    if (hintedBy != UCHAR_MAX && hintedBy < TARGET_ITEM_COUNT)
        RandoSetHintEvents(hintedBy);
}

/**
 * @brief Updates equipment, spawns a message banner, and stores the item,
 * jingle, and custom message for a major location item
 */
void RandoCollectMajorLocationItem(ItemSource source)
{
    const struct MajorLocation* loc;

    loc = &sMajorLocations[source];
    gCurrentRandoItem.isMinor = FALSE;
    gCurrentRandoItem.item = loc->item;
    gCurrentRandoItem.jingle = loc->jingle;
    gCurrentRandoItem.messageId = loc->messageId;
    gCurrentRandoItem.customMessage = loc->customMessage;

    RandoCollectItem(loc->item, loc->hintedBy);
}

/**
 * @brief Updates equipment, spawns a message banner, and stores the item,
 * jingle, and custom message for a minor location item
 */
void RandoCollectMinorLocationItem(const struct MinorLocation* loc)
{
    gCurrentRandoItem.isMinor = TRUE;
    gCurrentRandoItem.item = loc->item;
    gCurrentRandoItem.jingle = loc->jingle;
    gCurrentRandoItem.messageId = loc->messageId;
    gCurrentRandoItem.customMessage = loc->customMessage;

    RandoCollectItem(loc->item, loc->hintedBy);
}

void RandoSetHintEvents(u8 hint)
{
    SET_EVENT(sRandoHintEvents[hint][0]);
    SET_EVENT(sRandoHintEvents[hint][1]);

    if (hint == TARGET_LONG_BEAM)
        InGameCutsceneCheckFlag(TRUE, IGC_LONG_BEAM_HINT);
}

/**
 * @brief TODO
 */
boolu8 RandoIsItemMessage(u8 message)
{
    switch (message)
    {
        case MESSAGE_ENERGY_TANK_ACQUIRED:
        case MESSAGE_MISSILE_TANK_ACQUIRED:
        case MESSAGE_FIRST_MISSILE_TANK:
        case MESSAGE_SUPER_MISSILE_TANK_ACQUIRED:
        case MESSAGE_FIRST_SUPER_MISSILE_TANK:
        case MESSAGE_POWER_BOMB_TANK_ACQUIRED:
        case MESSAGE_FIRST_POWER_BOMB_TANK:
        case MESSAGE_LONG_BEAM:
        case MESSAGE_CHARGE_BEAM:
        case MESSAGE_ICE_BEAM:
        case MESSAGE_WAVE_BEAM:
        case MESSAGE_UKNOWN_ITEM_PLASMA:
        case MESSAGE_BOMB:
        case MESSAGE_VARIA_SUIT:
        case MESSAGE_UNKNOWN_ITEM_GRAVITY:
        case MESSAGE_MORPH_BALL:
        case MESSAGE_SPEED_BOOSTER:
        case MESSAGE_HIGH_JUMP:
        case MESSAGE_SCREW_ATTACK:
        case MESSAGE_UNKNOWN_ITEM_SPACE_JUMP:
        case MESSAGE_POWER_GRIP:
        case MESSAGE_FULLY_POWERED_SUIT:
        case MESSAGE_NOTHING_ACQUIRED:
        case MESSAGE_UNKNOWN_ITEM:
        case MESSAGE_ZIPLINES:
        case MESSAGE_INFANT_METROID:
        case MESSAGE_ICE_TRAP:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief Gets the actual message text based on the message ID
 */
const u16* RandoGetMessageText(u8 message)
{
    if (RandoIsItemMessage(message))
    {
        if (gCurrentRandoItem.messageId != UCHAR_MAX)
        {
            message = gCurrentRandoItem.messageId;
        }
        else if (gCurrentRandoItem.customMessage != NULL)
        {
            return (*gCurrentRandoItem.customMessage)[gLanguage];
        }
        else if (gEquipment.suitType != SUIT_FULLY_POWERED)
        {
            switch (message)
            {
                case MESSAGE_UKNOWN_ITEM_PLASMA:
                case MESSAGE_UNKNOWN_ITEM_GRAVITY:
                case MESSAGE_UNKNOWN_ITEM_SPACE_JUMP:
                    message = MESSAGE_UNKNOWN_ITEM;
                    break;
            }
        }
    }

    return sMessageTextPointers[gLanguage][message];
}

#endif // RANDOMIZER
