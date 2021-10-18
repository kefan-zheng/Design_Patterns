#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
struct Event {
	string startTime;
	string name;
};
bool sortByName(Event e1, Event e2) {
	return e1.name < e2.name;
}
bool sortByTime(Event e1, Event e2) {
	return e1.startTime < e2.startTime;
}

class Compositor {

public:
	Compositor() {}
	virtual void show(vector<Event>) = 0;
};
class SortByName :public Compositor {
public:
	SortByName(){}
	virtual void show(vector<Event>_events) {
		sort(_events.begin(), _events.end(), sortByName);
		for (int i = 0; i < _events.size(); ++i) {
			cout << "项目名称：" <<setw(16)<<left<< _events[i].name << "  开始时间：" << _events[i].startTime << endl;
		}
	}
};
class SortByTime :public Compositor {
public:
	SortByTime() {}
	virtual void show(vector<Event>_events) {
		sort(_events.begin(), _events.end(), sortByTime);
		for (int i = 0; i < _events.size(); ++i) {
			cout << "开始时间：" << _events[i].startTime << "  项目名称：" << _events[i].name << endl;
		}
	}
};
class Menu {
private:
	Compositor* _compositor;
	vector<Event>_events;
public:
	Menu(Compositor* c, vector<Event>v) :_compositor(c), _events(v) {}
	void Show() {
		_compositor->show(_events);
	}
};
int main() {
	vector<Event>v;
	v.push_back(Event{ "2021-10-18 08:00","男子100m赛跑"});
	v.push_back(Event{ "2021-10-19 14:00","女子100m游泳" });
	v.push_back(Event{ "2021-10-21 10:00","男子铅球" });
	v.push_back(Event{ "2021-10-18 10:00","女子排球" });
	SortByTime* time = new SortByTime;
	SortByName* name = new SortByName;
	cout << "按照时间排序：\n";
	Menu m1(time, v);
	m1.Show();
	cout << "按照项目首字母排序：\n";
	Menu m2(name, v);
	m2.Show();
}