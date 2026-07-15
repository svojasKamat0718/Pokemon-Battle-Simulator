#pragma once
#include <iostream>
#include <CombatMove.h>

class Pokemon {
    public:
        std::string name;
        Type type;

        int currentHP{};
        int maxHP{};

        int attack{};
        int defence{};
        int spAttack{};
        int spDefence{};

        Status status = NONE;

        CombatMove moves[4];
    
    Pokemon(std::string name, Type type, 
            int hp,
            int attack, int defence, int spAttack, int spDefence,
            Status status,
            CombatMove m1, CombatMove m2, CombatMove m3, CombatMove m4)
    {
        this->name = name;
        this->type = type;
        this->currentHP = hp;
        this->maxHP = hp;
        this->attack = attack;
        this->defence = defence;
        this->spAttack = spAttack;
        this->spDefence = spDefence;
        moves[0] = m1;
        moves[1] = m2;
        moves[2] = m3;
        moves[3] = m4;
    }

    Pokemon() = default;
};