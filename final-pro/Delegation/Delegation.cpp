#include "Delegation.h"
#include "AbstractDelegation.h"
#include <map>
using namespace std;

bool Referees::init = false;
Referees Referees::instance;

double Referees::score()
{
    double res{};
    double temp[7];
    double max{0}, min{100};
    cout << "Referees::score() delegates Referee::score()\n";
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
    static Referees& instance = Referees::Instance();
    cout << "diver::score() delegates Referees::score()\n";
    for (int i = 0; i != 2; ++i)
        total += 10 * instance.score();
    return total;
}

void testDelegation() //test
{
    Referees::Instance();
    vector<Diver> divers;
    divers.push_back(string("QuanHongchan"));
    divers.push_back(string("WuMinxia"));
    divers.push_back(string("LinYining"));
    srand(time(nullptr));
    map<string, double> DeleRes;
    for (auto &diver : divers)
    {
        cout << diver.getName() << ":\n";
        DeleRes[diver.getName()] = diver.score();
    }
    cout<< "----------------------- Diving ------------------------\n"
        << left << setw(30) << "* name"
        << left << setw(24) << "score" << "*\n"
        << "-------------------------------------------------------\n";
    for (auto diver : DeleRes)
    {
        cout<< "* " << left << setw(28) << diver.first
            << left << setw(24) << diver.second << "*\n";
    }
    cout<< "-------------------------------------------------------\n";
}
