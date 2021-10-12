#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mediator;

class Player {

public:
	static int idCount;
	Player(Mediator* const m) :
		mediator(m), ID(++idCount) {}

	~Player() {}

	int getID() {
		return this->ID;
	}

	virtual void send(std::string msg) = 0;
	virtual void receive(int senderID, std::string msg) = 0;
protected:
	int ID;
	Mediator* mediator;
};

class ConcretePlayer : public Player {
public:
	ConcretePlayer(Mediator* const m) :
		Player(m) {}
	~ConcretePlayer() {}

	void send(std::string msg);

	void receive(int senderID, std::string msg) {
		cout << "Player" << this->getID() << " stops, as Player" << senderID << " said" << " \"" << msg << "\".\n";;
	}
};



/*
* defines a interface class of players
*/
class Mediator {
public:
	virtual void add(Player* const p) = 0;
	virtual void distribute(int senderID, string msg) = 0;
};

class ConcreteMediator : public Mediator {
public:
	ConcreteMediator() {}
	void add(Player* const p) {
		playerList.push_back(p);
		cout << "Player" << p->getID() << " join the competition.\n";
	}
	void distribute(int senderID, string msg) {
		for (auto player : playerList) {
			if (senderID != player->getID()) {
				player->receive(senderID, msg);
			}
		}
	}
	~ConcreteMediator() {
		for (auto player : playerList) {
			delete[] player;
		}
		playerList.clear();
	}
private:
	vector<Player*> playerList;
};
