#include<iostream>
#include"FrontController/FrontController.h"
#include<string>

using namespace std;

int main()
{
	
	Dispatcher dispatcher;
	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	const string noTestPattern[] = {"flyweight", "strategy", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype"};
	for (int i = 0; i < 30; i++)
	{
		for (auto str : noTestPattern) {
			if (designpatterns[i] == str) {
				continue;
			}
		}

		frontcontroller.dispatchRequest(designpatterns[i]);
		system("pause");
		cout << endl;
	}

	return 0;
}