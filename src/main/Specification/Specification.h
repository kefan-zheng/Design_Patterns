#pragma once
//举重比赛：姓名、年龄、公斤级、性别、国籍
#ifndef _SPECIFICATION_H_
#define _SPECIFICATION_H_
#include<vector>
#include<string>
using namespace std;
class Athlete
{
public:
	Athlete(string name,int age,int Kilogram,string gender,string nation);
	~Athlete();
	string _name;
	int _age;
	int _Kilogram;
	string _gender;
	string _nation;
};
//Athlete provide interface
//specification interface
class IAthleteProvide
{
public:
	IAthleteProvide();
	~IAthleteProvide();
	virtual bool isBy(Athlete* athlete);//查询是否符合筛选条件
};
//specification executex
class IAthleteExecute
{
public:
	virtual vector<Athlete* >searchAthletes(IAthleteProvide* IAthlete) = 0;
};
class AthleteExecute :public IAthleteExecute
{
public:
	AthleteExecute(vector<Athlete* >athletes);
	~AthleteExecute();
	vector<Athlete* >searchAthletes(IAthleteProvide* Athlete)override;
private:
	vector<Athlete* >athletes;
};
class genderSearch :public IAthleteProvide
{
public:
	genderSearch(string gender);
	~genderSearch();
	bool isBy(Athlete* athlete)override;
private:
	string _gender;
};
class KiloSearch :public IAthleteProvide
{
public:
	KiloSearch(int Kilogram);
	~KiloSearch();
	bool isBy(Athlete* athlete)override;
private:
	int _Kilogram;
};
class nationSearch :public IAthleteProvide
{
public:
	nationSearch(string nation);
	~nationSearch();
	bool isBy(Athlete* athlete)override;
private:
	string _nation;
};
#endif // !_SPECIFICATION_H_

