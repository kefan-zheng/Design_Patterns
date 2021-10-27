#pragma once
#ifndef TEMPLATE_METHOD_TEMPLATEMETHOD_H
#define TEMPLATE_METHOD_TEMPLATEMETHOD_H
/*
 * C++ Design Patterns: Template Method
 * Author: Zhibo Xu
 * 2021/10
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>
#include "cstdlib"
/*
 * AbstractClass
 * implements a template method defining the skeleton of an algorithm
 */
//��������
using std::cout;
using std::endl;
class Venues
{//���������
    std::string name;
public:
    virtual ~Venues() {}

    void templateMethod()//ģ�巽��
    {
        // ...
        holdGame1();
        // ...
        cout<<" and ";
        holdGame2();
        // ...
    }

    virtual void holdGame1() = 0;
    virtual void holdGame2() = 0;

    void setName(std::string name)
    {
        this->name=name;
    }
    std::string getName()
    {
        return this->name;
    }
    // ...
};
/*
 * Concrete Class
 * implements the primitive operations to carry out specific steps
 * of the algorithm, there may be many Concrete classes, each implementing
 * the full set of the required operation
 */
class SwimmingVenues : public Venues
{
public:
    ~SwimmingVenues() {}

    SwimmingVenues(std::string name)
    {
        this->setName(name);
    }

    void holdGame1()
    {
        std::cout << "swimming" ;
        // ...
    }

    void holdGame2()
    {
        std::cout << "diving";
        // ...
    }
    // ...
};
class TrackFieldVenues : public Venues
{
public:
    ~TrackFieldVenues(){}

    TrackFieldVenues(std::string name)
    {
        this->setName(name);
    }

    void holdGame1()
    {
        std::cout << "100m game";
        // ...
    }

    void holdGame2()
    {
        std::cout << "javelin" ;
        // ...
    }
    // ...
};

int testTemplateMethod();

#endif //TEMPLATE_METHOD_TEMPLATEMETHOD_H
