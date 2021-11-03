#pragma once
//设计模式--visitor模式类

#ifndef _visitor_H_
#define _visitor_H_

#include <list>
#include <string>
using namespace std;


class VisitorFootBall;
//私有对象类，保护初始化数据
class FootBallData{
public:
    FootBallData(){};
    ~FootBallData(){};
    void SetData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY);
    int RedPoint;
    int BluePoint;
    int RedFoulTimes;
    int BlueFoulTimes;
    string Countary;
};

//以足球为例
class FootBall {
private:
    FootBallData _footballdata;
    const std::string _name;
public:
    FootBall(const std::string& name);
    virtual ~FootBall() {};
    virtual void SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY){};
    virtual int RedPoint();
    virtual int BluePoint();
    virtual int RedFoulTimes();
    virtual int BlueFoulTimes();
    virtual string Countary();
};

//定义决赛类
class Final :public FootBall {
private:
    FootBallData _footballdata;
public:
    Final(const std::string& name);
    ~Final() override {};
    void SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    int RedPoint() override;
    int BluePoint() override;
    int RedFoulTimes() override;
    int BlueFoulTimes() override;
    string Countary() override;
};
//定义半决赛类
class SemiFinal :public FootBall {
private:
    FootBallData _footballdata;
public:
    SemiFinal(const std::string& name);
    ~SemiFinal() override {};
    virtual void SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    virtual int RedPoint() override;
    virtual int BluePoint() override;
    virtual int RedFoulTimes() override;
    virtual int BlueFoulTimes() override;
    virtual string Countary() override;
};

//定义小组赛类
class GroupGame :public FootBall {
private:
    FootBallData _footballdata;
public:
    GroupGame(const std::string& name);
    ~GroupGame() override {};
    void SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY) override;
    int RedPoint() override;
    int BluePoint() override;
    int RedFoulTimes() override;
    int BlueFoulTimes() override;
    string Countary() override;
};

class VisitorFootBall {
private:
    int _total = 0;
protected:
    VisitorFootBall() {};
public:
    virtual ~VisitorFootBall() {};
    virtual void Visit(Final*) {};
    virtual void Visit(SemiFinal*) {};
    virtual void Visit(GroupGame*) {};
};


class VisitorFootBallRedPoint : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallRedPoint() {};
    ~VisitorFootBallRedPoint() override {};
    int& GetRedPoint();
    void Visit(Final* final) override;
    void Visit(SemiFinal* semifinal1) override;
    void Visit(GroupGame* groupgame) override;
};

class VisitorFootBallBluePoint : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallBluePoint() {};
    ~VisitorFootBallBluePoint() override {};
    int& GetBluePoint();
    void Visit(Final* final) override;
    void Visit(SemiFinal* semifinal1) override;
    void Visit(GroupGame* groupgame) override;
};

class VisitorFootBallRedFoulTimes : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallRedFoulTimes() {};
    ~VisitorFootBallRedFoulTimes() override {};
    int& GetRedFoulTimes();
    void Visit(Final* final) override;
    void Visit(SemiFinal* semifinal1) override;
    void Visit(GroupGame* groupgame) override;
};

class VisitorFootBallBlueFoulTimes : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallBlueFoulTimes() {};
    ~VisitorFootBallBlueFoulTimes() override {};
    int& GetBlueFoulTimes();
    void Visit(Final* final) override;
    void Visit(SemiFinal* semifinal1) override;
    void Visit(GroupGame* groupgame) override;
};

class VisitorFootBallCountary : public VisitorFootBall {
private:
    string _total;
public:
    VisitorFootBallCountary() {};
    ~VisitorFootBallCountary() override {};
    string& GetCountary();
    void Visit(Final* final) override;
    void Visit(SemiFinal* semifinal1) override;
    void Visit(GroupGame* groupgame) override;
};

void testonVisitor();

#endif