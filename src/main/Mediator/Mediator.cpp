#include "Mediator.h"
using namespace std;

void ConcretePlayer::send(std::string msg) {
	cout << "Player" << this->getID() << " says:" << "\"" << msg << "\".\n";
	this->mediator->distribute(getID(), msg);
}

int Player::idCount = 0;
