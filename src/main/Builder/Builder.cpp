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



//���������ĳ���ӿ�
//��ȡ����
Game GameBuilder::get()
{
    return game;
}


//��Ӿ���������ߣ��̳��Գ������������
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


//�ܲ����������ߣ��̳��Գ������������
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

//�����ָ࣬����������Ľ���
Director::~Director()
{
    if (builder)
    {
        delete builder;
    }
}

void Director::set(GameBuilder* b)
{
    //�����µ�builder
    if (builder)
    {
        delete builder;
    }
    builder = b;
}

//���ر���
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

//���Ժ���
//������Ӿ�������ܲ�����
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