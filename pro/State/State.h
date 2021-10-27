#pragma once
#ifndef _STATE_H_
#define _STATE_H_
class Context;
class state
{
public:
	state();
	virtual ~state();
	virtual void handle(Context* pContext) = 0;
};
class swimmingstate :public state
{
public:
	swimmingstate();
	~swimmingstate();
	virtual void handle(Context* pContext);
};
class TransitionSectionA :public state
{
public:
	TransitionSectionA();
	~TransitionSectionA();
	virtual void handle(Context* pContext);
};
class cyclingstate :public state
{
public:
	cyclingstate();
	~cyclingstate();
	virtual void handle(Context* pContext);
};
class TransitionSectionB :public state
{
public:
	TransitionSectionB();
	~TransitionSectionB();
	virtual void handle(Context* pContext);
};
class runningstate :public state
{
public:
	runningstate();
	~runningstate();
	virtual void handle(Context* pContext);
};
class Context
{
public:
	Context(state* pstate);
	~Context();
	void Request();
	void Changestate(state* pstate);
private:
	state* _state;
};

int testState();

#endif // !_STATE_H_
