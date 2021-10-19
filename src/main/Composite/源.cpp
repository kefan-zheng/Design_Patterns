#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Events {
public:
	Events(string name) :eventName(name),parent(NULL) {}
	virtual void add(Events*e) {
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
int main() {
	CompositeEvents* overallEvents=new CompositeEvents("总体活动");
	CompositeEvents* swimming=new CompositeEvents("游泳");
	CompositeEvents* running = new CompositeEvents("跑步");
	overallEvents->add(swimming);
	overallEvents->add(running);
	swimming->add(new SingleEvents("男子50米蛙泳", "2021-10-19 14:00", "1号游泳馆"));
	swimming->add(new SingleEvents("女子50米自由泳", "2021-10-20 15:00", "1号游泳馆"));
	swimming->add(new SingleEvents("男子100米蝶泳", "2021-10-18 10:00", "3号游泳馆"));
	running->add(new SingleEvents("男子100米赛跑", "2021-10-17 10:30", "1号田径场"));
	running->add(new SingleEvents("女子1000米赛跑", "2021-10-20 14:30", "2号田径场"));
	overallEvents->show();
	return 0;
}