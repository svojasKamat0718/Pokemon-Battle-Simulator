#include <iostream>
#include "CombatMove.h"
#include "Pokemon.h"
#include "Utilities.h"
#include <windows.h>

bool CombatMove::checkPP(CombatMove *move){

    if (move->PP == 0){

        animatedText(" No PP left for this move.", 25);
        std::cout << "\n";
        Sleep(2000);
        return false;
    }
    return true;
}