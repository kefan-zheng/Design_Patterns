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
	cout << "Querying athlete information..." << endl;
	cout << "Athlete information verified successfully... " << endl;
	cout << "Returning drug test results ..." << endl;
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
	cout << "Athlete wants to view drug test results !" << endl;
	cout << "Query results through an agent ..." << endl;
	cout << "Checking the results from the Olympic Drug Testing Center ..." << endl;
	cout << "The agent connects to the drug test center..." << endl;
	result->check();
}
int main()
{
	Proxy* proxy = new Proxy();
	proxy->check();
	delete proxy;
	return 0;
}