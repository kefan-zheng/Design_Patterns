#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include"AbstractMedalRanking.h"
#include"SingletonMedalRanking.h"
using namespace std;


//Γ½Με½±ΕΖ°ρ
class MedalRanking: public AbstractMedalRanking {
public:
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
	MedalRanking(const SingletonMedalRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationMedal(*nation));
		}
	}
	MedalRanking& operator=(const SingletonMedalRanking& m) {
		this->nationList.clear();
		for (auto nation : m.nationList) {
			this->nationList.push_back(new NationMedal(*nation));
		}
		return *this;
	}
};