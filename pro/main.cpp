#include<iostream>
#include"AbstractFactory/AbstractFactory.h"
#include"Adapter/Adaptor.h"
#include"Bridge/Bridge.h"
#include"Builder/Builder.h"
#include"ChainOfResponsibility/ChainOfResponsibility.h"
#include"Composite/Composite.h"
#include"Decorator/Decorator.h"
#include"Delegation/Delegation.h"
#include"Facade/Facade.h"
#include"FactoryMethod/Swimming.h"
#include"Flyweight/Flyweight.h"
#include"FrontController/FrontController.h"
#include"Immutable/Immutable.h"
#include"Iterator/Iterator.h"
#include"Mediator/Mediator.h"
#include"Memento/Memento.h"
#include"Mvc/Mvc.h"
#include"Observer/Observer.h"
#include"Prototype/Prototype.h"
#include"Proxy/Proxy.h"
#include"Specification/Specification.h"
#include"State/State.h"
#include"Strategy/Strategy.h"
#include"TemplateMethod/TemplateMethod.h"
#include"Visitor/Visitor.h"

using namespace std;

int main()
{
	testAbstractFactory();
	testAdaptor();
	testBridge();
	testBuilder();
	testChainOfResponsibility();
	testComposite();
	testDecorator();
	testFacade();
	testFlyweight();
	testFrontController();
	testImmutable();
	testIterator();
	testMediator();
	testMVC();
	testObserver();
	testMemento();
	testProxy();
	testSpecification();
	testState();
	testStrategy();
	testTemplateMethod();
	testVisitor();
	testPrototype();

	return 0;
}