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
	const string noTestPattern[] = {"flyweight", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype", "interpreter" }; //��Щ���ģʽ���ϲ������������ģʽ��
	
	int preNum = 8;//��ǰ�����ĳ�������
	int competitionNum = 11;//�����ĳ���
	
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