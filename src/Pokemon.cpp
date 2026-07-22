#include <iostream>
#include "Pokemon.h"
#include "PokemonData.h"
//#include "MoveData.h"
#include "Utilities.h"

void Pokemon::displayPokemon()
{
    for(int i = 0; i < pokemonPoolSize; i++)
    {
        std::cout << " " << i+1 << ". " << pokemonPool[i].name << "\n";
    }
}

void Pokemon::displayPokemonInfo()
{   
    int choice{};

    do{
    screenTitle("Pokemon Info Menu");
    std::cout << "\n Select pokemon to view info of or enter '0' to exit.\n\n";

    displayPokemon();

    choice = getValidatedInput(0,10);

    if (choice == 0){
        break;
    }
    
    clearScreen();
    screenTitle(pokemonPool[choice -1].name);
    std::cout << "\n";

    std::cout << " Name : " << pokemonPool[choice - 1].name << "\n";
    std::cout << " Type : " << typeToString(pokemonPool[choice - 1].type) << "\n";
    std::cout << " HP   : " << pokemonPool[choice - 1].maxHP << "\n\n";
    
    std::cout << "  MOVES\n";
    std::cout << " _______\n\n";

    for (int i = 0; i < 4; i++){
        std::cout << " " << i+1 << ". " << pokemonPool[choice - 1].moves[i].name << "\n"; 
    }
    std::cout << "\n\n";
    printEqualSign();
    std::cout << "\n";
    
    std::cout << "Enter '0' to return\n";
    int tempChoice = getValidatedInput(0,0);
    clearScreen();
    }while (choice != 0);
}
