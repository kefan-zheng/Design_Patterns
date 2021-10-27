#include <iostream>
#include <string>
#include "Builder.h"

using namespace std;

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


//游泳比赛创建者，继承自抽象比赛建造者
void SwimmingGameBuilder::buildTime()
{
    game.setTime("11.06");
}
void SwimmingGameBuilder::buildPlace()
{
    game.setPlace("SwimmingPool");
}
void SwimmingGameBuilder::buildPlayer()
{
    game.setPlayer("Phelps");
}


//跑步比赛创建者，继承自抽象比赛建造者
void RunningGameBuilder::buildTime()
{
    game.setTime("11.06");
}
void RunningGameBuilder::buildPlace()
{
    game.setPlace("TAF-Ground");
}
void RunningGameBuilder::buildPlayer()
{
    game.setPlayer("Bolt");
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
//创建游泳比赛和跑步比赛
int testBuilder()
{
    Director director;
    director.set(new SwimmingGameBuilder);
    director.construct();

    Game game1 = director.get();
    std::cout << "1st game: " << game1.get() << std::endl;

    director.set(new RunningGameBuilder);
    director.construct();

    Game game2 = director.get();
    cout << "2nd game: " << game2.get() << endl;

    cout << endl;

    return 0;
}