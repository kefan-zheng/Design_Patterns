#pragma once
#include <iostream>
#include <string>

using namespace std;

//比赛对象信息类
class Game
{
private:
    string time;
    string place;
    string player;

public:
    void setTime(const std::string& part);
    void setPlace(const std::string& part);
    void setPlayer(const std::string& part);
    string get();

};

//创建比赛的抽象接口
class GameBuilder
{
protected:
    Game game;
public:
    //析构函数
    virtual ~GameBuilder() {}

    //获取比赛
    Game get();

    //虚函数
    virtual void buildTime() = 0;
    virtual void buildPlace() = 0;
    virtual void buildPlayer() = 0;

};

//击剑比赛创建者，继承自抽象比赛建造者
class FencingGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildPlayer();
};


//跆拳道比赛创建者，继承自抽象比赛建造者
class TaekwondoGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildPlayer();
};

//导演类，指导具体比赛的建造
class Director {
private:
    GameBuilder* builder;
public:
    Director() : builder() {}

    ~Director();

    void set(GameBuilder* b);

    //返回比赛
    Game get();

    void construct();
};

//测试函数
//创建击剑比赛和跆拳道比赛
int testBuilder();