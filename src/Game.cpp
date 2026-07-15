#include <iostream>
#include "Game.h"
#include "Menu.h"
//#include "Battle.h"
//#include "Pokemon.h"
//#include "CombatMove.h"
#include "Utilities.h"

void Game::run(){

    Menu menu;
    int choice = menu.run();  
    
    switch (choice)
    {   
        case 1:
            //Battle Starts...
            break;
        
        case 2:
            //Pokemon Info...
            break;
    
        case 3:
            //Move Info...
            break;

        case 4:
            std::cout << "Thank you for playing!\n";
            break;
    }
}