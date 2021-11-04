#pragma once
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

class Props
{
private:
    string propsName;
public:
    ~Props() {}
    Props(string name) : propsName(name) {}

    string getPropsName() { return propsName; }
    virtual void display() = 0;
};

class Timer : public Props
{
public:
    Timer(string name) : Props(name) {}
    ~Timer() {}

    virtual void display() {
        cout << "Timer" << endl;
    }
};

class Table : public Props
{
public:
    Table(string name) : Props(name) {}
    ~Table() {}

    virtual void display() {
        cout << "Table" << endl;
    }
};

//本例子中只有一个乒乓球工厂，产生多个比赛项目
 //单人比赛
class GameProduct
{
private:
    string contestName;
    string startTime;
    string contestSite;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
    //比赛状态变量，0表示未开始，1表示正在进行，2表示比赛暂停，3表示比赛结束
    int contestState;
public:
    GameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        contestName(cN), startTime(sT), contestSite(cS), sportsmanName(sName), sportsmanNation(sNation), contestState(cState) {}
    const string getcontestName() {
        return contestName;
    }
    const string getstartTime() {
        return startTime;
    }
    const string getcontestSite() {
        return contestSite;
    }
    const vector<string> getsportsmanName() {
        return sportsmanName;
    }
    const vector<string> getsportsmanNation() {
        return sportsmanNation;
    }
    const int getcontestState() {
        return contestState;
    };
    void setContestState(int state) {
        contestState = state;
    }
    //跑步的虚函数
    //获取信息函数
    virtual const double getelapsedTime() { return 0; }
    virtual const double getdistance() { return 0; }
    virtual const vector<double> getdistanceTravelled() { vector<double>null; return null; }
    virtual const vector<double> getscore() { vector<double>null; return null; }
    //设置函数
    virtual void setelapsedTime(double para){}
    virtual void setdistanceTravelled(vector<double> para){}
    virtual void setscore(vector<double> para){}

    //乒乓球的虚函数
    virtual int getScore1() { return 0; }
    virtual int getScore2() { return 0; }
        
    //设置函数
    virtual void setScore(int i) {}
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
    Timer* timer;
public:
    ~RunningGameProduct() {}
    RunningGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        timer = new Timer("timer1");
        elapsedTime = 0;
        distance = 100;
        for (int i = 0; i < sName.size(); ++i)sportsmanState.push_back(0), distanceTravelled.push_back(0), score.push_back(0);
    }
    //获取信息函数
    virtual const double getelapsedTime();
    virtual const double getdistance();
    virtual const vector<double> getdistanceTravelled();
    virtual const vector<double> getscore();
    //设置函数
    virtual void setelapsedTime(double para);
    virtual void setdistanceTravelled(vector<double> para);
    virtual void setscore(vector<double> para);

};

//乒乓球比赛
class TableTennisGameProduct : public GameProduct
{
private:
    int Score[2];
    Table* table;
public:
    ~TableTennisGameProduct() {};
    TableTennisGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        table = new Table("table1");
       Score[0] = Score[1] = 0;
    }
    virtual int getScore1() {
        return Score[0];
    }
    virtual int getScore2() {
        return Score[1];
    }
    //设置函数
    virtual void setScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++Score[i]; 
    }
};


//抽象工厂

class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) = 0;
};

//乒乓球工厂，继承自抽象工厂
class TableTennisFactory : public AbstractFactory
{
public:
    ~TableTennisFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new TableTennisGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};
//跑步工厂，继承自抽象工厂
class RunningFactory :public AbstractFactory
{
public:
    ~RunningFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new RunningGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};

