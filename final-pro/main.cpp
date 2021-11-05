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
	const string noTestPattern[] = {"flyweight", "command", "frontController", "abstractfactory", "multition", "singleton", "prototype"}; //��Щ���ģʽ���ϲ������������ģʽ��
	
	int preNum = 7;//��ǰ�����ĳ�������
	int competitionNum = 9;//�����ĳ���
	
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

		if (i == 0) {
			transferAnimate1();
		}
		else if (i == preNum-1) {
			transferAnimate2();
		}
		else if (i == preNum + competitionNum -1) {
			transferAnimate3();
		}
	}
	system("pause");
	return 0;
}