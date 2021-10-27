#include "MedalTable.h"
#include <vector>
#include <algorithm>
/*
 * @param country the country to win a medal
 * @param type the type of the medal won
 */
void MedalTable::update(std::string country, int type) 
{
    Medal &medal = mMedal[country];
    switch (type)
    {
    case GOLD_MEDAL:
        medal.gold++;
        break;
    case SILVER_MEDAL:
        medal.silver++;
        break;
    case BRONZE_MEDAL:
        medal.bronze++;
        break;
    default:
        throw std::runtime_error("Unexpected Medal Type");
    }
    medal.total++;
}
/*
 * @param policy to show the table in which priority, gold or total
 */
void MedalTable::show(int policy)
{
    auto GoldPol = [](const std::pair<std::string, Medal> &lhs, const std::pair<std::string, Medal> &rhs) -> bool
    {
        if (lhs.second.gold > rhs.second.gold)
            return true;
        else if (lhs.second.gold == rhs.second.gold && lhs.second.silver > rhs.second.silver)
            return true;
        else if (lhs.second.gold == rhs.second.gold && lhs.second.silver == rhs.second.silver)
            return lhs.second.bronze > rhs.second.bronze;
        return false;
    };
    auto TotalPol = [](const std::pair<std::string, Medal> &lhs, const std::pair<std::string, Medal> &rhs) -> bool
    {
        if (lhs.second.total > rhs.second.total)
            return true;
        else if (lhs.second.total == rhs.second.total && lhs.second.gold > rhs.second.gold)
            return true;
        else if (lhs.second.total == rhs.second.total && lhs.second.gold == rhs.second.gold)
            return lhs.second.silver > rhs.second.silver;
        return false;
    };
    std::vector<std::pair<std::string, Medal>> table;
    for (auto entry : mMedal)
        table.push_back(entry);
    switch(policy)
    {
    case PRI_GOLD:
        std::sort(table.begin(), table.end(), GoldPol);
        break;
    case PRI_TOTAL:
        std::sort(table.begin(), table.end(), TotalPol);
        break;
    default:
        throw std::runtime_error("Unexpected Policy Type");
    }
    std::cout<<"Country\tGold\tSilver\tBronze\tTotal\n";
    for (auto entry : table)
        std::cout<<entry.first<<'\t'<<entry.second.gold<<'\t'<<entry.second.silver<<'\t'<<entry.second.bronze<<'\t'<<entry.second.total<<'\n';
}
