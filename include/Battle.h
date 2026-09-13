#pragma once
#include "Enums.h"
#include "Pokemon.h"
#include "Utilities.h"

class Battle{

    private:
        Pokemon *playerPokemon = nullptr;
        Pokemon *botPokemon = nullptr;

    public:
        void run();

        Battle(Pokemon *player, Pokemon *bot){
            playerPokemon = player;
            botPokemon = bot;
        }
        Battle() = default;

        static double getSTAB_Multiplier(Pokemon *attacker , CombatMove *move);
        static double getTypeMultiplier(CombatMove *move , Type defenderType);

    private:
        void playerTurn();
        void botTurn();
        int calculateDamage(Pokemon *attacker, CombatMove *move, Pokemon *defender, double criticalMultiplier);
        bool isFainted();
        bool battleOver();
        CombatMove* getPlayerMove();
        void displayHPBar(Pokemon *pokemon);
        void displayBattle();
        void executeMove(Pokemon *attacker, std::string attackerLabel, CombatMove *move, Pokemon *defender);
        bool moveHits(std::string name, CombatMove *move);
        void applyEffect(Pokemon *attacker, CombatMove *move, Pokemon *defender);
        void displayTypeMessage(double multiplier , Pokemon *pokemon);
        double getCriticalHit();
        void animateHP(Pokemon* pokemon, double oldHP);
        void applyStatusDamage(Pokemon *pokemon);
};