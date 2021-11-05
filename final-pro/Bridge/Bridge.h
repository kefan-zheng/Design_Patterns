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
    //�μӰ��˻�����
    int participateNumBefore;

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

//�μӰ��˻��¼�ľ���ʵ����
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
    Implementor* implementor1;
    Implementor* implementor2;
    Implementor* implementor3;

    Role(Implementor* impl, Implementor* imp2, Implementor* imp3) : implementor1(impl), implementor2(imp2), implementor3(imp3) {}
    virtual ~Role() {}

    virtual void setattribute() = 0;
    virtual void print() = 0;
};

//��չ������Ľӿڣ���Ϊ�������˶�Ա��־Ը��������ɫ
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