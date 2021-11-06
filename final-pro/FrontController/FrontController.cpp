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
		testDelegation();
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
		//testInterpreter();
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

//输出场景提示
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_HBLUE);
	if (request == "facade") {
		cout << "Now Players all over the world are coming to the Olyic Village.";
	}
	else if (request == "iterator") {
		cout << "Teams from different nations are participating in the opening ceremony.";
	}
	else if (request == "adapter") {
		cout << "Organizers are trying to sovle communication problems caused by different languages.";
	}
	else if (request == "templatemethod") {
		cout << "The usage of different venues are as follows.";
	}
	else if (request == "immutable") {
		cout << "What's Bird's Nest? Just read texts as follows!";
	}
	else if (request == "composite") {
		cout << "Here we can see some information of several competitions.";
	}
	else if (request == "strategy") {
		cout << "Here are some of competitions sorted in different orders.";
	}
	else if (request == "bridge") {
		cout << "Now we are interviewing some people in the stadium.";
	}
	else if (request == "builder") {
		cout << "Let's see what competitions are coming up.";
	}
	else if (request == "factorymethod") {
		cout << "Swimming competition";
	}
	else if (request == "delegation") {
		cout << "Diving competition";
	}
	else if (request == "decorator") {
		cout << "Table tennis competition \nRunning competition";
	}
	else if (request == "visitor") {
		cout << "Football Game";
	}
	else if (request == "mediator") {
		cout << "Basketball game";
	}
	else if (request == "mvc") {
		cout << "Shooting competition";
	}
	else if (request == "state") {
		cout << "Triathlon";
	}
	else if (request == "transferobject") {
		cout << "Badminton game";
	}
	else if (request == "specification") {
		cout << "Weight lifting competition";
	}
	else if (request == "observer") {
		cout << "Here are reactions of aundience and medias afer the change of medal ranking.";
	}
	else if (request == "memento") {
		cout << "Here we will see what will happen if some players are found using illeagal drugs in the drug test.";
	}
	else if (request == "chainofresponsibility") {
		cout << "Now let'see the process after appealing to the organizing committee.";
	}
	else if (request == "proxy") {
		cout << "A drug test starts!";
	}
	cct_setcolor();
}

void FrontController::trackRequest(string request)
{
	string originRequest = request;
	if (request == "observer") {
		request += " && singleton";
	}
	else if (request == "memento") {
		request += " && singleton";
	}
	else if (request == "mediator") {
		request += " && command";
	}
	else if (request == "decorator") {
		request += " && abstracFactory";
	}
	else if (request == "facade") {
		request += " && multition";
	}
	else if (request == "delegation") {
		request += " && prototype";
	}
	else if (request == "templatemethod") {
		request += " && flyweight";
	}
	else if (request == "transferobject") {
		request += " && interpreter";
	}
	
	//输出场景提示
	cout << "---------------------------------------------------------------------------\n\n";
	outputScene(originRequest);
	cout << "\n";

	//输出设计模式提示
	cct_setcolor(COLOR_BLACK, COLOR_HGREEN);
	cout << "design pattern request:" << request << endl;
	cct_setcolor();
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
