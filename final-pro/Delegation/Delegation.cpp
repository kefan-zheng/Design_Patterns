#include "Delegation.h"
using namespace std;

bool Referees::init = false;
Referees Referees::instance;

double Referees::score()
{
    double res{};
    double temp[7];
    double max{0}, min{100};
    for (int i = 0; i != 7; ++i)
    {
        temp[i] = RefereeList[i]->score();
        max = (max > temp[i]) ? max : temp[i];
        min = (min < temp[i]) ? min : temp[i];
        res += temp[i];
    }
    return (res - max - min) * 3 / 5;
}
double Diver::score() //difficulty all set 2.0
{
    Referees& instance = Referees::Instance();
    for (int i = 0; i != 10; ++i)
        total += 2.0 * instance.score();
    return total;
}

void testDelegation() //test
{
    vector<Diver> divers;
    divers.push_back(string("QuanHongchan"));
    divers.push_back(string("WuMinxia"));
    divers.push_back(string("LinYining"));
    srand(time(nullptr));
    cout<< "----------------------- Diving ------------------------\n"
        << left << setw(30) << "* name"
        << left << setw(24) << "score" << "*\n"
        << "-------------------------------------------------------\n";
    for (auto diver : divers)
    {
        cout<< "* " << left << setw(28) << diver.getName()
            << left << setw(24) << diver.score() << "*\n";
    }
    cout<< "-------------------------------------------------------\n";
}
