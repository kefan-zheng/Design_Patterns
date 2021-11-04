#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include "AbstractMedalRanking.h"
#define PRI_GOLD 1
#define PRI_TOTAL 2
using namespace std;

/*
  SingletonMedalRanking: 单例模式创建的奖牌榜
*/
class SingletonMedalRanking : public AbstractMedalRanking{
    friend class MedalRanking;
public:
    static SingletonMedalRanking& Instance()
    {
        static SingletonMedalRanking instance;
        return instance;
    }

private:
	SingletonMedalRanking() = default;
	SingletonMedalRanking(const SingletonMedalRanking& m) = delete;
	SingletonMedalRanking& operator=(const SingletonMedalRanking& m) = delete;
};