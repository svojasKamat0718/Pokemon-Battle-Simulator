#pragma once
#include <iostream>
#include "Enums.h"
 
class CombatMove {
    public:
    std::string name;
    Type type;
    int power{};
    int accuracy{};
    int PP{};
    int maxPP{};
    MoveCategory category;
    MoveEffect effect;
    int effectChance;
    
    CombatMove(std::string name, Type type , int power , int accuracy , int PP, MoveCategory category, MoveEffect effect, int effectChance){
        
        this->name = name;
        this->type = type;
        this->power = power;
        this->accuracy = accuracy;
        this->PP = PP; 
        this->maxPP = PP;
        this->category = category;
        this->effect = effect;
        this->effectChance = effectChance;
    }

    CombatMove() = default;
};