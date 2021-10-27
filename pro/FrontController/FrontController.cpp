#include<iostream>
#include"FrontController.h"

using namespace std;

void HomeView::show()
{
	cout << "Display Homepage" << endl;
}

void WebView::show()
{
	cout << "Display Webpage" << endl;
}

void Dispatcher::set(HomeView* h, WebView* w)
{
	homeview = h;
	webview = w;
}

void Dispatcher::dispatch(string request)
{
	if (request == "student")
	{
		homeview->show();
	}
	else
	{
		webview->show();
	}
}


bool FrontController::isAuthentic()
{
	cout << "Authenticated successfully" << endl;
	return true;
}

void FrontController::trackRequest(string request)
{
	cout << "page request:" << request << endl;
}

void FrontController::set(Dispatcher* d)
{
	dispatcher = d;
}

void FrontController::dispatchRequest(string request)
{
	trackRequest(request);
	if (isAuthentic())
	{
		dispatcher->dispatch(request);
	}
}

int testFrontController()
{
	Dispatcher dispatcher;
	dispatcher.set(new HomeView(), new WebView());

	FrontController frontcontroller;
	frontcontroller.set(&dispatcher);
	frontcontroller.dispatchRequest("student");
	frontcontroller.dispatchRequest("Home");
	cout << endl;

	return 0;
}