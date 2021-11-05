#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Delegation/AbstractDelegation.h"

class Referee : public Delegation
{
public:
    Referee() {}
    ~Referee() {}

public:
    virtual Referee* Clone() { return new Referee(*this); }
    double score()
    {
        std::cout << "Referee::score()\n";
        return double(rand() % 100) / 10;
    }

private:
    // make the copy constructor private since we have Clone()
    Referee(const Referee &rhs) {}
};
