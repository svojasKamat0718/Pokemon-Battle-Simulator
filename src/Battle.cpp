#include <algorithm>
#include <iostream>
#include <windows.h>
#include <cmath>
#include "Battle.h"
#include "Pokemon.h"
#include "Utilities.h"
double damageRoll();

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

int Battle::calculateDamage(Pokemon *attacker, CombatMove *move, Pokemon *defender, double criticalMultiplier)
{   
    float effAtk = attacker->attack * stageMultiplier(attacker->attackStage);
    float effDef = defender->defence * stageMultiplier(defender->defenceStage);
    float effSpAtk = attacker->spAttack * stageMultiplier(attacker->spAttackStage);
    float effSpDef = defender->spDefence * stageMultiplier(defender->spDefenceStage);
    float baseDamage;

    if (move->category == PHYSICAL){
        
        baseDamage = (move->power * effAtk/effDef)
                     * getSTAB_Multiplier(attacker, move)
                     * getTypeMultiplier(move, defender->type)
                     * damageRoll()
                     * criticalMultiplier;
    }

    else if (move->category == SPECIAL){

        baseDamage = (move->power * effSpAtk/effSpDef)
                     * getSTAB_Multiplier(attacker, move)
                     * getTypeMultiplier(move, defender->type)
                     * damageRoll()
                     * criticalMultiplier;
    }
    baseDamage = floor(baseDamage);
    
    return baseDamage;
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

    int defenderOldHP = defender->currentHP;

    screenTitle("Battle");
    std::cout << "\n";
    printCentered(attackerLabel + "'s Turn", 80);
    std::cout << "\n";
    
    animatedText(" " + attacker->name + " used " + move->name + "\n", 25);
    Sleep(1000);

    if(!CombatMove::checkPP(move)){
        return;
    }
    move->PP--;

    if(!moveHits(attacker->name, move)){
        return;
    }

    switch(move->category)
    {
        case STATUS:
            {
            applyEffect(attacker, move, defender);
            break;
            }
        
        default:
            {
            double criticalMultiplier = getCriticalHit(); 
            int damage = calculateDamage(attacker, move, defender, criticalMultiplier);
            
            if(criticalMultiplier != 1){
                animatedText(" A critical hit!\n", 25);
            }

            displayTypeMessage(getTypeMultiplier(move, defender->type), defender);

            defender->currentHP -= damage;

            animatedText(" " + defender->name + " took " + std::to_string(damage) + " damage!\n", 25);

            Sleep(3000);
            clearScreen();

            animateHP(defender, defenderOldHP);
            break;
            }  
    }

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

double Battle::getSTAB_Multiplier(Pokemon *attacker , CombatMove *move){

    if (attacker->type == move->type){
        return 1.5;
    }
    return 1;
}

double Battle::getTypeMultiplier(CombatMove *move , Type defenderType){

    switch(move->type){
        
        case NORMAL:
            if(defenderType == ROCK || defenderType == STEEL){
                return 0.5;
            }
            else if(defenderType == GHOST){
                return 0;
            }
            return 1.0;

        case ELECTRIC:
            if(defenderType == WATER || defenderType == FLYING){
                return 2.0;
            }
            else if(defenderType == GRASS || defenderType == DRAGON || defenderType == ELECTRIC){
                return 0.5;
            }
            else if(defenderType == GROUND){
                return 0;
            }
            return 1.0;

        case FIRE:
            if(defenderType == GRASS || defenderType == ICE || defenderType == STEEL){
                return 2;
            }
            else if(defenderType == WATER || defenderType == ROCK || defenderType == DRAGON || defenderType == FIRE){
                return 0.5;
            }
            return 1.0;

        case WATER:
            if(defenderType == FIRE || defenderType == ROCK || defenderType == GROUND){
                return 2.0;
            }
            else if(defenderType == GRASS || defenderType == DRAGON || defenderType == WATER){
                return 0.5;
            }
            return 1.0;

        case GRASS:
            if(defenderType == WATER || defenderType == ROCK || defenderType == GROUND){
                return 2.0;
            }
            else if(defenderType == FIRE || defenderType == DRAGON || defenderType == GRASS || defenderType == POISON || defenderType == STEEL || defenderType == FLYING){
                return 0.5;
            }
            return 1.0;

        case ROCK:
            if(defenderType == FIRE || defenderType == ICE || defenderType == FLYING){
                return 2.0;
            }
            else if(defenderType == FIGHTING || defenderType == GROUND || defenderType == STEEL){
                return 0.5;
            }
            return 1.0;

        case PSYCHIC:
            if(defenderType == FIGHTING || defenderType == POISON){
                return 2.0;
            }
            else if(defenderType == PSYCHIC|| defenderType == STEEL){
                return 0.5;
            }
            else if (defenderType == DARK){
                return 0;
            }
            return 1.0;

        case FIGHTING:
            if(defenderType == ROCK || defenderType == NORMAL || defenderType == DARK || defenderType == STEEL || defenderType == ICE){
                return 2.0;
            }
            else if(defenderType == PSYCHIC || defenderType == FLYING || defenderType == POISON){
                return 0.5;
            }
            else if (defenderType == GHOST){
                return 0;
            }
            return 1.0;

        case GHOST:
            if(defenderType == PSYCHIC || defenderType == GHOST){
                return 2.0;
            }
            else if(defenderType == DARK){
                return 0.5;
            }
            else if (defenderType == NORMAL){
                return 0;
            }   
            return 1.0;

        case DRAGON:
            if(defenderType == DRAGON){
                return 2.0;
            }
            else if(defenderType == STEEL){
                return 0.5;
            }
            return 1.0;

        case ICE:
            if(defenderType == GRASS || defenderType == GROUND || defenderType == FLYING || defenderType == DRAGON){
                return 2.0;
            }
            else if(defenderType == FIRE || defenderType == WATER || defenderType == ICE || defenderType == STEEL){
                return 0.5;
            }
            return 1.0;

        case GROUND:
            if(defenderType == FIRE || defenderType == ROCK || defenderType == ELECTRIC || defenderType == STEEL || defenderType == POISON){
                return 2.0;
            }
            else if(defenderType == GRASS){
                return 0.5;
            }
            else if(defenderType == FLYING){
                return 0;
            }
            return 1.0;

        case FLYING:
            if(defenderType == GRASS || defenderType == FIGHTING){
                return 2.0;
            }
            else if (defenderType == ROCK || defenderType == STEEL || defenderType == ELECTRIC){
                return 0.5;
            }
            return 1;

        case POISON:
            if(defenderType == GRASS){
                return 2.0;
            }
            else if(defenderType == POISON || defenderType == GROUND || defenderType == GHOST || defenderType == ROCK){
                return 0.5;
            }
            else if(defenderType == STEEL){
                return 0;
            }
            return 1;

        case DARK:
            if(defenderType == GHOST || defenderType == PSYCHIC){
                return 2.0;
            }
            else if(defenderType == FIGHTING || defenderType == DARK){
                return 0.5;
            }
            return 1;
        
        case STEEL:
            if(defenderType == ROCK || defenderType == ICE){
                return 2.0;
            }
            else if(defenderType == FIRE || defenderType == WATER || defenderType == ELECTRIC || defenderType == STEEL){
                return 0.5;
            }
            return 1.0;

        default:
            std::cout << "Error: Unknown attacker type.\n";
            return 1.0;
    }
}

double Battle::getCriticalHit(){
    
    if(randomInt(1,100) == 1){
        return 1.5;
    }

    return 1;
}

double damageRoll(){
    return randomInt(85,100)/100.0;
}

void Battle::displayTypeMessage(double multiplier , Pokemon *pokemon){
    
    Sleep(2000);
    if(multiplier == 2){
        animatedText(" It's super effective!\n", 25);
    }
    else if(multiplier == 0.5){
        animatedText(" It's not  very effective...\n", 25);
    }
    else if(multiplier == 0){
        animatedText(" It doesn't affect " + pokemon->name + "...\n", 25);
        
    }
}

void Battle::animateHP(Pokemon* pokemon, double oldHP){

    double finalHP = pokemon->currentHP;
    pokemon->currentHP = oldHP;

    while(pokemon->currentHP > finalHP){
        pokemon->currentHP -= 20;
        if (pokemon->currentHP < finalHP)
            pokemon->currentHP = finalHP;
        displayBattle();
        Sleep(500);
        clearScreen();
    }
}
