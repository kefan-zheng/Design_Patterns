#pragma once
#include<string>
#include<map>
#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_
using namespace std;
class Flyweight
{
public:
	Flyweight();
	virtual ~Flyweight();
	virtual void Execute(int extrinsicState) = 0;
};
class ConcreteCompetition :public Flyweight
{
public:
	ConcreteCompetition(string item);
	~ConcreteCompetition();
	void Execute(int extrinsicState);
private:
	string item;
};
class FlyweightFactory
{
private:
	map<string, ConcreteCompetition* >Flyweights;
public:
	FlyweightFactory();
	virtual ~FlyweightFactory();
	virtual ConcreteCompetition* GetFlyweight(string key);
	map<string ,ConcreteCompetition*>* getFlyWeights()
       {
        return  &Flyweights;
       }
};

#endif // !_FLYWEIGHT_H_
