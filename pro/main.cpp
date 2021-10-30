#include<iostream>
#include"FrontController/FrontController.h"

using namespace std;

int main()
{
	
	Dispatcher dispatcher;
	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	for (int i = 0; i < 30; i++)
	{
		frontcontroller.dispatchRequest(designpatterns[i]);
		system("pause");
		cout << endl;
	}

	return 0;
}