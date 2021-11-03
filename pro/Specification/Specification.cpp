#include"Specification.h"
#include<iostream>
#include<string>
#include<vector>
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
void testSpecification()
{
	//内存数据
	vector<Athlete* >Athletes;
	Athlete* A1 = new Athlete("Tim", 22, 73, "male", "U.K.");
	Athlete* A2 = new Athlete("Mike", 29, 73, "male", "U.K.");
	Athlete* A3 = new Athlete("Tom", 32, 73, "male", "U.S.");
	Athlete* A4 = new Athlete("Jack", 28, 73, "male", "U.S.");
	Athlete* A5 = new Athlete("Lin ", 21, 73, "male", "China");
	Athlete* A6 = new Athlete("Chen", 22, 61, "female", "China");
	Athlete* A7 = new Athlete("Jee", 19, 49, "female", "Japen");
	Athlete* A8 = new Athlete("Cathy", 18, 49, "female", "Germany");
	Athlete* A9 = new Athlete("Merry", 20, 61, "female", "Cananda");
	Athlete* A10 = new Athlete("Hert", 25, 59, "female", "France");
	Athlete* A11 = new Athlete("Katty", 25, 61, "female", "South Korea");
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
	cout << "Weightlifting competition now in progress !" << endl;
	cout << "Now let’s look at the athletes information !" << endl;
	cout << "Male weightlifters："<<endl;
	for (i = 0; i < size1; i++)
	{
		cout << "name：" << Athlete1.at(i)->_name << " age：" << Athlete1.at(i)->_age << " kilogram：" << Athlete1.at(i)->_Kilogram
			<< " nation：" << Athlete1.at(i)->_nation << endl;
	}
	cout << "Female weightlifters：" << endl;
	for (i = 0; i < size2; i++)
	{
		cout << "name：" << Athlete2.at(i)->_name << " age：" << Athlete2.at(i)->_age << " kilogram：" << Athlete2.at(i)->_Kilogram
			<< " nation：" << Athlete2.at(i)->_nation << endl;
	}
	cout << "Now playing in the 73kg category !" << endl;
	cout << "73 kg weightlifter：" << endl;
	for (i = 0; i < size3; i++)
	{
		cout << "name：" << Athlete3.at(i)->_name << " age：" << Athlete3.at(i)->_age << " gender：" << Athlete3.at(i)->_gender
			<< " nation：" << Athlete3.at(i)->_nation << endl;
	}
	cout << "Now playing in the 61kg category !" << endl;
	cout << "61 kg weightlifter：" << endl;
	for (i = 0; i < size4; i++)
	{
		cout << "name：" << Athlete4.at(i)->_name << " age：" << Athlete4.at(i)->_age << " gender：" << Athlete4.at(i)->_gender
			<< " nation：" << Athlete4.at(i)->_nation << endl;
	}
	cout << endl;
	cout << "The game is over, the champion is ";
	cout << "Chinese weightlifter：" << endl;
	for (i = 0; i < size5; i++)
	{
		cout << "name：" << Athlete5.at(i)->_name << " age：" << Athlete5.at(i)->_age << " kilogram：" << Athlete5.at(i)->_Kilogram
			<< " gender：" << Athlete5.at(i)->_gender<< endl;
	}
}