#include"Specification.h"
#include<iostream>
using namespace std;
/*in this parttern ,we can query athletes through different constraints */
//举重比赛：姓名、年龄、公斤级、性别、国籍

Athlete::Athlete(string name, int age, int Kilogram, string gender, string nation)
{
	this->_name = name;
	this->_age = age;
	this->_Kilogram = Kilogram;
	this->_gender = gender;
	this->_nation = nation;
}
Athlete::~Athlete() {}
IAthleteProvide::IAthleteProvide() {}
IAthleteProvide::~IAthleteProvide() {}
bool IAthleteProvide::isBy(Athlete* athlete)
{
	return true;
}
genderSearch::genderSearch(string gender)
{
	this->_gender = gender;
}
genderSearch::~genderSearch() {}
bool genderSearch::isBy(Athlete* athlete)
{
	if (this->_gender == athlete->_gender)
	{
		return true;
	}
	return false;
}
KiloSearch::KiloSearch(int Kilogram)
{
	this->_Kilogram = Kilogram;
}
KiloSearch::~KiloSearch(){}
bool KiloSearch::isBy(Athlete* athlete)
{
	if (this->_Kilogram == athlete->_Kilogram)
	{
		return true;
	}
	return false;
}
nationSearch::nationSearch(string nation)
{
	this->_nation = nation;
}
nationSearch::~nationSearch() {}
bool nationSearch::isBy(Athlete* athlete)
{
	if (this->_nation == athlete->_nation)
	{
		return true;
	}
	return false;
}
AthleteExecute::AthleteExecute(vector<Athlete*>athletes)
{
	this->athletes = athletes;
}
vector<Athlete*>AthleteExecute::searchAthletes(IAthleteProvide* IAthlete)
{
	vector<Athlete* >Athletes;
	int size = this->athletes.size();
	for (int i = 0; i < size; i++)
	{
		if (IAthlete->isBy(this->athletes.at(i)))
		{
			Athletes.push_back(this->athletes.at(i));
		}
	}
	return Athletes;
}
int testSpecification()
{
	//内存数据
	vector<Athlete* >Athletes;
	Athlete* A1 = new Athlete("1", 22, 61, "male", "U.K.");
	Athlete* A2 = new Athlete("2", 29, 61, "male", "U.K.");
	Athlete* A3 = new Athlete("3", 32, 73, "male", "U.S.");
	Athlete* A4 = new Athlete("4", 28, 73, "male", "U.S.");
	Athlete* A5 = new Athlete("5", 21, 109, "male", "China");
	Athlete* A6 = new Athlete("6", 22, 61, "male", "China");
	Athlete* A7 = new Athlete("7", 19, 49, "female", "Japen");
	Athlete* A8 = new Athlete("8", 18, 49, "female", "Germany");
	Athlete* A9 = new Athlete("9", 20, 61, "female", "Cananda");
	Athlete* A10 = new Athlete("10", 25, 59, "female", "France");
	Athlete* A11 = new Athlete("11", 25, 73, "female", "South Korea");
	Athletes.push_back(A1);
	Athletes.push_back(A2);
	Athletes.push_back(A3);
	Athletes.push_back(A4);
	Athletes.push_back(A5);
	Athletes.push_back(A6);
	Athletes.push_back(A7);
	Athletes.push_back(A8);
	Athletes.push_back(A9);
	Athletes.push_back(A10);
	Athletes.push_back(A11);

	IAthleteExecute* search = new AthleteExecute(Athletes);
	IAthleteProvide* G1 = new genderSearch("male");
	IAthleteProvide* G2 = new genderSearch("female");
	IAthleteProvide* K1 = new KiloSearch(73);
	IAthleteProvide* K2 = new KiloSearch(61);
	IAthleteProvide* N1 = new nationSearch("China");
	vector<Athlete* >Athlete1 = search->searchAthletes(G1);
	vector<Athlete* >Athlete2 = search->searchAthletes(G2);
	vector<Athlete* >Athlete3 = search->searchAthletes(K1);
	vector<Athlete* >Athlete4 = search->searchAthletes(K2);
	vector<Athlete* >Athlete5 = search->searchAthletes(N1);
	int size1 = Athlete1.size(); 
	int size2 = Athlete2.size();
	int size3 = Athlete3.size();
	int size4 = Athlete4.size();
	int size5 = Athlete5.size();
	int i = 0;  //循环计数
	cout << "Male weightlifters："<<endl;
	for (i = 0; i < size1; i++)
	{
		cout << "姓名：" << Athlete1.at(i)->_name << " 年龄：" << Athlete1.at(i)->_age << " 公斤级：" << Athlete1.at(i)->_Kilogram
			<< " 国籍：" << Athlete1.at(i)->_nation << endl;
	}
	cout << "女子举重运动员有：" << endl;
	for (i = 0; i < size2; i++)
	{
		cout << "姓名：" << Athlete2.at(i)->_name << " 年龄：" << Athlete2.at(i)->_age << " 公斤级：" << Athlete2.at(i)->_Kilogram
			<< " 国籍：" << Athlete2.at(i)->_nation << endl;
	}
	cout << "73 kg weightlifter：" << endl;
	for (i = 0; i < size3; i++)
	{
		cout << "姓名：" << Athlete3.at(i)->_name << " 年龄：" << Athlete3.at(i)->_age << " 性别：" << Athlete3.at(i)->_gender
			<< " 国籍：" << Athlete3.at(i)->_nation << endl;
	}
	cout << "61 kg weightlifter：" << endl;
	for (i = 0; i < size4; i++)
	{
		cout << "姓名：" << Athlete4.at(i)->_name << " 年龄：" << Athlete4.at(i)->_age << " 性别：" << Athlete4.at(i)->_gender
			<< " 国籍：" << Athlete4.at(i)->_nation << endl;
	}
	cout << "Chinese weightlifter：" << endl;
	for (i = 0; i < size5; i++)
	{
		cout << "姓名：" << Athlete5.at(i)->_name << " 年龄：" << Athlete5.at(i)->_age << " 公斤级：" << Athlete5.at(i)->_Kilogram
			<< " 性别：" << Athlete5.at(i)->_gender<< endl;
	}

	cout << endl;

	return 0;
}