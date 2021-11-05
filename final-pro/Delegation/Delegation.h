#pragma once
#include <iostream>
#include <vector>
#include<iomanip>
#include "../Prototype/Prototype.h"
//take diving as example

class Diver : public Delegation
{
public:
    Diver():total(0) {}
    Diver(std::string n) : name(n), total(0) {}
    ~Diver() {}
    double score();
    const std::string& getName() const { return name; }

private:
    double total;
    std::string name;
};
class Referees : public Delegation //Diver delegates this class
{
public:
    static Referees& Instance() //return the instance
    {
        if (!init)
        {
            init = true;
            Referee* proto = new Referee();
            std::cout << "Prototype Referee created.\n";
            instance.RefereeList.push_back(proto);
            for (int i = 0; i != 6; ++i)
            {
                instance.RefereeList.push_back(proto->Clone());
                std::cout << "Referee cloned " << i + 1 << "/6\n";
            }
            std::cout << "Referee creation completed! Scoring..." << std::endl;
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


void testDelegation(); //test
