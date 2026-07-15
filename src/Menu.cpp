#include "iostream"
#include "Menu.h"
#include "Utilities.h"

int Menu::run(){
    
    displayChoice();
    return getValidatedInput(1,4);
}

void Menu::displayChoice(){

    std::cout << "Enter serial number (1-4)\n";
    std::cout << "1. Battle\n";
    std::cout << "2. Pokemon Info\n";
    std::cout << "3. Move Info\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter  number here: ";
}