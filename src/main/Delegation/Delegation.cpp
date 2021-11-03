#include "Delegation.h"

double Referees::score()
{
    double res{};
    double temp[7];
    double max{0}, min{100};
    srand(time(nullptr));
    for (int i = 0; ++i; i != 7)
    {
        temp[i] = double(rand() % 100) / 10;
        max = max > temp[i] ? max : temp[i];
        min = min < temp[i] ? min : temp[i];
        res += temp[i];
    }
    return (res - max - min) * 3 / 5;
}
double Diver::score() //difficulty all set 2.0
{
    for (int i = 0; i != 10; ++i)
        total += 2.0 * Referees::Instance().score();
    return total;
}