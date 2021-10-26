#include "Memento.h"

Memento::Memento(const MedalRanking& m) {
	this->medalState = m;
}

MedalRanking Memento:: getState() {
	return this->medalState;
}

void Originator::setState(MedalRanking m) {
	this->state = m;
	cout << "Medal Ranking is updating.......\n";
}

void Originator::setState(Memento* m) {
	this->state = m->getState();
	cout << "Medal Ranking is updatting.......\n";
}

void Originator::showState() {
	state.print();
}

MedalRanking Originator::getState() {
	return state;
}

Memento* Originator::createMemento() {
	return new Memento(state);
}

CareTaker::CareTaker(Originator* const o) :
	originator(o) {}

CareTaker::~CareTaker() {
	for (auto eachHistory : history) {
		delete eachHistory;
	}
	history.clear();
}

void CareTaker::save() {
	cout << "Save current state......\n";
	history.push_back(originator->createMemento());
}

void CareTaker::undo() {
	if (!history.empty()) {
		Memento* m = history.back();
		originator->setState(m);
		cout << "Undo State......\n";
	}
}

void CareTaker::showState() {
	cout << "current state......\n";
	originator->showState();
}

void MementoTest(){
	Originator* originator = new Originator();
	CareTaker* careTaker = new CareTaker(originator);

	MedalRanking state1;
	state1.addCountry("China", 38, 32, 18);
	state1.addCountry("American", 39, 41, 33);
	state1.addCountry("Japan", 27, 14, 17);
	state1.addCountry("UK", 22, 21, 22);
	state1.addCountry("Russia", 20, 28, 23);
	state1.addCountry("Testcountry", 19, 28, 23);
	originator->setState(state1);//当前奖牌榜
	careTaker->showState();//显示当前奖牌榜
	careTaker->save();//当前状态存档

	state1.setCountryMedal("Testcountry", 21, 29, 24);
	originator->setState(state1);//当前奖牌榜
	careTaker->showState();//显示当前奖牌榜

	cout << "Some Player are found using illeagal drugs in the drug test.\n";
	careTaker->undo();//退回之前状态
	careTaker->showState();
}