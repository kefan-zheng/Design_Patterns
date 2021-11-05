#include<iostream>
#include"FrontController/FrontController.h"
#include"./utils/animate.h"
#include<string>

using namespace std;

int main()
{
	startAnimate();


	Dispatcher dispatcher;
	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	const string noTestPattern[] = {"flyweight", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype", "interpreter" }; //这些设计模式被合并到了其他设计模式中
	
	int preNum = 8;//赛前比赛的场景数量
	int competitionNum = 11;//比赛的场景
	
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

		if (i == 0) {
			system("pause");
			transferAnimate1();
		}
		else if (i == preNum-1) {
			system("pause");
			transferAnimate2();
		}
		else if (i == preNum + competitionNum -1) {
			system("pause");
			transferAnimate3();

		}

		frontcontroller.dispatchRequest(designpatterns[i]);
		//system("pause");
		cout << endl;
	}
	system("pause");
	return 0;
}