#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#define PRI_GOLD 1
#define PRI_TOTAL 2
using namespace std;

//奖牌榜的一项
class NationMedal {
public:
	std::string country;
	int gold;
	int silver;
	int copper;
	NationMedal(string country, int g, int s, int c) : country(country), gold(g), silver(s), copper(c) {}
	NationMedal(const NationMedal& m);
	NationMedal& operator=(const NationMedal& m);
	void setMedal(int g, int s, int c);
};

class AbstractMedalRanking
{
public:
	void addCountry(string country, int g, int s, int c);
	void setCountryMedal(string country, int g, int s, int c);
    void sortMedal(int policy = PRI_GOLD);
    void print();
private:
	vector<NationMedal*> nationList;
};
