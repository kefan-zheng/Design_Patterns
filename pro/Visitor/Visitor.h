#pragma once
//设计模式--visitor模式类
//目前代码用于双方对抗性比赛上

#ifndef _visitor_H_
#define _visitor_H_

#include <list>
#include <string>
using namespace std;


class VisitorFootBall;
class MyException {};

//以足球为例
class FootBall {
private:
    const std::string _name;
public:
    FootBall(const std::string& name) : _name(name) {};
    virtual ~FootBall() {};
    virtual int RedPoint() { return 0; };
    virtual int BluePoint() { return 0; };
    virtual int RedFoulTimes() { return 0; };
    virtual int BlueFoulTimes() { return 0; };
    virtual string Countary() { return "XXX&XXX"; }
    virtual void Add(FootBall*) { throw MyException(); };
    virtual void Remove(FootBall*) { throw MyException(); };
};

//定义决赛类
class Final :public FootBall {
public:
    Final(const std::string& name) : FootBall(name) {};
    virtual ~Final() override {};
    virtual int RedPoint() override { return 2; };
    virtual int BluePoint() override{ return 0; };
    virtual int RedFoulTimes() override { return 2; };
    virtual int BlueFoulTimes() override { return 1; };
    virtual string Countary() override{ return "西班牙VS德国"; }
};

class SemiFinal1 :public FootBall {
public:
    SemiFinal1(const std::string& name) : FootBall(name) {};
    virtual ~SemiFinal1() override {};
    virtual int RedPoint() override { return 1; };
    virtual int BluePoint() override { return 0; };
    virtual int RedFoulTimes() override { return 1; };
    virtual int BlueFoulTimes() override { return 3; };
    virtual string Countary() override { return "西班牙VS法国"; }
};

class SemiFinal2 :public FootBall {
public:
    SemiFinal2(const std::string& name) : FootBall(name) {};
    virtual ~SemiFinal2() override {};
    virtual int RedPoint() override { return 3; };
    virtual int BluePoint() override { return 1; };
    virtual int RedFoulTimes() override { return 4; };
    virtual int BlueFoulTimes() override { return 3; };
    virtual string Countary() override { return "德国VS巴西"; }
};

class VisitorFootBall {
private:
    int _total = 0;
protected:
    VisitorFootBall() {};
public:
    virtual ~VisitorFootBall() {};
    virtual void Visit(Final*) {};
    virtual void Visit(SemiFinal1*) {};
    virtual void Visit(SemiFinal2*) {};
};


class VisitorFootBallRedPoint : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallRedPoint() {};
    ~VisitorFootBallRedPoint() override {};
    int& GetRedPoint() { return _total; }

    virtual void Visit(Final* final) override {
        _total = final->RedPoint();
    }
    virtual void Visit(SemiFinal1* semifinal1) override {
        _total = semifinal1->RedPoint();
    }
    virtual void Visit(SemiFinal2* semifinal2) override {
        _total = semifinal2->RedPoint();
    }
};

class VisitorFootBallBluePoint : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallBluePoint() {};
    ~VisitorFootBallBluePoint() override {};
    int& GetBluePoint() { return _total; }

    virtual void Visit(Final* final) override {
        _total = final->BluePoint();
    }
    virtual void Visit(SemiFinal1* semifinal1) override {
        _total = semifinal1->BluePoint();
    }
    virtual void Visit(SemiFinal2* semifinal2) override {
        _total = semifinal2->BluePoint();
    }
};

class VisitorFootBallRedFoulTimes : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallRedFoulTimes() {};
    ~VisitorFootBallRedFoulTimes() override {};
    int& GetRedFoulTimes() { return _total; }

    virtual void Visit(Final* final) override {
        _total = final->RedFoulTimes();
    }
    virtual void Visit(SemiFinal1* semifinal1) override {
        _total = semifinal1->RedFoulTimes();
    }
    virtual void Visit(SemiFinal2* semifinal2) override {
        _total = semifinal2->RedFoulTimes();
    }
};

class VisitorFootBallBlueFoulTimes : public VisitorFootBall {
private:
    int _total = 0;
public:
    VisitorFootBallBlueFoulTimes() {};
    ~VisitorFootBallBlueFoulTimes() override {};
    int& GetBlueFoulTimes() { return _total; }

    virtual void Visit(Final* final) override {
        _total = final->BlueFoulTimes();
    }
    virtual void Visit(SemiFinal1* semifinal1) override {
        _total = semifinal1->BlueFoulTimes();
    }
    virtual void Visit(SemiFinal2* semifinal2) override {
        _total = semifinal2->BlueFoulTimes();
    }
};

class VisitorFootBallCountary : public VisitorFootBall {
private:
    string _total;
public:
    VisitorFootBallCountary() {};
    ~VisitorFootBallCountary() override {};
    string& GetCountary() { return _total; }

    virtual void Visit(Final* final) override {
        _total = final->Countary();
    }
    virtual void Visit(SemiFinal1* semifinal1) override {
        _total = semifinal1->Countary();
    }
    virtual void Visit(SemiFinal2* semifinal2) override {
        _total = semifinal2->Countary();
    }
};

int testVisitor();

#endif