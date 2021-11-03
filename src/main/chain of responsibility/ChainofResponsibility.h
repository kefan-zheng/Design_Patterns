#ifndef _CHAINOFRESPONSIBILITY_H_
#define _CHAINOFRESPONSIBILITY_H_


#include <iostream>
using namespace std;

class Handler
{
public:
    Handler();
    virtual ~Handler();
    void SetNextHandler(Handler* next);
    virtual void HandleRequest(int level);
protected:
    Handler* NextHandler;
};

class InterimCommittee:public Handler
{
public:
    InterimCommittee();
    ~InterimCommittee() override;
    void HandleRequest(int level);
};

class ExecutiveCommittee:public Handler
{
public:
    ExecutiveCommittee();
    ~ExecutiveCommittee() override;
    void HandleRequest(int level);
};

class PlenarySession:public Handler
{
public:
    PlenarySession();
    ~PlenarySession() override;
    void HandleRequest(int level);
};

#endif