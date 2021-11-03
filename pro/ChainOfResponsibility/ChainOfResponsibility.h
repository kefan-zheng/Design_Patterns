#pragma once
#ifndef _CHAIN_OF_RESPONSIBILITY_H_
#define _CHAIN_OF_RESPONSIBILITY_H_


#include <iostream>
using namespace std;

class Handler
{
public:
    Handler(){NextHandler = NULL;}
    virtual ~Handler(){}

    void SetNextHandler(Handler *next){NextHandler = next;}

    virtual void HandleRequest(int level){};
protected:
    Handler *NextHandler;
};

class InterimCommittee:public Handler
{
public:
    virtual void HandleRequest(int level)
    {
        if(level <= 1)
        {
            cout<<""<<endl;
        }
        else
        {
            NextHandler->HandleRequest(level);
        }
    }
};

class ExecutiveCommittee:public Handler
{
public:
    virtual void HandleRequest(int level)
    {
        if(level <= 2)
        {
            cout<<"2"<<endl;
        }
        else
        {
            NextHandler->HandleRequest(level);
        }
    }
};

class PlenarySession:public Handler
{
public:
    virtual void HandleRequest(int level)
    {
        if(level <= 3)
        {
            cout<<"3"<<endl;
        }
        else
        {
            cerr<<"4"<<endl;
        }
    }
};

int testChainOfResponsibility();

#endif