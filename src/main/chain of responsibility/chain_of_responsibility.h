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
            cout<<"申诉已经交由临时委员会处理,请耐心等待！"<<endl;
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
            cout<<"申诉已经交由奥委会秘书处处理,请耐心等待！"<<endl;
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
            cout<<"申诉已经交由奥委会全会处理,请耐心等待！"<<endl;
        }
        else
        {
            cerr<<"权级有误！"<<endl;
        }
    }
};

#endif