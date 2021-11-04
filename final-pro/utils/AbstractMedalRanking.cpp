#include "AbstractMedalRanking.h"
NationMedal::NationMedal(const NationMedal &m)
{
    this->country = m.country;
    this->gold = m.gold;
    this->silver = m.silver;
    this->copper = m.silver;
}
NationMedal &NationMedal::operator=(const NationMedal &m)
{
    this->country = m.country;
    this->gold = m.gold;
    this->silver = m.silver;
    this->copper = m.silver;
    return *this;
}
void NationMedal::setMedal(int g, int s, int c)
{
    gold = g;
    silver = s;
    copper = c;
}

void AbstractMedalRanking::addCountry(string country, int g, int s, int c)
{
    nationList.push_back(new NationMedal(country, g, s, c));
}
void AbstractMedalRanking::setCountryMedal(string country, int g, int s, int c)
{
    for (auto nation : nationList)
    {
        if (nation->country == country)
        {
            nation->setMedal(g, s, c);
            break;
        }
    }
}
void AbstractMedalRanking::sortMedal(int policy)
{
    auto GoldPol = [](const NationMedal *lhs, const NationMedal *rhs) -> bool
    {
        if (lhs->gold > rhs->gold)
            return true;
        else if (lhs->gold == rhs->gold && lhs->silver > rhs->silver)
            return true;
        else if (lhs->gold == rhs->gold && lhs->silver == rhs->silver)
            return lhs->copper > rhs->copper;
        return false;
    };
    auto TotalPol = [](const NationMedal *lhs, const NationMedal *rhs) -> bool
    {
        int lhsTtl = lhs->gold + lhs->silver + lhs->copper;
        int rhsTtl = rhs->gold + rhs->silver + rhs->copper;
        if (lhsTtl > rhsTtl)
            return true;
        else if (lhsTtl == rhsTtl && lhs->gold > rhs->gold)
            return true;
        else if (lhsTtl == rhsTtl && lhs->gold == rhs->gold)
            return lhs->silver > rhs->silver;
        return false;
    };
    switch (policy)
    {
    case PRI_GOLD:
        sort(nationList.begin(), nationList.end(), GoldPol);
        break;
    case PRI_TOTAL:
        sort(nationList.begin(), nationList.end(), TotalPol);
        break;
    default:
        throw runtime_error("Unexpected Policy Type");
    }
}
void AbstractMedalRanking::print()
{
    sortMedal();
    cout << "------------------- Medal Ranking --------------------\n";
    cout << left << setw(7) << "* rank";
    cout << left << setw(11) << "counrry";
    cout << left << setw(9) << "gold";
    cout << left << setw(10) << "silver";
    cout << left << setw(10) << "cooper";
    cout << left << setw(10) << "total *" << endl;
    cout << "------------------------------------------------------\n";

    int rank = 1;
    for (auto nation : nationList)
    {
        cout << "*  " << left << setw(4) << rank++;
        cout << left << setw(12) << nation->country;
        cout << left << setw(9) << nation->gold;
        cout << left << setw(10) << nation->silver;
        cout << left << setw(10) << nation->copper;
        cout << left << setw(5) << nation->gold + nation->silver + nation->copper;
        cout << "*" << endl;
    }
    cout << "------------------------------------------------------\n";
}