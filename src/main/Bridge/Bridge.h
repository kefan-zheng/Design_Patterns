#pragma once
#include <iostream>

using namespace std;

//ʵ����
class Implementor
{
public:
    virtual ~Implementor() {}

    string nationality;
    string gender;

    virtual void setattribute() = 0;
};

//�����ľ���ʵ����
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

//�Ա�ľ���ʵ����
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


//������
class Role
{
public:
    virtual ~Role() {}

    virtual void setattribute() = 0;
    virtual void print() = 0;
};

//��չ������Ľӿ�
class CoachRole : public Role
{
private:
    Implementor* implementor1;
    Implementor* implementor2;
public:
    ~CoachRole() {}

    CoachRole(Implementor* impl, Implementor* imp2) : implementor1(impl), implementor2(imp2) {}

    void setattribute();

    void print();

};

class AthleteRole : public Role
{
private:
    Implementor* implementor1;
    Implementor* implementor2;
public:
    ~AthleteRole() {}

    AthleteRole(Implementor* impl, Implementor* imp2) : implementor1(impl), implementor2(imp2) {}

    void setattribute();

    void print();

};

int testBridge();