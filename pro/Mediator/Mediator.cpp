#include "Mediator.h"
using namespace std;

int CirtainPlayer::idCount = 0;

CirtainPlayer::CirtainPlayer(Mediator* const m) :
	mediator(m), ID(++idCount) {}

CirtainPlayer::~CirtainPlayer() {}

int CirtainPlayer::getID() {
	return this->ID;
}

BasketballPlayer::BasketballPlayer(Mediator* const m) :
	CirtainPlayer(m) {}

BasketballPlayer::~BasketballPlayer(){}

void BasketballPlayer::BasketballPlayer::send(std::string msg) {
	cout << "Player" << this->getID() << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

void BasketballPlayer::receive(int senderID, std::string msg) {
	cout << "Basketball Player" << this->getID() << " stops, as Player" << senderID << " said" << " \"" << msg << "\" and the referee agrees to pause the game. \n";;
}

ConcreteMediator::ConcreteMediator() {}
void ConcreteMediator::add(CirtainPlayer* const p) {
	playerList.push_back(p);
	cout << "Player" << p->getID() << " join the basketball game.\n";
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

int testMediator() {
	Mediator* game = new ConcreteMediator();//中介者，这里可以理解为裁判

	//依次为中介者添加三个篮球运动员，一场球赛可能有更多运动员，这里只加了三个，仅仅用于模拟
	CirtainPlayer* p1 = new BasketballPlayer(game);
	CirtainPlayer* p2 = new BasketballPlayer(game);
	CirtainPlayer* p3 = new BasketballPlayer(game);
	game->add(p1);
	game->add(p2);
	game->add(p3);

	p1->send("I ask to pause the game!");//p1要求停止比赛，通知裁判。裁判同意后要求其他运动员也停下
	p2->send("Please pause the game right now!");//p2要求停止比赛，通知裁判。裁判同意后要求其他运动员也停下
	cout << endl;
	return 0;
}
