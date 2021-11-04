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
	cout << "Medal Ranking is updating.......\n";
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

void testMemento(){
	Originator* originator = new Originator();
	CareTaker* careTaker = new CareTaker(originator);

	SingletonMedalRanking& singletonMedalStatus = SingletonMedalRanking::Instance();
	originator->setState(singletonMedalStatus);//当前奖牌榜
	careTaker->showState();//显示当前奖牌榜
	careTaker->save();//当前状态存档

	singletonMedalStatus.setCountryMedal("Testcountry", 23, 29, 24);
	originator->setState(singletonMedalStatus);//当前奖牌榜
	careTaker->showState();//显示当前奖牌榜

	cout << "Some Player are found using illeagal drugs in the drug test.\n";
	careTaker->undo();//退回之前状态
	careTaker->showState();
}