#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mediator;

/*
 *  CirtainPlayer: ����ĳ����Ա����
 *  ÿ��CirtainPlayer����һ��ָ��Mediator��ָ�룬�������Ϊ��Ӧһ������
 *  ��Ա����ֱ�Ӵ����Ϸ����¼���Ҫ�Բ���Ϊ�н��������Լ���ͼ
 */
class CirtainPlayer {
public:
	CirtainPlayer(Mediator* const m);//����ʱ����Mediator*������Ϊ����
	~CirtainPlayer();
	int getID();//��ȡ��Ա���
	virtual void send(string msg) = 0; //������Ϣ��Mediator
	virtual void receive(int senderID, string msg) = 0; //��������Mediator����Ϣ
private:
	static int idCount;//��¼�Ѿ������˶��ٸ���Ա�����Դ���Ϊ����Ա���
protected:
	int ID;//��Ա���
	Mediator* mediator;//����Ϊ����
};


/*
 *  BasketballPlayer_PG: ����ӿ������
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer_PG : public CirtainPlayer {
public:
	BasketballPlayer_PG(Mediator* const m);
	~BasketballPlayer_PG();

	void send(string msg);//�������������й���Ϣ
	void receive(int senderID, string msg);//�������������й���Ϣ
};


/*
 *  BasketballPlayer_SG: ����ӵ÷ֺ���
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer_SG : public CirtainPlayer {
public:
	BasketballPlayer_SG (Mediator* const m);
	~BasketballPlayer_SG();

	void send(string msg);//�������������й���Ϣ
	void receive(int senderID, string msg);//�������������й���Ϣ
};


/*
 *  BasketballPlayer_SF: �����Сǰ��
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer_SF : public CirtainPlayer {
public:
	BasketballPlayer_SF(Mediator* const m);
	~BasketballPlayer_SF();

	void send(string msg);//�������������й���Ϣ
	void receive(int senderID, string msg);//�������������й���Ϣ
};


/*
 *  BasketballPlayer_PF: ����Ӵ�ǰ��
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer_PF : public CirtainPlayer {
public:
	BasketballPlayer_PF(Mediator* const m);
	~BasketballPlayer_PF();

	void send(string msg);//�������������й���Ϣ
	void receive(int senderID, string msg);//�������������й���Ϣ
};


/*
 *  BasketballPlayer_C: ������з�
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer_C : public CirtainPlayer {
public:
	BasketballPlayer_C(Mediator* const m);
	~BasketballPlayer_C();

	void send(string msg);//�������������й���Ϣ
	void receive(int senderID, string msg);//�������������й���Ϣ
};



/*
*  Mediator: �н��߳�����
*/
class Mediator {
public:
	virtual void add(CirtainPlayer* const p) = 0;
	virtual void distribute(int senderID, string msg) = 0;
};


/*
*  ConcreteMediator: ��������Ĳ���
*/
class ConcreteMediator : public Mediator {
public:
	ConcreteMediator();
	void add(CirtainPlayer* const p);//��������˶�Ա
	void distribute(int senderID, string msg);//����Ϣ�ַ�ת������˶�Ա
	~ConcreteMediator();
private:
	vector<CirtainPlayer*> playerList;//����������˶�Ա�б�
};

void MediatorTest();//���Ժ���