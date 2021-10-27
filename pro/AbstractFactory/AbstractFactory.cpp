//��������ֻ��һ��ƹ���򹤳����������������Ŀ
#include <iostream>
#include "AbstractFactory.h"

using namespace std;

//���ӵ���
const char* MenSingle::getName()
{
    return "MenSingle";
}

//Ů�ӵ���
const char* WomenSingle::getName()
{
    return "WomenSingle";
}

//����˫��
const char* MenDoubles::getName()
{
    return "MenDoubles";
}


//Ů��˫��
const char* WomenDoubles::getName()
{
    return "WomenDoubles";
}


//ƹ���򹤳����̳��Գ��󹤳�
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

    //һ��ƹ���򹤳����Բ������������Ŀ��Ʒ
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