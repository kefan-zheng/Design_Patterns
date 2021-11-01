#pragma once
#include <iostream>
#include <vector>
#include<iomanip>
#include "Prototype.h"
//take diving as example
class Diver
{
public:
    Diver() {}
    Diver(std::string n) : name(n) {}
    ~Diver() {}
    double score();
    const std::string& getName() { return name; }

private:
    double total;
    std::string name;
};
class Referees //Diver delegates this class
{
public:
    static Referees& Instance() //return the instance
    {
        if (!init)
        {
            init = true;
            Referee* proto = new Referee();
            instance.RefereeList.push_back(proto);
            for (int i = 0; i != 6; ++i)
                instance.RefereeList.push_back(proto->Clone());
        }
        return instance;
    }
    double score();

private:
    static bool init;
    static Referees instance;
    std::vector<Referee* > RefereeList;
    Referees() = default;
    Referees(const Referees& m) = delete;
    Referees &operator=(const Referees& m) = delete;
};
bool Referees::init = false;
Referees Referees::instance;