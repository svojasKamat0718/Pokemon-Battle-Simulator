#pragma once

enum Status
{
    NONE,
    BURNED,
    POISONED
};

enum Type{
    NORMAL,
    ELECTRIC,
    FIRE,
    WATER,
    GRASS,
    ROCK,
    PSYCHIC,
    FIGHTING,
    GHOST,
    DRAGON,
    ICE,
    GROUND,
    FLYING,
    POISON,
    DARK,
    STEEL
};

enum MoveCategory
{
    PHYSICAL,
    SPECIAL,
    STATUS
};

enum MoveEffect
{
    NO_EFFECT,

    BURN_EFFECT,
    POISON_EFFECT,

    ATTACK_UP,
    ATTACK_DOWN,

    DEFENCE_UP,
    DEFENCE_DOWN,

    SP_ATTACK_UP,
    SP_ATTACK_DOWN,

    SP_DEFENCE_UP,
    SP_DEFENCE_DOWN
};
