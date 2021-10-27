//本例子中只有一个乒乓球工厂，产生多个比赛项目
#include <iostream>
#include "AbstractFactory.h"

using namespace std;

//男子单打
const char* MenSingle::getName()
{
    return "MenSingle";
}

//女子单打
const char* WomenSingle::getName()
{
    return "WomenSingle";
}

//男子双打
const char* MenDoubles::getName()
{
    return "MenDoubles";
}


//女子双打
const char* WomenDoubles::getName()
{
    return "WomenDoubles";
}


//乒乓球工厂，继承自抽象工厂
Single* TableTennisFactory::createSingleGame()
{
    return new MenSingle();
}

Doubles* TableTennisFactory::createDoublesGame()
{
    return new MenDoubles();
}

int testAbstractFactory()
{
    TableTennisFactory* factory = new TableTennisFactory();

    //一个乒乓球工厂可以产生多个比赛项目产品
    Single* p1 = factory->createSingleGame();
    Doubles* p2 = factory->createDoublesGame();
    cout << "ProjectName1: " << p1->getName() << endl;
    cout << "ProjectName2: " << p2->getName() << endl;

    delete p1;
    delete p2;

    delete factory;

    cout << endl;

    return 0;
}