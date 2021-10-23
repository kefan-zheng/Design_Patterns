//
// Created by xzb23 on 2021/10/23.
//

#ifndef MVC_MVC_H
#define MVC_MVC_H
#include <iostream>
#include <string>
using  namespace std;
class Player
{
public:
    Player() {};
    ~Player() {};

    string getNation();
    void setNation(string nation);
    string getName();
    void setName(string name);

private:
    string nation;
    string name;
};

string Player ::getNation()
{
    return nation;
}

void Player::setNation(string nation)
{
    this->nation = nation;
}

string Player::getName()
{
    return name;
}

void Player::setName(string name)
{
    this->name = name;
}

//视图View类StudentView
class PlayerView
{
public:
    PlayerView() {};
    ~PlayerView() {};

    void playerDetails(string name, string nation);
};

void PlayerView::playerDetails(string name, string nation)
{
    cout << "Player: " << endl
         << "Name: " << name << endl
         << "Nation: " << nation<< endl;
}

//controller控制器类StudentController
class PlayerController
{
public:
    PlayerController(Player model, PlayerView view);
    ~PlayerController() {};

    void setPlayerName(string name);
    string getPlayerName();
    void setPlayerNation(string nation);
    string getPlayerNation();
    void updateView();
private:
    Player model;
    PlayerView view;
};

PlayerController::PlayerController(Player model, PlayerView view)
{
    this->model = model;
    this->view = view;
}

void PlayerController::setPlayerName(string name)
{
    this->model.setName(name);
}

string PlayerController::getPlayerName()
{
    return this->model.getName();
}

void PlayerController::setPlayerNation(string nation)
{
    this->model.setNation(nation);
}

string PlayerController::getPlayerNation()
{
    return this->model.getNation();
}

void PlayerController::updateView()
{
    this->view.playerDetails(this->model.getName(), this->model.getNation());
}
#endif //MVC_MVC_H
