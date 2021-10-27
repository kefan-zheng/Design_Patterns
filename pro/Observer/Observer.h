#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"../MedalRanking.h"

using namespace std;

class Subject;

/*
 *  Observer: 观察者抽象类
 *  当Subject改变时，各个Observer会被notify并更新
 */
class Observer {
public:
	virtual ~Observer() {}

	virtual MedalRanking getState() = 0;
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
};

/*
 *  ConcreteObserver: 观察者具体类，这里对应的是媒体
 *  媒体的状态就是奖牌榜的信息，当奖牌榜改变时，各家媒体
 */
class ConcreteObserver : public Observer {
public:
	ConcreteObserver(string name, MedalRanking const state);//根据媒体名字与当前奖牌榜信息初始化
	~ConcreteObserver();
	MedalRanking getState(); // 获取媒体状态，即奖牌榜信息
	void update(Subject* subject); // 奖牌榜信息改变，更新媒体的奖牌榜信息
	void showState(); // 打印媒体状态，以新闻播报形式呈现
private:
	MedalRanking state; // 奖牌榜信息
	string name; // 媒体名称
};


/*
 *  Subject: 被观察者，它存有所有其观察者的信息，可在状态改变时通知各观察者
 */
class Subject {
public:
	void attach(Observer* observer); //添加观察者
	void detach(const int index); //根据序号删除某观察者
	void notify();//状态改变时，将会通知各观察者
	virtual MedalRanking getState() = 0; //获取当前状态
	virtual void setState(const MedalRanking s) = 0; //更新状态
private:
	vector<Observer*> observers;// 记录所有的观察者
};


/*
 *  ConcreteSubject: 这里对应的是奖牌榜，当奖牌榜改变时，各家媒体会收到通知，并更新自身数据
 */
class ConcreteSubject :public Subject {
public:
	MedalRanking getState();//获取当前状态，直接返回自身存储的奖牌榜实例
	void setState(MedalRanking s); //更新奖牌榜状态
private:
	MedalRanking state; //奖牌榜状态
};

int testObserver();//测试函数