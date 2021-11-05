#pragma once
#include <iostream>

using namespace std;

//实现类
class Implementor
{
public:
    virtual ~Implementor() {}

    string nationality;
    string gender;
    //参加奥运会总数
    int participateNumBefore;

    virtual void setattribute() = 0;
};

//国籍的具体实现类
class ChinaNationality : public Implementor
{
public:
    ~ChinaNationality() {}

    void setattribute();
};

class GermanyNationality : public Implementor
{
public:
    ~GermanyNationality() {}

    void setattribute();
};

//参加奥运会记录的具体实现类
class NeverParticipate : public Implementor
{
public:
    ~NeverParticipate() {}

    void setattribute();
};

class ParticipateOnce : public Implementor
{
public:
    ~ParticipateOnce() {}

    void setattribute();
};

//性别的具体实现类
class Male : public Implementor
{
public:
    ~Male() {}

    void setattribute();
};

class Female : public Implementor
{
public:
    ~Female() {}

    void setattribute();
};


//抽象类
class Role
{
public:
    Implementor* implementor1;
    Implementor* implementor2;
    Implementor* implementor3;

    Role(Implementor* impl, Implementor* imp2, Implementor* imp3) : implementor1(impl), implementor2(imp2), implementor3(imp3) {}
    virtual ~Role() {}

    virtual void setattribute() = 0;
    virtual void print() = 0;
};

//扩展抽象类的接口，分为教练、运动员、志愿者三个角色
class CoachRole : public Role
{
public:
    ~CoachRole() {}

    CoachRole(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();

};

class AthleteRole : public Role
{
public:
    ~AthleteRole() {}

    AthleteRole(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();

};

class Volunteer : public Role
{
public:
    ~Volunteer() {};
    Volunteer(Implementor* impl, Implementor* imp2, Implementor* imp3) : Role(impl, imp2, imp3) {}

    void setattribute();

    void print();
};

int testBridge();