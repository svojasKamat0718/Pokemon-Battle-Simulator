#include <CombatMove.h>

// =========================
// ELECTRIC
// =========================
CombatMove thunderBolt("Thunder Bolt", ELECTRIC, 90, 100, 15, SPECIAL, NO_EFFECT, 0);
CombatMove thunder("Thunder", ELECTRIC, 110, 70, 10, SPECIAL, NO_EFFECT, 0);
CombatMove thunderPunch("Thunder Punch", ELECTRIC, 75, 100, 15, PHYSICAL, NO_EFFECT, 0);

// =========================
// FIRE
// =========================
CombatMove flameThrower("Flame Thrower", FIRE, 90, 100, 15, SPECIAL, BURN_EFFECT, 10);
CombatMove fireBlast("Fire Blast", FIRE, 110, 85, 5, SPECIAL, BURN_EFFECT, 10);
CombatMove willOWisp("Will-O-Wisp", FIRE, 0, 85, 15, STATUS, BURN_EFFECT, 100);

// =========================
// WATER
// =========================
CombatMove hydroPump("Hydro Pump", WATER, 110, 80, 5, SPECIAL, NO_EFFECT, 0);
CombatMove surf("Surf", WATER, 90, 100, 15, SPECIAL, NO_EFFECT, 0);

// =========================
// GRASS
// =========================
CombatMove solarBeam("Solar Beam", GRASS, 120, 100, 10, SPECIAL, NO_EFFECT, 0);
CombatMove razorLeaf("Razor Leaf", GRASS, 70, 95, 25, PHYSICAL, NO_EFFECT, 0);
CombatMove growth("Growth", GRASS, 0, 100, 20, STATUS, SP_ATTACK_UP, 100);

// =========================
// ICE
// =========================
CombatMove iceBeam("Ice Beam", ICE, 90, 100, 10, SPECIAL, NO_EFFECT, 0);
CombatMove blizzard("Blizzard", ICE, 110, 70, 5, SPECIAL, NO_EFFECT, 0);

// =========================
// ROCK
// =========================
CombatMove rockSlide("Rock Slide", ROCK, 75, 90, 10, PHYSICAL, NO_EFFECT, 0);
CombatMove stoneEdge("Stone Edge", ROCK, 100, 80, 5, PHYSICAL, NO_EFFECT, 0);

// =========================
// GROUND
// =========================
CombatMove earthquake("Earthquake", GROUND, 100, 100, 10, PHYSICAL, NO_EFFECT, 0);

// =========================
// DRAGON
// =========================
CombatMove dragonClaw("Dragon Claw", DRAGON, 80, 100, 15, PHYSICAL, NO_EFFECT, 0);
CombatMove dragonRush("Dragon Rush", DRAGON, 100, 75, 10, PHYSICAL, NO_EFFECT, 0);
CombatMove dragonDance("Dragon Dance", DRAGON, 0, 100, 20, STATUS, ATTACK_UP, 100);

// =========================
// FLYING
// =========================
CombatMove airSlash("Air Slash", FLYING, 75, 95, 15, SPECIAL, NO_EFFECT, 0);
CombatMove hurricane("Hurricane", FLYING, 110, 70, 10, SPECIAL, NO_EFFECT, 0);

// =========================
// POISON
// =========================
CombatMove sludgeBomb("Sludge Bomb", POISON, 90, 100, 10, SPECIAL, POISON_EFFECT, 30);
CombatMove toxic("Toxic", POISON, 0, 90, 10, STATUS, POISON_EFFECT, 100);

// =========================
// STEEL
// =========================
CombatMove ironTail("Iron Tail", STEEL, 100, 75, 15, PHYSICAL, NO_EFFECT, 0);

// =========================
// PSYCHIC
// =========================
CombatMove psychic("Psychic", PSYCHIC, 90, 100, 10, SPECIAL, NO_EFFECT, 0);
CombatMove psyBeam("PsyBeam", PSYCHIC, 65, 100, 20, SPECIAL, NO_EFFECT, 0);
CombatMove futureSight("Future Sight", PSYCHIC, 120, 100, 10, SPECIAL, NO_EFFECT, 0);
CombatMove calmMind("Calm Mind", PSYCHIC, 0, 100, 20, STATUS, SP_ATTACK_UP, 100);
CombatMove dreamEater("Dream Eater", PSYCHIC, 100, 100, 15, SPECIAL, NO_EFFECT, 0);

// =========================
// GHOST
// =========================
CombatMove shadowBall("Shadow Ball", GHOST, 80, 100, 15, SPECIAL, NO_EFFECT, 0);

// =========================
// DARK
// =========================
CombatMove bite("Bite", DARK, 60, 100, 25, PHYSICAL, NO_EFFECT, 0);
CombatMove darkPulse("Dark Pulse", DARK, 80, 100, 15, SPECIAL, NO_EFFECT, 0);

// =========================
// FIGHTING
// =========================
CombatMove dynamicPunch("Dynamic Punch", FIGHTING, 100, 50, 5, PHYSICAL, NO_EFFECT, 0);
CombatMove closeCombat("Close Combat", FIGHTING, 120, 100, 5, PHYSICAL, NO_EFFECT, 0);
CombatMove karateChop("Karate Chop", FIGHTING, 50, 100, 25, PHYSICAL, NO_EFFECT, 0);
CombatMove crossChop("Cross Chop", FIGHTING, 100, 80, 5, PHYSICAL, NO_EFFECT, 0);
CombatMove bulkUp("Bulk Up", FIGHTING, 0, 100, 20, STATUS, ATTACK_UP, 100);

// =========================
// NORMAL
// =========================
CombatMove quickAttack("Quick Attack", NORMAL, 40, 100, 30, PHYSICAL, NO_EFFECT, 0);
CombatMove bodySlam("Body Slam", NORMAL, 85, 100, 15, PHYSICAL, NO_EFFECT, 0);
CombatMove explosion("Explosion", NORMAL, 150, 100, 5, PHYSICAL, NO_EFFECT, 0);