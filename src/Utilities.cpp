#include <iostream>
#include "Enums.h"
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include "Utilities.h"

int getValidatedInput(int min, int max){

    while(true){
        
        int num;
        std::cin >> num;
        
        if(!std::cin){

            std::cout << " Invalid Input. Try again. \n\n";
            std::cin.clear();
            std::cin.ignore(10000 , '\n');
            std::cout << " Please enter number (" << min << "-" << max << "): ";
            continue;
        }
        else if( num < min || num > max){
            std::cout << " Invalid number. Try again.\n\n";
            std::cin.ignore(10000 , '\n');
            std::cout << " Please enter number (" << min << "-" << max << "): ";
            continue;
        }
        else{
            std::cin.ignore(10000 , '\n');
            return num;
        }
    }
}

int randomInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void printEqualSign(int width)
{
    std::cout << std::string(width, '=') << "\n";
}

void printCentered(const std::string& text, int width)
{
    int padding = (width - text.length()) / 2;
    std::cout << std::string(padding, ' ') << text << '\n';
}

std::string typeToString(Type type)
{
    switch (type)
    {
        case NORMAL:    return "Normal";
        case ELECTRIC:  return "Electric";
        case FIRE:      return "Fire";
        case WATER:     return "Water";
        case GRASS:     return "Grass";
        case ROCK:      return "Rock";
        case PSYCHIC:   return "Psychic";
        case FIGHTING:  return "Fighting";
        case GHOST:     return "Ghost";
        case DRAGON:    return "Dragon";
        case ICE:       return "Ice";
        case GROUND:    return "Ground";
        case FLYING:    return "Flying";
        case POISON:    return "Poison";
        case DARK:      return "Dark";
        case STEEL:     return "Steel";
        default:        return "Unknown";
    }
}

std::string statusToString(Status status)
{
    switch(status)
    {
        case NONE     :  return "None";
        case BURNED   :  return "Burned";
        case POISONED :  return "Poisoned";
        default       :  return "Unkown";
    }
}

void screenTitle(std::string text)
{
    printEqualSign(80);
    std::cout << "\n";
    printCentered(text, 80); //Length is hardcoded 50 because I have decided to be the standard length of at least pokemon v4.
    std::cout << "\n";
    printEqualSign(80);
}\

void clearScreen() 
{
    // Called twice because some Windows terminals retain one frame
    // in the scrollback after a single ANSI clear sequence.
    std::cout << "\033[3J\033[2J\033[H" << std::flush;
    std::cout << "\033[3J\033[2J\033[H" << std::flush;
}

void animatedText(const std::string& text, int delay)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
