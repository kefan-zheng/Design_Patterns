#include<iostream>
#include"State.h"
using namespace std;
//state Pattern
//in this pattern ,athletes change states to play differenr games
state::state(){}
state::~state() {}
swimmingstate::swimmingstate(){}
swimmingstate::~swimmingstate() {}
void swimmingstate::handle(Context* pContext)
{
	cout << "This is the swimming section now !" << endl;
	pContext->Changestate(new TransitionSectionA());
}

TransitionSectionA::TransitionSectionA() {}
TransitionSectionA::~TransitionSectionA() {}
void TransitionSectionA::handle(Context* pContext)
{
	cout << "This is transition section from swimming to cycling now !" << endl;
	pContext->Changestate(new cyclingstate());
}

cyclingstate::cyclingstate() {}
cyclingstate::~cyclingstate() {}
void cyclingstate::handle(Context* pContext)
{
	cout << "This is the cycling section now !" << endl;
	pContext->Changestate(new TransitionSectionB());
}

TransitionSectionB::TransitionSectionB() {}
TransitionSectionB::~TransitionSectionB() {}
void TransitionSectionB::handle(Context* pContext)
{
	cout << "This is transition section from cycling to running now !" << endl;
	pContext->Changestate(new runningstate());
}

runningstate::runningstate() {}
runningstate::~runningstate() {}
void runningstate::handle(Context* pContext)
{
	cout << "This is the running section now !" << endl;
	cout << "All triathlon events are over !" << endl;
}

Context::Context(state* pstate)
{
	this->_state = pstate;
}
Context::~Context() {}
void Context::Request()
{
	if (this->_state != NULL)
	{
		this->_state->handle(this);
	}
}
void Context::Changestate(state* pstate)
{
	this->_state = pstate;
}
int testState()
{
	state* pstate = new swimmingstate();
	Context* pContext = new Context(pstate);
	pContext->Request();
	pContext->Request();
	pContext->Request();
	pContext->Request();
	pContext->Request();
	delete pstate;
	delete pContext;

	cout << endl;

	return 0;
}