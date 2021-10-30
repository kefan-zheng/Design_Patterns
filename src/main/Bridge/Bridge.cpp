#include <iostream>
#include "Bridge.h"


//�����ľ���ʵ����
void ChinaNationality::setattribute()
{
    nationality = "China";
}

void GermanyNationality::setattribute()
{
    nationality = "Germany";
}

//�Ա�ľ���ʵ����
void Male::setattribute()
{
    gender = "male";
}

void Female::setattribute()
{
    gender = "female";
}

//��չ������Ľӿ�
void CoachRole::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
}

void CoachRole::print()
{
    std::cout << "I am a Coach." << std::endl;
    std::cout << "I am from " << implementor1->nationality << "." << std::endl;
    std::cout << "My gender is " << implementor2->gender << "." << std::endl;
}

void AthleteRole::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
}

void AthleteRole::print()
{
    std::cout << "I am an Athlete." << std::endl;
    std::cout << "I am from " << implementor1->nationality << "." << std::endl;
    std::cout << "My gender is " << implementor2->gender << "." << std::endl;
}


int testBridge()
{
    Implementor* nationality1 = new ChinaNationality;
    Implementor* nationality2 = new GermanyNationality;
    Implementor* gender1 = new Male;
    Implementor* gender2 = new Female;

    Role* coach = new CoachRole(nationality2, gender2);
    coach->setattribute();
    coach->print();

    Role* athlete = new AthleteRole(nationality1, gender1);
    athlete->setattribute();
    athlete->print();

    delete coach;
    delete athlete;

    delete nationality1;
    delete nationality2;
    delete gender1;
    delete gender2;

    cout << endl;

    return 0;
}