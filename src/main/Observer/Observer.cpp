#include"Observer.h"

ConcreteObserver::ConcreteObserver(string name, MedalRanking const state) :
	name(name), state(state) {}

ConcreteObserver::~ConcreteObserver() {}

MedalRanking ConcreteObserver::getState() {
	return state;
}

void ConcreteObserver::update(Subject* subject) {
	this->state = subject->getState();
}

void ConcreteObserver::showState() {
	cout << "Observer " << this->name << " state:" << endl;
	cout << this->name  << " is reporting news: This is the current medal ranking information.\n";
	this->state.print();
}

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::detach(const int index) {
	observers.erase(observers.begin() + index);
}

void Subject::notify() {
	cout << "Notifying other observers...\n";
	for (auto observer : observers) {
		observer->update(this);
	}
}

MedalRanking ConcreteSubject::getState() {
	return state;
}

void ConcreteSubject::setState(MedalRanking s) {
	cout << "Subject set state......" << endl;
	s.print();
	this->state = s;
}

void ObserverTest()
{
	//���ư�״̬
	MedalRanking state1;
	state1.addCountry("China", 38, 32, 18);
	state1.addCountry("American", 39, 41, 33);
	state1.addCountry("Japan", 27, 14, 17);
	state1.addCountry("UK", 22, 21, 22);
	state1.addCountry("Russia", 20, 28, 23);
	state1.addCountry("Testcountry", 19, 28, 23);

	//�����۲���(ý��)
	ConcreteObserver observer1("Meida A", state1);
	ConcreteObserver observer2("Media B", state1);

	//��ӹ۲�����subject����ʾ״̬
	Subject* subject = new ConcreteSubject();
	subject->attach(&observer1);
	subject->attach(&observer2);
	observer1.showState();
	observer2.showState();

	//�ı�subject״̬
	state1.setCountryMedal("Testcountry", 21, 29, 24);
	subject->setState(state1);
	subject->notify();

	//�ٴ�չʾ�۲���״̬
	observer1.showState();
	observer2.showState();

	delete subject;
}