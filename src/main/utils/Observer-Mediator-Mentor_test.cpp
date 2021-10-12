#include "Mediator.h"
#include "Observer.h"
#include "Memento.h"

int MediatorTest() {
	Mediator* competition = new ConcreteMediator();//中介者

	//依次添加三个运动员
	Player* p1 = new ConcretePlayer(competition);
	Player* p2 = new ConcretePlayer(competition);
	Player* p3 = new ConcretePlayer(competition);
	competition->add(p1);
	competition->add(p2);
	competition->add(p3);

	p1->send("I ask to stop!");//p1要求停止比赛
	p2->send("Please stop right now!");//p2要求停止比赛

	return 0;
}

int ObserverTest()
{
	//奖牌榜状态
	MedalRanking state1;
	state1.addCountry("China", 38, 32, 18);
	state1.addCountry("American", 39, 41, 33);
	state1.addCountry("Japan", 27, 14, 17);
	state1.addCountry("UK", 22, 21, 22);
	state1.addCountry("Russia", 20, 28, 23);
	state1.addCountry("Testcountry", 19, 28, 23);

	//两个观察者(媒体)
	ConcreteObserver observer1("Meida A", state1);
	ConcreteObserver observer2("Media B", state1);

	//添加观察者至subject并显示状态
	Subject* subject = new ConcreteSubject();
	subject->attach(&observer1);
	subject->attach(&observer2);
	observer1.showState();
	observer2.showState();

	//改变subject状态
	state1.setCountryMedal("Testcountry", 21, 29, 24);
	subject->setState(state1);
	subject->notify();

	//再吃显示观察者状态
	observer1.showState();
	observer2.showState();

	delete subject;
	return 0;
}

void MementoTest() {
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

int main(){
	cout << "Mediator Test starts......\n";
	MediatorTest();

	cout << "\nObserver Test starts......\n";
	ObserverTest();

	cout << "\nMemnto Test starts......\n";
	MementoTest();

    return 0;
}
