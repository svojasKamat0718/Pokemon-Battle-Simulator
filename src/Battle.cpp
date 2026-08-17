#include <algorithm>
#include <iostream>
#include <windows.h>
#include "Battle.h"
#include "Pokemon.h"
#include "Utilities.h"

void Battle::run(){

    while(true){
        playerTurn();
        if(battleOver()){
            std::cout << "Player Wins!\n";
            return;
            //This is temporary win message. I will change it once I get everything working.
        }

        botTurn();
        if(battleOver()){
            std::cout << "Bot Wins!\n";
            return;
        }
    }

}

void Battle::playerTurn(){

    displayBattle();

    printCentered("Player's Turn", 80);
    std::cout << "\n";

    CombatMove *playerMove = getPlayerMove();
    Sleep(2000);
    clearScreen();

    executeMove(playerPokemon, "Player", playerMove, botPokemon);
    
}

void Battle::botTurn(){
    
    return;
}

bool Battle::battleOver(){
    
    return false;
}

bool Battle::isFainted(){
    
    return false;
}

int Battle::calculateDamage(){

    return 0;
}

CombatMove* Battle::getPlayerMove(){

    std::cout << " Select Move(1-4):\n\n";

    for (int i = 0; i < 4; i++){

        std::cout << " " << i+1 << ". " << playerPokemon->moves[i].name << " (PP: " << playerPokemon->moves[i].PP << "/" << playerPokemon->moves[i].maxPP << ")\n\n";
    }
    
    std::cout << " Enter Number here: ";

    return &playerPokemon->moves[getValidatedInput(1,4) - 1];
}

void Battle::displayHPBar(Pokemon *pokemon){

    double pokemonHP = pokemon->currentHP;
    double pokemonMaxHP = pokemon->maxHP;

    int pokemonHPBlocks = ceil((pokemonHP / pokemonMaxHP) * 50);

    std::cout << pokemon->name << " [Status: " << statusToString(pokemon->status) << " ]" << "\n";
    std::cout << "HP [" << std::string(pokemonHPBlocks , 'X') << std::string(50-pokemonHPBlocks , '-') << "] " << pokemonHP << "/" << pokemonMaxHP << "\n\n";
}

void Battle::displayBattle(){
    
    printEqualSign(80);
    std::cout << "\n";
    displayHPBar(botPokemon);

    printCentered("VS", 50);
    std::cout << "\n";
    
    displayHPBar(playerPokemon);
    printEqualSign(80);

    std::cout << "\n";
}

void Battle::executeMove(Pokemon *attacker, std::string attackerLabel, CombatMove *move, Pokemon *defender){

    screenTitle("Battle");
    std::cout << "\n";
    printCentered(attackerLabel + "'s Turn", 80);
    std::cout << "\n";
    
    animatedText(" " + attacker->name + " used " + move->name + "\n", 25);
    Sleep(2000);

    if(!CombatMove::checkPP(move)){
        return;
    }
    move->PP--;

    if(!moveHits(attacker->name, move)){
        return;
    }

    switch(move->category)
    {
        case PHYSICAL:
            
            break;
        
        case SPECIAL:
            break;
        
        case STATUS:
            applyEffect(attacker, move, defender);
            break;
    }//Randomint generator may not be working properly. Check if it is producing same random nums on different builds.

    Sleep(3000);
    clearScreen();
}

bool Battle::moveHits(std::string name, CombatMove *move){

    if(move->accuracy < randomInt(1,100)){

        animatedText(" " + name + "'s attack missed!", 25);
        std::cout << "\n";
        Sleep(2000);
        clearScreen();
        return false;
    }

    return true;
}

int Battle::calculateNormalDamage(CombatMove *move)
{
    
    return 0;
}

int Battle::calculateSpecialDamage(CombatMove *move)
{
    
    return 0;
}

double Battle::stageMultiplier(int stage)
{
    if (stage >= 0)
    {
        return (2.0 + stage) / 2.0;
    }

    return 2.0 / (2.0 - stage);
}

void Battle::applyEffect(Pokemon *attacker, CombatMove *move, Pokemon *defender){

    switch(move->effect)
    {
        case BURN_EFFECT:
            if (defender->status != NONE){
                animatedText(" but it failed!\n", 25);
                return;
            }
        
            if (move->effectChance >= randomInt(1, 100)){
                defender->status = BURNED;
                animatedText(" " + defender->name + " was burned!\n", 25);

            }
            break;

        case POISON_EFFECT:
            
            if (defender->status != NONE){
                animatedText(" but it failed!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1,100)){
                defender->status = POISONED;
                animatedText(" " + defender->name + " was poisoned!\n", 25);
            }
            break;

        case ATTACK_UP:
            
            if (attacker->attackStage == 6){
                animatedText(" " + attacker->name + "'s Attack won't go any higher!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                attacker->attackStage++;
                animatedText(" " + attacker->name + "'s Attack rose!\n", 25);
            }
            break;

        case ATTACK_DOWN:
            
            if (defender->attackStage == -6){
                animatedText(" " + defender->name + "'s Attack won't go any lower!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                defender->attackStage--;
                animatedText(" " + defender->name + "'s Attack fell!\n", 25);
            }
            break;
    
        case DEFENCE_UP:
            
            if (attacker->defenceStage == 6){
                animatedText(" " + attacker->name + "'s Defence won't go any higher!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                attacker->defenceStage++;
                animatedText(" " + attacker->name + "'s Defence rose!\n", 25);
            }
            break;
        
        case DEFENCE_DOWN:
            
            if (defender->defenceStage == -6){
                animatedText(" " + defender->name + "'s Defence won't go any lower!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                defender->defenceStage--;
                animatedText(" " + defender->name + "'s Defence fell!\n", 25);
            }
            break;
        
        case SP_ATTACK_UP:
            
            if (attacker->spAttackStage == 6){
                animatedText(" " + attacker->name + "'s Sp. Atk won't go any higher!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                attacker->spAttackStage++;
                animatedText(" " + attacker->name + "'s Sp. Atk rose!\n", 25);
            }
            break;

        case SP_ATTACK_DOWN:
            
            if (defender->spAttackStage == -6){
                animatedText(" " + defender->name + "'s Sp. Atk won't go any lower!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                defender->spAttackStage--;
                animatedText(" " + defender->name + "'s Sp. Atk fell!\n", 25);
            }
            break;

        case SP_DEFENCE_UP:
            
            if (attacker->spDefenceStage == 6){
                animatedText(" " + attacker->name + "'s Sp. Def won't go any higher!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                attacker->spDefenceStage++;
                animatedText(" " + attacker->name + "'s Sp. Def rose!\n", 25);
            }
            break;

        case SP_DEFENCE_DOWN:
            
            if (defender->spDefenceStage == -6){
                animatedText(" " + defender->name + "'s Sp. Def won't go any lower!\n", 25);
                return;
            }

            if (move->effectChance >= randomInt(1, 100)){
                defender->spDefenceStage--;
                animatedText(" " + defender->name + "'s Sp. Def fell!\n", 25);
            }
            break;

        default: return;
    }

}

