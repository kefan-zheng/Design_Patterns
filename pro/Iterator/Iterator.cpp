/*
 * C++ Design Patterns: Iterator
 * Author: Zhibo Xu
 * 2021/10
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */
//���˻ῪĻʽ����
#include "iostream"
#include "Iterator.h"
#include<Windows.h>

void delayTime()
{
    for(int i=0;i<5;i++)
    {
        cout<<".";
        Sleep(500);
    }
    cout<<std::endl;
}

Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}

int testIterator()
{
    int size=3;

    ConcreteAggregate list = ConcreteAggregate(size);//Ԫ������

    Iterator* it = list.createIterator();//ΪԪ����������������
    cout<<"��Ļʽ��ʼ"<<std::endl;
    delayTime();
    for (; !it->isDone(); it->next())//��������
    {
        it->currentItem();
        delayTime();
    }
    delete it;
    cout << std::endl;
    return 0;
}
