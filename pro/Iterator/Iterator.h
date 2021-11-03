#pragma once
//
// Created by xzb23 on 2021/10/23.
//

#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H
#include <iostream>
#include <vector>
#include<string>
#include "cstdlib"
using std::string;
using std::cout;
using std::cin;
class Iterator;
class ConcreteAggregate;
class Delegation
{
private:
    string name;//����������
    string nation;//�������ҵ���
    int playerNum;//�˶�Ա����
    int sportsNum;//�μӵ���Ŀ����
public:
    Delegation()
    {
        this->playerNum = 0;
        this->sportsNum = 0;
    }
    void setValue(string name, string nation, int num1, int num2)
    {
        this->name = name;
        this->nation = nation;
        this->playerNum = num1;
        this->sportsNum = num2;
    }
    void declare()
    {
        cout << "ӭ��������������" << this->nation << "��" << this->name << "" << std::endl;
        cout << this->name << "���ɳ���" << this->playerNum << "λ�˶�Ա�μӱ�����˻ᣬ���ǽ���" << this->sportsNum
            << "����Ŀ�����ά��" << std::endl;
    }
};
/*
 * Aggregate
 * defines an interface for aggregates and it decouples your
 * client from the implementation of your collection of objects
 */
class Aggregate
{
public:
    virtual ~Aggregate() {}

    virtual Iterator* createIterator() = 0;
};

//���˴�������
class ConcreteAggregate : public Aggregate
{
private:
    Delegation* list;
    unsigned int count;
public:
    ConcreteAggregate(unsigned int size)
    {
        list = new Delegation[size];
        this->initDelegations();
        count = size;
    }
    ~ConcreteAggregate()
    {
        delete[] list;
    }

    Iterator* createIterator();

    unsigned int size() const
    {
        return count;
    }

    void at(unsigned int index)
    {
        list[index].declare();
    }


    void initDelegations()
    {
        this->list[0].setValue("�й������", "China", 230, 40);
        this->list[1].setValue("�й���۴����", "China", 20, 7);
        this->list[2].setValue("����˹��ί������", "����˹", 170, 30);
    }

};

/*
 * Iterator
 * provides the interface that all iterators must implement and
 * a set of methods for traversing over elements
 */
class Iterator
{
public:
    virtual ~Iterator() { /* ... */ }

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual void currentItem() = 0;
    // ...
};

/*
 * Concrete Iterator
 * implements the interface and is responsible for managing
 * the current position of the iterator
 */
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(ConcreteAggregate* l) :
        list(l), index(0) {}

    ~ConcreteIterator() {}

    void first()
    {
        index = 0;
    }

    void next()
    {
        index++;
    }

    bool isDone() const
    {
        return (index >= list->size());
    }
    void currentItem()
    {
        if (isDone())
        {
            std::cout << "�����ˣ�";
        }
        list->at(index);
    }

private:
    ConcreteAggregate* list;
    unsigned int index;
    // ...
};



int testIterator();

#endif //ITERATOR_ITERATOR_H

