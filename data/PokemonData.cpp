#include "Enums.h"
#include "Pokemon.h"
#include "PokemonData.h"
#include "MoveData.h"

Pokemon pikachu(
    "Pikachu",
    ELECTRIC,
    200,
    55, 40, 50, 50,
    NONE,
    thunderBolt,
    quickAttack,
    ironTail,
    thunder
);

Pokemon charizard(
    "Charizard",
    FIRE,
    300,
    84, 78, 109, 85,
    NONE,
    flameThrower,
    fireBlast,
    airSlash,
    dragonClaw
);

Pokemon blastoise(
    "Blastoise",
    WATER,
    320,
    83, 100, 85, 105,
    NONE,
    hydroPump,
    surf,
    iceBeam,
    bite
);

Pokemon venusaur(
    "Venusaur",
    GRASS,
    320,
    82, 83, 100, 100,
    NONE,
    solarBeam,
    razorLeaf,
    sludgeBomb,
    screech
);

Pokemon golem(
    "Golem",
    ROCK,
    350,
    120, 130, 55, 65,
    NONE,
    earthquake,
    rockSlide,
    stoneEdge,
    ironDefense
);

Pokemon alakazam(
    "Alakazam",
    PSYCHIC,
    250,
    50, 45, 135, 95,
    NONE,
    psychic,
    psyBeam,
    shadowBall,
    calmMind
);

Pokemon machamp(
    "Machamp",
    FIGHTING,
    340,
    130, 80, 65, 85,
    NONE,
    dynamicPunch,
    closeCombat,
    karateChop,
    bulkUp
);

Pokemon gengar(
    "Gengar",
    GHOST,
    270,
    65, 60, 130, 75,
    NONE,
    shadowBall,
    darkPulse,
    dreamEater,
    nastyPlot
);

Pokemon dragonite(
    "Dragonite",
    DRAGON,
    360,
    134, 95, 100, 100,
    NONE,
    dragonClaw,
    dragonRush,
    hurricane,
    howl
);

Pokemon lapras(
    "Lapras",
    WATER,
    380,
    85, 80, 85, 95,
    NONE,
    surf,
    blizzard,
    bodySlam,
    iceBeam
);

extern const Pokemon pokemonPool[10] = {pikachu, charizard, blastoise, venusaur,
                            golem, alakazam, machamp,
                            gengar, dragonite, lapras};

extern const int  pokemonPoolSize = sizeof(pokemonPool)/sizeof(pokemonPool[0]);