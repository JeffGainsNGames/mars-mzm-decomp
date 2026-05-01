#include "data/sprites/space_pirate_carrying_power_bomb.h"
#include "macros.h"

const u32 sFakePowerBombGfx[115] = INCBIN_U32("data/sprites/fake_power_bomb.gfx.lz");
const u16 sFakePowerBombPal[16] = INCBIN_U16("data/sprites/fake_power_bomb.pal");

static const u16 sFakePowerBombOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sFakePowerBombOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sFakePowerBombOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sFakePowerBombOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0)
};

#ifdef RANDOMIZER
    #define PB_ANIM_SPEED 10
#else // !RANDOMIZER
    #define PB_ANIM_SPEED CONVERT_SECONDS(0.1f)
#endif // RANDOMIZER

const struct FrameData sFakePowerBombOam_Idle[5] = {
    [0] = {
        .pFrame = sFakePowerBombOam_Idle_Frame0,
        .timer = PB_ANIM_SPEED
    },
    [1] = {
        .pFrame = sFakePowerBombOam_Idle_Frame1,
        .timer = PB_ANIM_SPEED
    },
    [2] = {
        .pFrame = sFakePowerBombOam_Idle_Frame2,
        .timer = PB_ANIM_SPEED
    },
    [3] = {
#ifdef RANDOMIZER
        .pFrame = sFakePowerBombOam_Idle_Frame1,
#else // !RANDOMIZER
        .pFrame = sFakePowerBombOam_Idle_Frame3,
#endif // RANDOMIZER
        .timer = PB_ANIM_SPEED
    },
    [4] = FRAME_DATA_TERMINATOR
};
