#include<iostream>
#include"FrontController/FrontController.h"
#include<string>

using namespace std;

int main()
{
	cout << "----------------------------------------------------------------\n";
	cout << "*                       Olympic Game                           *\n";
	cout << "----------------------------------------------------------------\n";

	Dispatcher dispatcher;
	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	const string noTestPattern[] = {"flyweight", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype"}; //��Щ���ģʽ���ϲ������������ģʽ��
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
		//system("pause");
		cout << endl;
	}
	system("pause");
	return 0;
}