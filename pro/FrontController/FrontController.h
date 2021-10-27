#pragma once
#include<iostream>

using namespace std;

class HomeView
{
public:
	void show();
};

class WebView
{
public:
	void show();
};

class Dispatcher
{
private:
	HomeView* homeview;
	WebView* webview;

public:
	Dispatcher() : homeview(), webview() {}


	void set(HomeView* h, WebView* w);

	void dispatch(string request);
};

class FrontController
{
private:
	Dispatcher* dispatcher;
	
	bool isAuthentic();

	void trackRequest(string request);
public:
	FrontController() : dispatcher(){}

	void set(Dispatcher* d);

	void dispatchRequest(string request);
};

int testFrontController();