#include <iostream>
#include "Battle.h"
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

    std::cout << "Select Move(1-4):\n";
    for (int i = 0; i < 4; i++){

        std::cout << i+1 << ". " << playerPokemon->moves[i].name << "\n";
    }
    
    int moveNum = getValidatedInput(1,4);

    
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