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
void testIterator()
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
}
int main()
{
   testIterator();
    return 0;
}