#include <iostream>
#include "CombatMove.h"
#include "Pokemon.h"
#include "Utilities.h"

void CombatMove::displayMoves(Pokemon &pokemon)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << i+1 << ". " << pokemon.moves[i].name << "\n";
    }
}