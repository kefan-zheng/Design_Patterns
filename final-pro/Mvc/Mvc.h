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

    string getName();
    void setName(string name);
    void setScore(int i,int score)
    {
        Score[i-1]=score;
    }
    int getScore(int i)
    {
        return Score[i-1];
    }
private:
    string name;
    int Score[3];
};




//视图View类StudentView
class PlayerView
{
public:
    PlayerView() {};
    ~PlayerView() {};

    void playerDetails(Player player);
};



//controller控制器类StudentController
class PlayerController
{
public:
    PlayerController(){};
    PlayerController(Player model, PlayerView view);
    ~PlayerController() {};

    void setPlayerName(string name);
    string getPlayerName();

    void setPlayerScore(int i,int score)
    {
        this->model.setScore(i,score);
    };
    int getPlayerScore(int i)
    {
        return this->model.getScore(i);
    };
    void updateView();
private:
    Player model;
    PlayerView view;
};

int testMvc();
#endif //MVC_MVC_H
