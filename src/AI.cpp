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
                
                //Estimate damage calc for normal attack.
                if (Moves[i].category == 0){
                    estimateDamage =  Moves[i].power 
                               * ((bot->attack
                               * stageMultiplier(bot->attackStage))
                               / (player->defence
                               * stageMultiplier(player->defenceStage)));
                }

                //Estimate damage calc for special attack.
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

                //checking type advandage.
                float typeMultiplier = Battle::getTypeMultiplier(&Moves[i], player->type);

                if (typeMultiplier == 2.0) {
                    Moves[i].moveScore += 30;
                }
                else if (typeMultiplier == 0.5) {
                    Moves[i].moveScore -= 30;
                }
                else if (typeMultiplier == 0){
                    Moves[i].moveScore -= 50;
                }

                //checking stab.
                float StabMultiplier = Battle::getSTAB_Multiplier(bot, &Moves[i]);

                if (StabMultiplier == 1.5) {
                    Moves[i].moveScore += 20;
                }
            }

            else if (Moves[i].power == 0) { // Checking Atk, Def, SpAtk, SpDef stage here. Atk for bot, Def for player.

                // checking attack stage of bot:
                if (Moves[i].effect == ATTACK_UP) {

                    if (bot->attackStage >= 0) {
                        Moves[i].moveScore += (6 - bot->attackStage) * 10;
                    }
                    else {
                        Moves[i].moveScore += 90 + (-bot->attackStage - 1) * 15;
                    }
                }

                // checking attack stage of player:
                else if (Moves[i].effect == ATTACK_DOWN) {

                    if (player->attackStage >= 0) {
                        Moves[i].moveScore += 60 + player->attackStage * 15;
                    }
                    else {
                        Moves[i].moveScore += (-player->attackStage) * 10;
                    }
                }

                // checking defence stage of bot:
                else if (Moves[i].effect == DEFENCE_UP) {

                    if (bot->defenceStage >= 0) {
                        Moves[i].moveScore += (6 - bot->defenceStage) * 10;
                    }
                    else {
                        Moves[i].moveScore += 90 + (-bot->defenceStage - 1) * 15;
                    }
                }

                // checking defence stage of player:
                else if (Moves[i].effect == DEFENCE_DOWN) {

                    if (player->defenceStage >= 0) {
                        Moves[i].moveScore += 60 + player->defenceStage * 15;
                    }
                    else {
                        Moves[i].moveScore += (-player->defenceStage) * 10;
                    }
                }

                // checking sp atk stage of bot:
                else if (Moves[i].effect == SP_ATTACK_UP) {

                    if (bot->spAttackStage >= 0) {
                        Moves[i].moveScore += (6 - bot->spAttackStage) * 10;
                    }
                    else {
                        Moves[i].moveScore += 90 + (-bot->spAttackStage - 1) * 15;
                    }
                }

                // checking sp atk stage of player:
                else if (Moves[i].effect == SP_ATTACK_DOWN) {

                    if (player->spAttackStage >= 0) {
                        Moves[i].moveScore += 60 + player->spAttackStage * 15;
                    }
                    else {
                        Moves[i].moveScore += (-player->spAttackStage) * 10;
                    }
                }

                // checking sp def stage of bot:
                else if (Moves[i].effect == SP_DEFENCE_UP) {

                    if (bot->spDefenceStage >= 0) {
                        Moves[i].moveScore += (6 - bot->spDefenceStage) * 10;
                    }
                    else {
                        Moves[i].moveScore += 90 + (-bot->spDefenceStage - 1) * 15;
                    }
                }

                // checking sp def stage of player:
                else if (Moves[i].effect == SP_DEFENCE_DOWN) {

                    if (player->spDefenceStage >= 0) {
                        Moves[i].moveScore += 60 + player->spDefenceStage * 15;
                    }
                    else {
                        Moves[i].moveScore += (-player->spDefenceStage) * 10;
                    }
                }
            }

            //Evaluating moves with status effects as secondary effect:
            if (Moves[i].effect == POISON_EFFECT || Moves[i].effect == BURN_EFFECT){

                if(player->status == POISONED || player->status == BURNED){
                    
                    Moves[i].moveScore += 0;
                }

                else if ((player->currentHP*100.0/player->maxHP) >= 75){

                    if (Moves[i].effectChance >= 90) 
                    {
                        Moves[i].moveScore += 50;
                    }
                    else if (Moves[i].effectChance >= 50)
                    {
                        Moves[i].moveScore += 25;
                    }
                    else
                    {
                        Moves[i].moveScore += 15;
                    }  
                }
            }
        }
    
    return 0;
}

CombatMove *getBotMove(CombatMove availableMoves[], int moveCount)
{
    int bestMoveIndex = 0;

    for (int i = 1; i < moveCount; i++)
    {
        if (availableMoves[i].moveScore > availableMoves[bestMoveIndex].moveScore)
        {
            bestMoveIndex = i;
        }
    }

    return &availableMoves[bestMoveIndex];
}
