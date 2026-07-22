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

void Game::run(){

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
                continue;
        
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
