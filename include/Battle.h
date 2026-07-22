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

};