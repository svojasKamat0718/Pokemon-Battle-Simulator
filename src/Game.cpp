#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "Battle.h"
#include "Pokemon.h"
#include "PokemonData.h"
#include "CombatMove.h"
#include "MoveData.h"
#include "Utilities.h"
#include <windows.h>

void Game::run()
{

    Menu menu;
    int choice;
    
    Pokemon playerPokemon;
    Pokemon botPokemon;
    
    do{
        choice = menu.run();
        clearScreen();

        switch (choice)
        {   
            case 1:
                {
                screenTitle("Pokemon Selection Menu");
                std::cout << "\n Choose your pokemon!\n\n";
                playerPokemon = selectPokemon();
                std::cout << "\n You are " << playerPokemon.name << "!";
                Sleep(2000);
                clearScreen();
                
                screenTitle("Pokemon Selection Menu");
                std::cout << "\n Choose your opponent!\n\n";
                botPokemon = selectPokemon();
                std::cout << "\n Your opponent is " << botPokemon.name <<  "!";
                Sleep(2000);
                clearScreen();
                break;
                }
            case 2:
                Pokemon::displayPokemonInfo();
                clearScreen();
                break;
        
            case 3:
                //Move Info...
                // I am skipping this for now.
                //I'll complete this feature later.
                break;

            case 4:
                std::cout << "Thank you for playing!\n";
                return;
        }
    }while (choice != 1);

    do{
        choice = getBotDifficulty();
        std::cout << "\n";

        switch(choice){
            case 0:
                botDifficultyInfo();
                choice = getValidatedInput(0, 0);
                clearScreen();
                break;
            
            case 1:
                botPokemon.maxHP = 0.75 * botPokemon.maxHP;
                botPokemon.currentHP = 0.75 * botPokemon.currentHP;
                std::cout << " Difficulty was set to Easy\n";
                break;

            case 3:
                botPokemon.maxHP = 1.5 * botPokemon.maxHP;
                botPokemon.currentHP = 1.5 * botPokemon.currentHP;
                std::cout << " Difficulty was set to Hard\n";
                break;
            
            default:
                std::cout << " Difficulty was set to Normal\n";
                break;

        }
        Sleep(2000);
        clearScreen();
        }while(choice == 0);// I am using the same "choice" variable because user input will never overlap for 2 different tasks.
                            // If that's a bad industry practice, I will modify it. Just say so.

    Battle battle(&playerPokemon, &botPokemon);

    battle.run();

}

Pokemon Game::selectPokemon(){

    while(true){
        Pokemon::displayPokemon();
        std::cout << " 11. Random pokemon\n";
        std::cout << " 0.  Pokemon Info\n\n";
        std::cout << " Enter number here: ";
        int choice = getValidatedInput(0,11);

        switch(choice)
        {
            case 11:  
                return pokemonPool[randomInt(0,9)];
            
            case 0:
                clearScreen();
                Pokemon::displayPokemonInfo();
                clearScreen();
                break;

            default:
                return pokemonPool[choice - 1];
        }        
    }   
}

int Game::getBotDifficulty(){

    screenTitle("Bot Difficulty Selection Menu");

    std::cout << "\n Select bot difficulty\n\n";
    std::cout << " 1. Easy\n";
    std::cout << " 2. Normal\n";
    std::cout << " 3. Hard\n\n";
    std::cout << " 0. Difficulty modifier info\n";
    std::cout << " ";
    
    return getValidatedInput(0, 3);
}

void Game::botDifficultyInfo(){

    screenTitle("Difficulty Modifier Info Menu");
    
    std::cout << " Easy:\n";
    std::cout << "   1. Opponent's HP will be decreased by 25%.\n";
    std::cout << "   2. Chance of each move:\n";
    std::cout << "          Best move     : 20%\n";
    std::cout << "          2nd best move : 30%\n";
    std::cout << "          3rd best move : 50%\n\n";
    
    std::cout << " Normal:\n";
    std::cout << "   1. Opponent's HP will be same as shown in info menu.\n";
    std::cout << "   2. Chance of each move:\n";
    std::cout << "          Best move     : 50%\n";
    std::cout << "          2nd best move : 30%\n";
    std::cout << "          3rd best move : 20%\n\n";

    std::cout << " Hard:\n";
    std::cout << "   1. Opponent's HP will be increased by 50%.\n";
    std::cout << "   2. Chance of each move:\n";
    std::cout << "          Best move     : 80%\n";
    std::cout << "          2nd best move : 15%\n";
    std::cout << "          3rd best move : 05%\n\n";

    std::cout << " Enter 0 to return.\n";
    std::cout << " \n";
}