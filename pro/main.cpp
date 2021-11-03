#include<iostream>
#include"FrontController/FrontController.h"
#include<string>

using namespace std;

int main()
{
	Dispatcher dispatcher;
	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	const string noTestPattern[] = {"flyweight", "strategy", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype"}; //这些设计模式被合并到了其他设计模式中
	for (int i = 0; i < 30; i++)
	{
		bool continueFlag = false;
		for (auto str : noTestPattern) {

			if (designpatterns[i] == str) {
				continueFlag = true;
				break;
			}
		}

		if (continueFlag) {
			continue;
		}

		frontcontroller.dispatchRequest(designpatterns[i]);
		if (designpatterns[i] == "immutable") {
			system("pause");
		}
		//system("pause");
		cout << endl;
	}
	system("pause");
	return 0;
}