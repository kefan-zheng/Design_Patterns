#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

//奖牌榜的一项
struct NationMedal {
	string country;
	int gold;
	int silver;
	int copper;
	NationMedal(string country, int g, int s, int c) : country(country), gold(g), silver(s), copper(c) {}
	NationMedal(const NationMedal& m) {
		this->country = m.country;
		this->gold = m.gold;
		this->silver = m.silver;
		this->copper = m.silver;
	}
	NationMedal& operator=(const NationMedal& m) {
		this->country = m.country;
		this->gold = m.gold;
		this->silver = m.silver;
		this->copper = m.silver;
		return *this;
	}
	void setMedal(int g, int s, int c) {
		gold = g;
		silver = s;
		copper = c;
	}

};

//奖牌榜
struct MedalRanking {
	vector<NationMedal*> nationList;
	MedalRanking() {}
	MedalRanking(const MedalRanking& m) {
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationMedal(*nation));
		}
	}
	MedalRanking& operator=(const MedalRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationMedal(*nation));
		}
		return *this;
	}


	void addCountry(string country, int g, int s, int c) {
		nationList.push_back(new NationMedal(country, g, s, c));
	}
	void setCountryMedal(string country, int g, int s, int c) {
		for (auto nation : nationList) {
			if (nation->country == country) {
				nation->setMedal(g, s, c);
				break;
			}
		}
	}

	void sortMedal() {
		sort(nationList.begin(), nationList.end(), [](const NationMedal* m1, const NationMedal* m2)->bool { // 定义匿名函数
			return m1->gold > m2->gold;
			});
	}

	void print() {
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
		for (auto nation : nationList) {
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
};
