#pragma once
#include "CombatMove.h"
#include "Pokemon.h"


bool hasPP(CombatMove moves[], int index);

int evaluateMove(CombatMove Moves[], int moveCount, Pokemon *player, Pokemon *bot);

CombatMove *getBotMove(CombatMove availableMoves[], int moveCount);