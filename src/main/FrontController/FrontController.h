#pragma once
#include<iostream>
#include"../AbstractFactory/AbstractFactory.h"
#include"../Adapter/Adaptor.h"
#include"../Bridge/Bridge.h"
#include"../Builder/Builder.h"
#include"../ChainOfResponsibility/ChainOfResponsibility.h"
#include"../Command/Command.h"
#include"../Composite/Composite.h"
#include"../Decorator/Decorator.h"
#include"../Delegation/Delegation.h"
#include"../Facade/Facade.h"
#include"../FactoryMethod/Swimming.h"
#include"../Flyweight/Flyweight.h"
#include"../Immutable/Immutable.h"
#include"../Interpreter/Interpreter.h"
#include"../Iterator/Iterator.h"
#include"../Mediator/Mediator.h"
#include"../Mvc/Mvc.h"
#include"../Observer/Observer.h"
#include"../Memento/Memento.h"
#include"../Prototype/Prototype.h"
#include"../Proxy/Proxy.h"
#include"../Specification/Specification.h"
#include"../State/State.h"
#include"../Strategy/Strategy.h"
#include"../TemplateMethod/TemplateMethod.h"
#include"../TransferObject/TransferObject.h"
#include"../Visitor/Visitor.h"

using namespace std;

const string designpatterns[30] = { "abstractfactory","adapter","bridge","builder","chainofresponsibility","command","composite","decorator","delegation","facade",
"factorymethod","flyweight","immutable","interpreter","iterator","mediator","memento","mvc","observer","prototype","proxy","specification","state","strategy",
"templatemethod","transferobject","visitor" };

class Dispatcher
{
public:
	Dispatcher(){}

	void dispatch(string request);
};

class FrontController
{
private:
	Dispatcher* dispatcher;

	void trackRequest(string request);
public:
	FrontController() : dispatcher(){}

	void set(Dispatcher* d);

	void dispatchRequest(string request);
};
