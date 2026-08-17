#pragma once
#include "Pokemon.h"

class Game{

    public:
        void run();

    private:
        Pokemon selectPokemon();
        int getBotDifficulty();
        void botDifficultyInfo();
};