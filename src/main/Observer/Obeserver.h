#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"MedalRanking.h"
using namespace std;

class Subject;
class Observer {
public:
	virtual ~Observer() {}

	virtual MedalRanking getState() = 0;
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
};

//ConcreteObserver:这里指的是各家媒体
class ConcreteObserver : public Observer {
public:
	ConcreteObserver(string name, MedalRanking const state) :
		name(name), state(state) {}
	~ConcreteObserver() {}
	MedalRanking getState() {
		return state;
	}
	void update(Subject* subject);
	void showState();
private:
	MedalRanking state;
	string name;
};

class Subject {
public:
	void attach(Observer* observer) {
		observers.push_back(observer);
	}
	void detach(const int index) {
		observers.erase(observers.begin() + index);
	}
	void notify() { 
		cout << "Notifying other observers...\n";
		for (auto observer : observers) {
			observer->update(this);
		}
	}
	virtual MedalRanking getState() = 0;
	virtual void setState(const MedalRanking s) = 0;
private:
	vector<Observer*> observers;
};

class ConcreteSubject :public Subject {
public:
	MedalRanking getState() {
		return state;
	}
	void setState(MedalRanking s) {
		cout << "Subject set state......" << endl;
		s.print();
		this->state = s;
	}
private:
	MedalRanking state;
};
