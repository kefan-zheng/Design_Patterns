#include <iostream>
#include <string>
#include "Builder.h"

using namespace std;

//比赛对象的基本修改信息函数
void Game::setTime(const string& part)
{
    time = part;
}                                                 

void Game::setPlace(const string& part)
{
    place = part;
}

void Game::setPlayer(const string& part)
{
    player = part;
}
    
string Game::get()
{
    return ("\nTime:" + time + "\nPlace:" + place + "\nPlayer:" + player);
}


//创建比赛的抽象接口
//获取比赛
Game GameBuilder::get()
{
    return game;
}


//击剑比赛创建者，继承自抽象比赛建造者
void FencingGameBuilder::buildTime()
{
    game.setTime("11.06");
}
void FencingGameBuilder::buildPlace()
{
    game.setPlace("Fencing-Hall");
}
void FencingGameBuilder::buildPlayer()
{
    game.setPlayer("Yiwen Sun && Popescu");
}


//跆拳道比赛创建者，继承自抽象比赛建造者
void TaekwondoGameBuilder::buildTime()
{
    game.setTime("11.06");
}
void TaekwondoGameBuilder::buildPlace()
{
    game.setPlace("TAF-Ground");
}
void TaekwondoGameBuilder::buildPlayer()
{
    game.setPlayer("Bolt && Shuai Zhao");
}

//导演类，指导具体比赛的建造
Director::~Director()
{
    if (builder)
    {
        delete builder;
    }
}

void Director::set(GameBuilder* b)
{
    //生成新的builder
    if (builder)
    {
        delete builder;
    }
    builder = b;
}

//返回比赛
Game Director::get()
{
    return builder->get();
}

void Director::construct()
{
    builder->buildTime();
    builder->buildPlace();
    builder->buildPlayer();
}

//测试函数
//创建击剑比赛和跆拳道比赛
int testBuilder()
{
    Director director;
    director.set(new FencingGameBuilder);
    director.construct();

    std:cout << "The next two games are as follows:\n";

    Game game1 = director.get();
    std::cout << "1st game: " << game1.get() << std::endl;

    director.set(new TaekwondoGameBuilder);
    director.construct();

    Game game2 = director.get();
    cout << "2nd game: " << game2.get() << endl;

    cout << endl;

    return 0;
}