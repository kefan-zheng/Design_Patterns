#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//take diving as example
class Diver
{
public:
    ~Diver(){}
    double score();
private:
    std::vector<double> difficulty;
    double total;
};
class Referees //Diver delegates this class
{
public:
    static Referees &Instance() //return the instance
    {
        static Referees instance;
        return instance;
    }
    double score();
private:
};