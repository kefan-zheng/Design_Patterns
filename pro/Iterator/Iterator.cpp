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
#include "ITerator.h"
void delayTime()
{
    for(int i=0;i<5;i++)
    {
        cout<<".";
        _sleep(500);
    }
    cout<<std::endl;
}
int testIterator()
{
    int size=6;
    ConcreteAggregate list = ConcreteAggregate(size);//元素容器

    list.addDelegation("Italy",372,19);
    list.addDelegation("Great Britain",376,28);
    list.addDelegation("Australia",478,37);
    list.addDelegation("China",406,110);
    list.addDelegation("Germany",425,115);
    list.addDelegation("United States",613,204);
    list.addDelegation("France",398,205);
    list.addDelegation("Japan",552,206);

    Iterator* it = list.createIterator();//为元素容器创建迭代器
    cout<<"Opening ceremony begins!"<<std::endl;
    delayTime();
    for (; !it->isDone(); it->next())//遍历容器
    {
        it->currentItem();
        delayTime();
    }
    delete it;
    return 0;
}