#pragma once
#include<vector>
#include <iostream>

using namespace std;
//本例子中只有一个乒乓球工厂，产生多个比赛项目
 //单人比赛
class GameProduct
{
public:
    string contestName;
    string startTime;
    string contestSite;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
    //比赛状态变量，0表示未开始，1表示正在进行，2表示比赛暂停，3表示比赛结束
    int contestState;
    //析构函数
    virtual ~GameProduct() {}
    //纯虚函数
    virtual const string getcontestName() = 0;
    virtual const string getstartTime() = 0;
    virtual const string getcontestSite() = 0;
    virtual const vector<string> getsportsmanName() = 0;
    virtual const vector<string> getsportsmanNation() = 0;
    virtual const int getcontestState() = 0;
};

//跑步比赛
class RunningGameProduct : public GameProduct
{
private:
    double elapsedTime;
    //百米赛跑，初始化为100
    double distance;
    //运动员比赛完成状态，元素数量等于运动员数量，初始化为[0,...,0]
    vector<bool> sportsmanState;
    //表示运动员距离起点的距离，元素数量等于运动员数量，初始化为[0,...,0]
    vector<double> distanceTravelled;
    //表示运动员比赛成绩
    vector<double> score;
public:
    ~RunningGameProduct() {}
    //纯虚函数的实现
    const string getcontestName();
    const string getstartTime();
    const string getcontestSite();
    const vector<string> getsportsmanName();
    const vector<string> getsportsmanNation();
    const int getcontestState();

    const double getelapsedTime();
    const double getdistance();
    const vector<bool> getsportsmanState();
    const vector<double> getdistanceTravelled();
    const vector<double> getscore();

    //设置函数
    void setelapsedTime(double para);
    void setsportsmanState(vector<bool> para);
    void setdistanceTravelled(vector<double> para);
    void setscore(vector<double> para);
    void setcontestState(int para);
};

//乒乓球比赛
class TableTennisGameProduct : public GameProduct
{
private:
    //大比分
    int bigScore[2];
    //小比分
    int smallScore[2];
    //运动员相对球桌的位置，false代表站在左边，true代表站在右边
    bool location[2];
public:
    ~TableTennisGameProduct() {}
    //纯虚函数的实现
    const string getcontestName();
    const string getstartTime();
    const string getcontestSite();
    const vector<string> getsportsmanName();
    const vector<string> getsportsmanNation();
    const int getcontestState();

    const int* getbigScore();
    const int* getsmallScore();
    const bool getlocation();
    //设置函数
    void setbigScore(int para);
    void setsmallScore(int para);
    void setlocation(bool para);
    void setcontestState(int para);
};


//抽象工厂
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    //两个产品
    virtual RunningGameProduct* createRunningGameProduct() = 0;
    virtual TableTennisGameProduct* createTableTennisGameProduct() = 0;
};

//乒乓球工厂，继承自抽象工厂
class GameFactory : public AbstractFactory
{
public:
    ~GameFactory() {}

    RunningGameProduct* createRunningGameProduct();

    TableTennisGameProduct* createTableTennisGameProduct();
};

int testAbstractFactory();