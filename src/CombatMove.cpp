#include <iostream>
#include "CombatMove.h"
#include "Pokemon.h"
#include "Utilities.h"
#include <windows.h>

/*void CombatMove::displayMoves(Pokemon &pokemon)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << " " << i+1 << ". " << pokemon.moves[i].name << "\n";
    }
}*/

bool CombatMove::checkPP(CombatMove *move){

    if (move->PP == 0){

        animatedText(" No PP left for this move.", 25);
        std::cout << "\n";
        Sleep(2000);
        return false;
    }
    return true;
}