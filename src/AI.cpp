#include "AI.h"
#include "Battle.h"


bool hasPP(CombatMove moves[], int index)
{
    if (moves[index].PP == 0){
        return false;
    }

    return true;
}

int evaluateMove(CombatMove Moves[], int moveCount, Pokemon *player, Pokemon *bot)
{
    for (int i = 0; i < moveCount; i++) {
            
            Moves[i].moveScore = 0; // Setting moveScore of each move to 0 before evaluating.

            float estimateDamage{};
            if (Moves[i].power != 0){
                
                if (Moves[i].category == 0){
                    estimateDamage =  Moves[i].power 
                               * ((bot->attack
                               * stageMultiplier(bot->attackStage))
                               / (player->defence
                               * stageMultiplier(player->defenceStage)));
                }

                else if (Moves[i].category == 1){
                    estimateDamage =  Moves[i].power 
                               * ((bot->spAttack
                               * stageMultiplier(bot->spAttackStage))
                               / (player->spDefence
                               * stageMultiplier(player->spDefenceStage)));
                }

                Moves[i].moveScore += (estimateDamage/player->currentHP) * 100;

                if (estimateDamage >= player->currentHP) {
                    Moves[i].moveScore += 50; //50 is the KO bonus.
                }
                
                //deducting score based on move accuracy.
                if (Moves[i].accuracy == 100)
                {
                    //No deduction
                }
                else if (Moves[i].accuracy > 90)
                {
                    Moves[i].moveScore -= 5;
                }
                else if (Moves[i].accuracy > 80)
                {
                    Moves[i].moveScore -= 10;
                }
                else if (Moves[i].accuracy > 70)
                {
                    Moves[i].moveScore -= 15;
                }
                else if (Moves[i].accuracy > 60)
                {
                    Moves[i].moveScore -= 20;
                }
                else if (Moves[i].accuracy > 40)
                {
                    Moves[i].moveScore -= 30;
                }
                else
                {
                    Moves[i].moveScore -= 50;
                }



            }
        }
    return 0;
}

