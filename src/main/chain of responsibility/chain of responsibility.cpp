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
            cout<<"�����Ѿ�������ʱίԱ�ᴦ��,�����ĵȴ���"<<endl;
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
            cout<<"�����Ѿ����ɰ�ί�����鴦����,�����ĵȴ���"<<endl;
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
            cout<<"�����Ѿ����ɰ�ί��ȫ�ᴦ��,�����ĵȴ���"<<endl;
        }
        else
        {
            cerr<<"Ȩ������"<<endl;
        }
    }
};

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