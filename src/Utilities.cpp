#include <Utilities.h>
#include <iostream>

int getValidatedInput(int min, int max){

    while(true){
        
        int num;
        std::cin >> num;
        
        if(!std::cin){

            std::cout << "Invalid Input. Try again. \n\n";
            std::cin.clear();
            std::cin.ignore(10000 , '\n');
            std::cout << "Please enter number (" << min << "-" << max << "): ";
            continue;
        }
        else if( num < min || num > max){
            std::cout << "Invalid number. Try again.\n\n";
            std::cin.ignore(10000 , '\n');
            std::cout << "Please enter number (" << min << "-" << max << "): ";
            continue;
        }
        else{
            std::cin.ignore(10000 , '\n');
            return num;
        }
    }
}