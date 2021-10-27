#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Events {
public:
	Events(string name) :eventName(name), parent(NULL) {}
	virtual void add(Events* e) {
		children.push_back(e);
	}
	virtual string getName() {
		return eventName;
	}
	virtual void show() {
	}
	virtual ~Events() {

	}
protected:
	string eventName;
	Events* parent;
	vector<Events*>children;
};
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	virtual void show() {
		cout << eventName << "包含: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children[i]->getName();
		}
		cout << endl;
		for (auto i : children)i->show();
	}
private:
};
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << " 的举办时间为：" << _date << "，举办地点为：" << _site << endl;
	}
private:
	string _date;
	string _site;
};

int testComposite();