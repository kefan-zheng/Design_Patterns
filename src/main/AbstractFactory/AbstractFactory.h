
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;
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
    RunningGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState, int num) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        elapsedTime = 0;
        distance = 100;
        for (int i = 0; i < num; ++i)sportsmanState.push_back(0), distanceTravelled.push_back(0), score.push_back(0);
    }
    //获取信息函数
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
    ~TableTennisGameProduct() {};
    TableTennisGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        bigScore[0] = bigScore[1] = smallScore[0] = smallScore[1] = 0;
        location[0] = location[1] = false;
    }
    const int* getbigScore();
    const int* getsmallScore();
    const bool* getlocation();
    //设置函数
    void setbigScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++bigScore[i]; 
    }
    void setsmallScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++smallScore[i]; 
    }
    void flipLocation() {
        swap(location[0], location[1]);
    }
};


//抽象工厂
template<class T>
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
};

//乒乓球工厂，继承自抽象工厂
class TableTennisFactory : public AbstractFactory<TableTennisGameProduct>
{
public:
    ~TableTennisFactory() {}
    TableTennisGameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new TableTennisGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};
//跑步工厂，继承自抽象工厂
class RunningFactory {
public:
    ~RunningFactory() {}
    RunningGameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState,int num) {
        return new RunningGameProduct(cN, sT, cS, sName, sNation, cState, num);
    }
};
