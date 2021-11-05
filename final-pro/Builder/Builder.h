#pragma once
#include <iostream>
#include <string>

using namespace std;

//����������Ϣ��
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

//���������ĳ���ӿ�
class GameBuilder
{
protected:
    Game game;
public:
    //��������
    virtual ~GameBuilder() {}

    //��ȡ����
    Game get();

    //�麯��
    virtual void buildTime() = 0;
    virtual void buildPlace() = 0;
    virtual void buildPlayer() = 0;

};

//�������������ߣ��̳��Գ������������
class FencingGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildPlayer();
};


//��ȭ�����������ߣ��̳��Գ������������
class TaekwondoGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildPlayer();
};

//�����ָ࣬����������Ľ���
class Director {
private:
    GameBuilder* builder;
public:
    Director() : builder() {}

    ~Director();

    void set(GameBuilder* b);

    //���ر���
    Game get();

    void construct();
};

//���Ժ���
//����������������ȭ������
int testBuilder();