#include <iostream>
#include "Menu.h"
#include "Utilities.h"

int Menu::run(){
    
    displayChoice();
    return getValidatedInput(1,4);
}

void Menu::displayChoice(){

    screenTitle("Menu");

    std::cout << "\n";
    std::cout << " Enter serial number (1-4)\n\n";
    std::cout << " 1. Battle\n";
    std::cout << " 2. Pokemon Info\n";
    std::cout << " 3. Move Info\n";
    std::cout << " 4. Exit\n\n";
    std::cout << " Enter number here: ";
}