#include <iostream>
#include "Bridge.h"


//国籍的具体实现类
void ChinaNationality::setattribute()
{
    nationality = "China";
}

void GermanyNationality::setattribute()
{
    nationality = "Germany";
}

//参加记录的具体实现类
void NeverParticipate::setattribute()
{
    participateNumBefore = 0;
}

void ParticipateOnce::setattribute()
{
    participateNumBefore = 1;
}

//性别的具体实现类
void Male::setattribute()
{
    gender = "male";
}

void Female::setattribute()
{
    gender = "female";
}

//通过具体实现类设置属性
void CoachRole::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void CoachRole::print()
{
    cout << "I am a Coach." << endl;
    cout << "I am from " << implementor1->nationality << "." << endl;
    cout << "My gender is " << implementor2->gender << "." << endl;
    if (implementor3->participateNumBefore == 0)
    {
        cout << "I've never been to the Olympics before. This is my first time." << endl;
    }
    else if (implementor3->participateNumBefore == 1)
    {
        cout << "I've already been to the Olympics once" << endl;
    }
}

//通过具体实现类设置属性
void AthleteRole::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void AthleteRole::print()
{
    cout << "I am an Athlete." << endl;
    cout << "I am from " << implementor1->nationality << "." << endl;
    cout << "My gender is " << implementor2->gender << "." << endl;
    if (implementor3->participateNumBefore == 0)
    {
        cout << "I've never been to the Olympics before. This is my first time." << endl;
    }
    else if (implementor3->participateNumBefore == 1)
    {
        cout << "I've already been to the Olympics once" << endl;
    }
}

//通过具体实现类设置属性
void Volunteer::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void Volunteer::print()
{
    cout << "I am a Volunteer." << endl;
    cout << "I am from " << implementor1->nationality << "." << endl;
    cout << "My gender is " << implementor2->gender << "." << endl;
    if (implementor3->participateNumBefore == 0)
    {
        cout << "I've never been to the Olympics before. This is my first time." << endl;
    }
    else if (implementor3->participateNumBefore == 1)
    {
        cout << "I've already been to the Olympics once" << endl;
    }
}


int testBridge()
{
    Implementor* china = new ChinaNationality;
    Implementor* germany = new GermanyNationality;
    Implementor* neverparticipate = new NeverParticipate;
    Implementor* participateonce = new ParticipateOnce();
    Implementor* male = new Male;
    Implementor* female = new Female;

    Role* coach1 = new CoachRole(germany, female, participateonce);
    coach1->setattribute();
    coach1->print();

    Role* athlete1 = new AthleteRole(china, male, neverparticipate);
    athlete1->setattribute();
    athlete1->print();

    Role* volunteer1 = new Volunteer(china, female, neverparticipate);
    volunteer1->setattribute();
    volunteer1->print();

    delete coach1;
    delete athlete1;
    delete volunteer1;

    delete china;
    delete germany;
    delete neverparticipate;
    delete participateonce;
    delete male;
    delete female;

    cout << endl;

    return 0;
}