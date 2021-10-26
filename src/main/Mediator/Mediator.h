#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mediator;

/*
 *  CirtainPlayer: 代表某种球员的类
 *  每个CirtainPlayer都有一个指向Mediator的指针，可以理解为对应一个裁判
 *  球员不能直接处理场上发生事件，要以裁判为中介来传达自己意图
 */
class CirtainPlayer {
public:
	static int idCount;//记录已经加入了多少个球员，并以此作为新球员编号
	CirtainPlayer(Mediator* const m);//构造时传入Mediator*，可视为裁判
	~CirtainPlayer();
	int getID();//获取球员编号
	virtual void send(string msg) = 0; //发送信息给Mediator
	virtual void receive(int senderID, string msg) = 0; //接收来自Mediator的信息
protected:
	int ID;//球员编号
	Mediator* mediator;//可视为裁判
};


/*
 *  BasketballPlayer: 篮球队员类
 *  重载了CirtainPlay类中的虚函数send()与receive()，发送与接收信息都与篮球赛有关
 */
class BasketballPlayer : public CirtainPlayer {
public:
	BasketballPlayer(Mediator* const m);
	~BasketballPlayer();

	void send(std::string msg);//发送与篮球赛有关信息
	void receive(int senderID, std::string msg);//接收与篮球赛有关信息
};


/*
*  Mediator: 中介者抽象类
*/
class Mediator {
public:
	virtual void add(CirtainPlayer* const p) = 0;
	virtual void distribute(int senderID, string msg) = 0;
};


/*
*  ConcreteMediator: 篮球比赛的裁判
*/
class ConcreteMediator : public Mediator {
public:
	ConcreteMediator();
	void add(CirtainPlayer* const p);//添加球赛运动员
	void distribute(int senderID, string msg);//将信息分发转告给各运动员
	~ConcreteMediator();
private:
	vector<CirtainPlayer*> playerList;//参与比赛的运动员列表
};

void MediatorTest();//测试函数