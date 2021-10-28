#include"Observer.h"

ObserverMedia::ObserverMedia(string name, MedalRanking const state) :
	name(name), state(state) {}

ObserverMedia::~ObserverMedia() {}

MedalRanking ObserverMedia::getState() {
	return state;
}

void ObserverMedia::update(Subject* subject) {
	
	this->state = subject->getState();
}

void ObserverMedia::showState() {
	cout << "Observer(Media) " << this->name << " state:" << endl;
	cout << this->name  << " is reporting news: This is the current medal ranking information.\n";
	this->state.print();
}


ObserverAudience::ObserverAudience(string name):state(ObserverAudienceState::sleepy) {
	this->name = name;
}

void ObserverAudience::update(Subject* s) {
	this->state = ObserverAudienceState::excited;
}

void ObserverAudience::showState() {
	if (this->state == ObserverAudienceState::sleepy) {
		cout << "Observer(Audience) " << this->name << " feels sleepy because the medal ranking has not been changed for a long time.\n";
	}
	else if (this->state == ObserverAudienceState::excited) {
		cout << "Observer(Audience) " << this->name << " feels excited as the medal ranking changed.\n";
	}
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

SingletonMedalRanking& ConcreteSubject::getState() {
	return state;
}


void testObserver()
{
	//奖牌榜状态
	SingletonMedalRanking& singletonMedalStatus = SingletonMedalRanking::Instance();
	singletonMedalStatus.addCountry("China", 38, 32, 18);
	singletonMedalStatus.addCountry("American", 39, 41, 33);
	singletonMedalStatus.addCountry("Japan", 27, 14, 17);
	singletonMedalStatus.addCountry("UK", 22, 21, 22);
	singletonMedalStatus.addCountry("Russia", 20, 28, 23);
	singletonMedalStatus.addCountry("Testcountry", 19, 28, 23);

	//4个观察者(2个媒体，2个观众)
	ObserverMedia media1("Tencert News", singletonMedalStatus);
	ObserverMedia media2("BBC", singletonMedalStatus);
	ObserverAudience audience1("Zihao Yang");
	ObserverAudience audience2("Fengyuan cao");

	//添加观察者至subject并显示状态
	Subject* subject = new ConcreteSubject();
	subject->attach(&media1);
	subject->attach(&media2);
	subject->attach(&audience1);
	subject->attach(&audience2);
	cout << "The oringinal states of observers are as follows\n";
	media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	//改变subject状态
	singletonMedalStatus.setCountryMedal("Testcountry", 21, 29, 24);
	cout << "The subject changed and then notified observers...\n";
	subject->notify();

	//再次展示观察者状态
    media1.showState();
	media2.showState();
	audience1.showState();
	audience2.showState();

	delete subject;
}