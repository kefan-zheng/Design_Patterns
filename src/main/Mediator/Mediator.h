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
	static int idCount;//��¼�Ѿ������˶��ٸ���Ա�����Դ���Ϊ����Ա���
	CirtainPlayer(Mediator* const m);//����ʱ����Mediator*������Ϊ����
	~CirtainPlayer();
	int getID();//��ȡ��Ա���
	virtual void send(string msg) = 0; //������Ϣ��Mediator
	virtual void receive(int senderID, string msg) = 0; //��������Mediator����Ϣ
protected:
	int ID;//��Ա���
	Mediator* mediator;//����Ϊ����
};


/*
 *  BasketballPlayer: �����Ա��
 *  ������CirtainPlay���е��麯��send()��receive()�������������Ϣ�����������й�
 */
class BasketballPlayer : public CirtainPlayer {
public:
	BasketballPlayer(Mediator* const m);
	~BasketballPlayer();

	void send(std::string msg);//�������������й���Ϣ
	void receive(int senderID, std::string msg);//�������������й���Ϣ
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