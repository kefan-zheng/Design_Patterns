#include <iostream>
#include <string>
#include "Builder.h"

using namespace std;

//��������Ļ����޸���Ϣ����
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


//�������������ߣ��̳��Գ������������
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


//��ȭ�����������ߣ��̳��Գ������������
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
//����������������ȭ������
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