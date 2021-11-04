#include<iostream>
#include"FrontController.h"

using namespace std;

void Dispatcher::dispatch(string request)
{
	if(request == "adapter")
	{
		testAdaptor();
	}
	else if (request == "bridge")
	{
		testBridge();
	}
	else if (request == "builder")
	{
		testBuilder();
	}
	else if (request == "chainofresponsibility")
	{
		testChainOfResponsibility();
	}
	else if (request == "composite")
	{
		testComposite();
	}
	else if (request == "decorator")
	{
		testDecorator();
	}
	else if (request == "delegation")
	{
		//testDelegation();
	}
	else if (request == "facade")
	{
		testFacade();
	}
	else if (request == "factorymethod")
	{
		testFactoryMethod();
	}
	else if (request == "flyweight")
	{
		testFlyweight();
	}
	else if (request == "immutable")
	{
		testImmutable();
	}
	else if (request == "interpreter")
	{
		testInterpreter();
	}
	else if (request == "iterator")
	{
		testIterator();
	}
	else if (request == "mediator")
	{
		testMediator();
	}
	else if (request == "memento")
	{
		testMemento();
	}
	else if (request == "mvc")
	{
		testMvc();
	}
	else if (request == "observer")
	{
		testObserver();
	}
	else if (request == "proxy")
	{
		testProxy();
	}
	else if (request == "specification")
	{
		testSpecification();
	}
	else if (request == "state")
	{
		testState();
	}
	else if (request == "strategy")
	{
		testStrategy();
	}
	else if (request == "templatemethod")
	{
		testTemplateMethod();
	}
	else if (request == "transferobject")
	{
	testTransferObject();
	}
	else if (request == "visitor")
	{
		testVisitor();
	}

}


void FrontController::trackRequest(string request)
{
	if (request == "observer") {
		request += " && singleton";
	}
	else if (request == "memento") {
		request += " && singleton";
	}
	else if (request == "mediator") {
		request += " && command";
	}
	else if (request == "decrator") {
		request += " && abstracFactory";
	}
	else if (request == "facade") {
		request += " && multition";
	}
	else if (request == "delegation") {
		request += " && prototype";
	}
	else if (request == "templateMethod") {
		request += " && flyweight";
	}
	cout << "design pattern request:" << request << endl;
}

void FrontController::set(Dispatcher* d)
{
	dispatcher = d;
}

void FrontController::dispatchRequest(string request)
{
	trackRequest(request);
	dispatcher->dispatch(request);
}
