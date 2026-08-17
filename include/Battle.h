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

    private:
        void playerTurn();
        void botTurn();
        int calculateDamage();
        bool isFainted();
        bool battleOver();
        CombatMove* getPlayerMove();
        void displayHPBar(Pokemon *pokemon);
        void displayBattle();
        void executeMove(Pokemon *attacker, std::string attackerLabel, CombatMove *move, Pokemon *defender);
        bool moveHits(std::string name, CombatMove *move);
        int calculateNormalDamage(CombatMove *move);
        int calculateSpecialDamage(CombatMove *move);
        double stageMultiplier(int stage);
        void applyEffect(Pokemon *attacker, CombatMove *move, Pokemon *defender);
};