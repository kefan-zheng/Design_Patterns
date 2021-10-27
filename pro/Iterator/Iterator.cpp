/*
 * C++ Design Patterns: Iterator
 * Author: Zhibo Xu
 * 2021/10
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */
//奥运会开幕式场景
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

    ConcreteAggregate list = ConcreteAggregate(size);//元素容器

    Iterator* it = list.createIterator();//为元素容器创建迭代器
    cout<<"开幕式开始"<<std::endl;
    delayTime();
    for (; !it->isDone(); it->next())//遍历容器
    {
        it->currentItem();
        delayTime();
    }
    delete it;
    cout << std::endl;
    return 0;
}
