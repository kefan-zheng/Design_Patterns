#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Referee
{
public:
    Referee() {}
    ~Referee() {}

public:
    virtual Referee* Clone() { return new Referee(*this); }
    double score()
    {
        return double(rand() % 100) / 10;
    }

private:
    // make the copy constructor private since we have Clone()
    Referee(const Referee &rhs) {}
};