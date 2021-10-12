#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include"MedalRanking.h"
using namespace std;

//奖牌榜备忘录
class Memento {
private:
	friend class Originator;
	Memento(const MedalRanking& m) {
		this->medalState = m;
	}
	MedalRanking getState() {
		return this->medalState;
	}

private:
	MedalRanking medalState;
};

class Originator {
public:
	void setState(MedalRanking m) {
		this->state = m;
		cout << "Medal Ranking is updating.......\n";
	}
	void setState(Memento* m) {
		this->state = m->getState();
		cout << "Medal Ranking is updatting.......\n";
	}
	void showState() {
		state.print();
	}
	MedalRanking getState() {
		return state;
	}
	Memento* createMemento() {
		return new Memento(state);
	}
private:
	MedalRanking state;
};

class CareTaker {
public:
	CareTaker(Originator* const o) :
		originator(o) {}

	~CareTaker() {
		for (auto eachHistory : history) {
			delete eachHistory;
		}
		history.clear();
	}
	
	void save() {
		cout << "Save current state......\n";
		history.push_back(originator->createMemento());
	}

	void undo() {
		if (!history.empty()) {
			Memento* m = history.back();
			originator->setState(m);
			cout << "Undo State......\n";
		}
	}

	void showState() {
		cout << "current state......\n";
		originator->showState();
	}

private:
	Originator* originator;
	vector<Memento*> history;
};

