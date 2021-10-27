#include <iostream>
#include <string>
#include <map>
#define GOLD_MEDAL 0
#define SILVER_MEDAL 1
#define BRONZE_MEDAL 2
#define PRI_TOTAL 0
#define PRI_GOLD 1

/*
 * Singleton
 * The Medal Table as a Singleton to store medals of all countries
 */
struct Medal
{
    int gold = 0;
    int silver = 0;
    int bronze = 0;
    int total = 0;
};

class MedalTable
{
public:
    static MedalTable &Instance() //return the instance
    {
        static MedalTable instance;
        return instance;
    }
    void update(std::string country,int type); //update the table
    void show(int policy); //show the table

private:
    std::map<std::string, Medal> mMedal;
    MedalTable() = default; //disable creation outside the class
    ~MedalTable() = default;
    MedalTable(const MedalTable &) = default;
    MedalTable &operator=(const MedalTable &) = default;
};