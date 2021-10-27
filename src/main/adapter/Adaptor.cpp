//
// Created by xzb23 on 2021/10/23.
//
#include<iostream>
#include "ObjectAdaptor.h"
using namespace std;
void testAdaptor()
{
    Foreigner* t = new ForeignTranslator();
    t->request();
    delete t;
}
int main()
{
    testAdaptor();
    return 0;
}

