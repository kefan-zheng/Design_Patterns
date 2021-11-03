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
    string name;//代表团名称
    string nation;//所属国家地区
    int playerNum;//运动员人数
    int sportsNum;//参加的项目个数
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
        cout << "迎面走来的是来自" << this->nation << "的" << this->name << "" << std::endl;
        cout << this->name << "共派出了" << this->playerNum << "位运动员参加本届奥运会，他们将在" << this->sportsNum
            << "个项目中争夺奖牌" << std::endl;
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

//奥运代表团类
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
        this->list[0].setValue("中国代表队", "China", 230, 40);
        this->list[1].setValue("中国香港代表队", "China", 20, 7);
        this->list[2].setValue("俄罗斯奥委会代表队", "俄罗斯", 170, 30);
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
            std::cout << "出错了！";
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

