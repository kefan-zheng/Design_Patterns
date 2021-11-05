#include <iostream>
#include "ChainofResponsibility.h"
using namespace std;

Handler::Handler(){NextHandler = NULL;}
Handler::~Handler(){}
void Handler::SetNextHandler(Handler *next){NextHandler = next;}
void Handler::HandleRequest(int level){}

InterimCommittee::InterimCommittee(){}
//释放指针空间
InterimCommittee::~InterimCommittee()
{
    free(NextHandler);
}
//处理请求函数
void InterimCommittee::HandleRequest(int level)
{
    if(level <= 1)//判断权级
    {
        cout << "Appeal has been handed over to InterimCommittee. Please wait patiently." << endl;
    }
    else//不满足则移交给下一处理者
    {
        NextHandler->HandleRequest(level);
    }
}

ExecutiveCommittee::ExecutiveCommittee(){}
//释放指针空间
ExecutiveCommittee::~ExecutiveCommittee()
{
    free(NextHandler);
}
//处理请求函数
void ExecutiveCommittee::HandleRequest(int level)
{
    if(level <= 2)//判断权级
    {
        cout << "Appeal has been handed over to ExecutiveCommittee. Please wait patiently." << endl;
    }
    else//不满足则移交给下一处理者
    {
        NextHandler->HandleRequest(level);
    }
}

PlenarySession::PlenarySession(){}
//释放指针空间
PlenarySession::~PlenarySession()
{
    free(NextHandler);
}
//处理请求函数
void PlenarySession::HandleRequest(int level)
{
    if(level <= 3)//判断权级
    {
        cout << "Appeal has been handed over to PlenarySession. Please wait patiently." << endl;
    }
    else//不满足则移交给下一处理者
    {
        cerr << "Wrong power level!" << endl;
    }
}


void testChainOfResponsibility()
{
    Handler* interimcommittee = new InterimCommittee;
    Handler* executivecommittee = new ExecutiveCommittee;
    Handler* plenarysession = new PlenarySession;

    cout << "A player appealed to the organizing committee.\n";

    interimcommittee->SetNextHandler(executivecommittee);
    executivecommittee->SetNextHandler(plenarysession);

    interimcommittee->HandleRequest(1);
    interimcommittee->HandleRequest(2);
    interimcommittee->HandleRequest(3);
    interimcommittee->HandleRequest(8);
    //system("pause");
}