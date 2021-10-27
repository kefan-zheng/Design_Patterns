#pragma once
#include <iostream>
#include <string>

class Game
{
private:
    std::string time;
    std::string place;
    std::string player;
public:
    void setTime(const std::string& part);
    void setPlace(const std::string& part);
    void setPlayer(const std::string& part);
    std::string get();

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

//��Ӿ���������ߣ��̳��Գ������������
class SwimmingGameBuilder : public GameBuilder
{
public:
    void buildTime();
    void buildPlace();
    void buildPlayer();
};


//�ܲ����������ߣ��̳��Գ������������
class RunningGameBuilder : public GameBuilder
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
//������Ӿ�������ܲ�����
int testBuilder();