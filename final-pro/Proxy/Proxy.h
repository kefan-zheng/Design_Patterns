#pragma once
#ifndef _PROXY_H_
#define _PROXY_H_
//subject
class OlympicDrugTest
{
public:
	virtual ~OlympicDrugTest();
	OlympicDrugTest();
	virtual void check() = 0;
};
//real subject
class OlympicDrugTextResult :public OlympicDrugTest
{
public:
	OlympicDrugTextResult();
	virtual ~OlympicDrugTextResult();
	void check();
};
class Proxy :public OlympicDrugTest
{
public:
	virtual ~Proxy();
	Proxy();
	void check();
private:
	OlympicDrugTextResult* result;
};

int testProxy();

int testProxy();
#endif // !_PROXY_H_
