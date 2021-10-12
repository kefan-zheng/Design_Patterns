#include"Observer.h"

void ConcreteObserver::update(Subject* subject) {
	this->state = subject->getState();
}

void ConcreteObserver::showState() {
	cout << "Observer " << this->name << " state:" << endl;
	this->state.print();
}