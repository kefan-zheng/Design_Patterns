#include <iostream>
using namespace std;
#include "chain_of_responsibility.h"

int main()
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
    system("pause");
    return 0;
}