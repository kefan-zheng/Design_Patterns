#include <iostream>
#include "ChainOfResponsibility.h"

using namespace std;

int testChainOfResponsibility()
{
    Handler *interimcommittee = new InterimCommittee;
    Handler *executivecommittee = new ExecutiveCommittee;
    Handler *plenarysession = new PlenarySession;

    interimcommittee->SetNextHandler(executivecommittee);
    executivecommittee->SetNextHandler(plenarysession);

    interimcommittee->HandleRequest(1);
    interimcommittee->HandleRequest(2);
    interimcommittee->HandleRequest(3);
    interimcommittee->HandleRequest(8);
    
    cout << endl;

    return 0;
}