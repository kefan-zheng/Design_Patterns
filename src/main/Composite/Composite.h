#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<string>
using namespace std;
//比赛基类
class Events {
public:
	Events(string name) :eventName(name), parent(NULL) {}
	//增加新的子类比赛
	virtual void add(Events* e) {
		children.push_back(e);
	}
	//获得比赛名称
	virtual string getName() {
		return eventName;
	}
	virtual void show() {
	}
	virtual ~Events() {

	}
protected:
	string eventName;//比赛名称（既可以是单个比赛也可以是复合比赛）
	Events* parent;//该比赛的父类指针
	vector<Events*>children;//比赛的子类指针
};
//复合比赛，继承自比赛基类
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	//展示单个比赛
	virtual void show() {
		cout << eventName << " encompasses: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children[i]->getName();
		}
		cout << endl;
		//递归展示下一层比赛（既有复合比赛，又有单个比赛）
		for (auto i : children)i->show();
		cout << endl;
	}
private:
};
//单个比赛，继承自比赛基类
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << ", held time：" << _date << ", held site：" << _site << endl;
	}
private:
	string _date;//比赛时间
	string _site;//比赛地点
};