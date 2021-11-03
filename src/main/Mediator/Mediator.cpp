#include "Mediator.h"
using namespace std;

int CirtainPlayer::idCount = 0;

CirtainPlayer::CirtainPlayer(Mediator* const m) :
	mediator(m), ID(++idCount) {}

CirtainPlayer::~CirtainPlayer() {}

int CirtainPlayer::getID() {
	return this->ID;
}

//通过id得到队伍名称，1-5为
string getTeamName(int id) {
	if (id <= 5 && id >= 1) {
		return "Chinese Team";
	}
	else {
		return "Japanese Team";
	}
}


BasketballPlayer_PG::BasketballPlayer_PG(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer_PG::~BasketballPlayer_PG(){}

void BasketballPlayer_PG::BasketballPlayer_PG::send(std::string msg) {
	cout << "The point guard of " << getTeamName(ID) << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer_PG::receive(int senderID, std::string msg) {
	cout << "The point guard of " << getTeamName(ID) << " stops running, as a player of " << getTeamName(senderID) << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}


BasketballPlayer_SG::BasketballPlayer_SG(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer_SG::~BasketballPlayer_SG() {}

void BasketballPlayer_SG::BasketballPlayer_SG::send(std::string msg) {
	cout << "The point guard of " << getTeamName(ID) << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer_SG::receive(int senderID, std::string msg) {
	cout << "The point guard of " << getTeamName(ID) << " stops running, as a player of " << getTeamName(senderID) << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}


BasketballPlayer_SF::BasketballPlayer_SF(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer_SF::~BasketballPlayer_SF() {}

void BasketballPlayer_SF::BasketballPlayer_SF::send(std::string msg) {
	cout << "The small forward of " << getTeamName(ID) << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer_SF::receive(int senderID, std::string msg) {
	cout << "The small forward of " << getTeamName(ID) << " stops running, as a player of " << getTeamName(senderID) << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}


BasketballPlayer_PF::BasketballPlayer_PF(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer_PF::~BasketballPlayer_PF() {}

void BasketballPlayer_PF::BasketballPlayer_PF::send(std::string msg) {
	cout << "The power forward of " << getTeamName(ID) << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer_PF::receive(int senderID, std::string msg) {
	cout << "The power forward of " << getTeamName(ID) << " stops running, as a player of " << getTeamName(senderID) << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}

BasketballPlayer_C::BasketballPlayer_C(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer_C::~BasketballPlayer_C() {}

void BasketballPlayer_C::BasketballPlayer_C::send(std::string msg) {
	cout << "The center forward of " << getTeamName(ID) << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer_C::receive(int senderID, std::string msg) {
	cout << "The center forward of " << getTeamName(ID) << " stops running, as a player of " << getTeamName(senderID) << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}

ConcreteMediator::ConcreteMediator() {}
void ConcreteMediator::add(CirtainPlayer* const p) {
	playerList.push_back(p);
	cout << "Player" << p->getID() << "(" << getTeamName(p->getID()) << ") join the basketball game.\n";
}

void ConcreteMediator::distribute(int senderID, string msg) {
	for (auto player : playerList) {
		if (senderID != player->getID()) {
			player->receive(senderID, msg);
		}
	}
}

ConcreteMediator::~ConcreteMediator() {
	for (auto player : playerList) {
		delete[] player;
	}
	playerList.clear();
}

void MediatorTest() {
	Mediator* game = new ConcreteMediator();//中介者，这里可以理解为裁判

	//依次添加10个篮球运动员，对应双方篮球赛的10名队员
	CirtainPlayer* p1 = new BasketballPlayer_PG(game);
	CirtainPlayer* p2 = new BasketballPlayer_SG(game);
	CirtainPlayer* p3 = new BasketballPlayer_SF(game);
	CirtainPlayer* p4 = new BasketballPlayer_PF(game);
	CirtainPlayer* p5 = new BasketballPlayer_C(game);
	CirtainPlayer* p6 = new BasketballPlayer_PG(game);
	CirtainPlayer* p7 = new BasketballPlayer_SG(game);
	CirtainPlayer* p8 = new BasketballPlayer_SF(game);
	CirtainPlayer* p9 = new BasketballPlayer_PF(game);
	CirtainPlayer* p10 = new BasketballPlayer_C(game);

	game->add(p1);
	game->add(p2);
	game->add(p3);
	game->add(p4);
	game->add(p5);
	game->add(p6);
	game->add(p7);
	game->add(p8);
	game->add(p9);
	game->add(p10);

	p1->send("I ask to pause the game!");//p1要求停止比赛，通知裁判。裁判同意后要求其他运动员也停下
	p7->send("Please pause the game right now!");//p7要求停止比赛，通知裁判。裁判同意后要求其他运动员也停下
}