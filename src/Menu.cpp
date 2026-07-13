#include <iostream>
#include <Menu.h>
#include <Battle.h>
#include <Utilities.h>

int Menu::runMenu(){
    
    displayChoice();
    return getValidatedInput(1,2);
}

void Menu::displayChoice(){

    std::cout << "Enter serial number (1-2)\n";
    std::cout << "1.Battle\n";
    std::cout << "2.Exit\n";
    std::cout << "Enter  number here: ";
}

