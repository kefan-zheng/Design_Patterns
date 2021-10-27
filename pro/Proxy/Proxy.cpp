#include"Proxy.h"
#include<iostream>
using namespace std;
/*
	in this pattern,Olympic Drug Testing Center as the pointer, olympian as proxy
*/
OlympicDrugTest::OlympicDrugTest() {}
OlympicDrugTest::~OlympicDrugTest() {}
OlympicDrugTextResult::OlympicDrugTextResult() {}
OlympicDrugTextResult::~OlympicDrugTextResult() {}
void OlympicDrugTextResult::check()
{
	cout << "The drug test came back negative !" << endl;
}
Proxy::Proxy()
{
	result = new OlympicDrugTextResult();
}
Proxy::~Proxy()
{
	delete result;
}
void Proxy::check()
{
	cout << "Checking the results from the Olympic Drug Testing Center ..." << endl;
	cout << "The result is :";
	result->check();
}

int testProxy()
{
	Proxy* proxy = new Proxy();
	proxy->check();
	delete proxy;

	cout << endl;

	return 0;
}