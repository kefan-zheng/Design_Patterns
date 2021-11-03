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
    ConcreteAggregate list = ConcreteAggregate(size);//Ԫ������

    list.addDelegation("Italy",372,19);
    list.addDelegation("Great Britain",376,28);
    list.addDelegation("Australia",478,37);
    list.addDelegation("China",406,110);
    list.addDelegation("Germany",425,115);
    list.addDelegation("United States",613,204);
    list.addDelegation("France",398,205);
    list.addDelegation("Japan",552,206);

    Iterator* it = list.createIterator();//ΪԪ����������������
    cout<<"Opening ceremony begins!"<<std::endl;
    delayTime();
    for (; !it->isDone(); it->next())//��������
    {
        it->currentItem();
        delayTime();
    }
    delete it;
    return 0;
}