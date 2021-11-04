#pragma once
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

    string getNation()
    {
        return nation;
    }

    void setNation(string nation)
    {
        this->nation = nation;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

private:
    string nation;
    string name;
};

//视图View类StudentView
class PlayerView
{
public:
    PlayerView() {};
    ~PlayerView() {};

    void playerDetails(string name, string nation)
    {
        cout << "Player: " << endl
            << "Name: " << name << endl
            << "Nation: " << nation << endl;
    }
};

//controller控制器类StudentController
class PlayerController
{
public:
    PlayerController(Player model, PlayerView view)
    {
        this->model = model;
        this->view = view;
    }

    ~PlayerController() {};

    void setPlayerName(string name)
    {
        this->model.setName(name);
    }

    string getPlayerName()
    {
        return this->model.getName();
    }

    void setPlayerNation(string nation)
    {
        this->model.setNation(nation);
    }

    string getPlayerNation()
    {
        return this->model.getNation();
    }

    void updateView()
    {
        this->view.playerDetails(this->model.getName(), this->model.getNation());
    }

private:
    Player model;
    PlayerView view;
};

int testMVC();

#endif //MVC_MVC_H
