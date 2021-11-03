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
    string nation;//所属国家地区
    int playerNum;//运动员人数
    int order;//enter order
public:
    Delegation()
    {
        this->playerNum=0;
        this->order=0;
    }
    void setValue(string nation,int num1,int num2)
    {
        this->nation = nation;
        this->playerNum = num1;
        this->order = num2;
    }
    void declare()
    {
        cout<<"Walking head-on is the "<<this->nation<<" team."<<std::endl;
        cout<<this->nation<<" sent "<<this->playerNum<<"players. They enters in the order of "
            <<this->order<<"."<<std::endl;
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
    // ...
};

/*
 * Concrete Aggregate
 * has a collection of objects and implements the method
 * that returns an Iterator for its collection
 *
 */
//奥运代表团类
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(unsigned int size)
    {
        list = new Delegation[size];
        count = size;
        exist=0;
    }
    ~ConcreteAggregate()
    {
        delete[] list;
    }
    Iterator* createIterator();
    unsigned int getSize() const
    {
        return count;
    }
    void at(unsigned int index)
    {
        list[index].declare();
    }
    void addDelegation(string nation,int num1,int num2)
    {
        if(exist==count)
        {
            cout<<"Capacity is full"<<std::endl;
            return;
        }
        this->list[exist].setValue(nation,num1,num2);
        exist++;
    }
    // ...

private:
    Delegation* list;
    unsigned int count;//capacity
    int exist;//number of teams that already exist
    // ...
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
        return (index >= list->getSize());
    }
    void currentItem()
    {
        if (isDone())
        {
            std::cout<<"出错了！";
        }
        list->at(index);
    }

private:
    ConcreteAggregate* list;
    unsigned int index;
    // ...
};
Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}
#endif //ITERATOR_ITERATOR_H
