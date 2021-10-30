#pragma once
#include <stdio.h>
class CPrototype //
{
public:
    virtual ~CPrototype() {}
    virtual CPrototype *Clone() = 0;
};

class CConcretePrototype1 : public CPrototype
{
public:
    CConcretePrototype1()
    {
        printf("[CConcretePrototype1] ctor. \n");
    }
    ~CConcretePrototype1()
    {
        printf("[CConcretePrototype1] dtor. \n");
    }

public:
    virtual CPrototype *Clone() { return new CConcretePrototype1(*this); }

private:
    // make the copy constructor private since we have Clone()
    CConcretePrototype1(const CConcretePrototype1 &rhs)
    {
        printf("[CConcretePrototype1] copy ctor. \n");
    }
};

class CConcretePrototype2 : public CPrototype
{
public:
    CConcretePrototype2()
    {
        printf("[CConcretePrototype2] ctor. \n");
    }
    ~CConcretePrototype2()
    {
        printf("[CConcretePrototype2] dtor. \n");
    }

public:
    virtual CPrototype *Clone() { return new CConcretePrototype2(*this); }

private:
    // make the copy constructor private since we have Clone()
    CConcretePrototype2(const CConcretePrototype2 &rhs)
    {
        printf("[CConcretePrototype2] copy ctor. \n");
    }
};

int testPrototype();//test
