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
//比赛场馆
using std::cout;
using std::endl;
class Venues
{//抽象类基类
    std::string name;
public:
    virtual ~Venues() {}

    void templateMethod()//模板方法
    {
        // ...
        holdGame();
        // ...
    }

    virtual void holdGame() = 0;

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
    void holdGame();
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

    void holdGame();

    // ...
};
class Wudokan : public Venues
{
public:
    ~Wudokan(){}
    Wudokan(std::string name)
    {
        this->setName(name);
    }

    void holdGame();
    // ...
};
#endif //TEMPLATE_METHOD_TEMPLATEMETHOD_H
