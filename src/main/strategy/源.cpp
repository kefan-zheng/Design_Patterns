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
			cout << "��Ŀ���ƣ�" <<setw(16)<<left<< _events[i].name << "  ��ʼʱ�䣺" << _events[i].startTime << endl;
		}
	}
};
class SortByTime :public Compositor {
public:
	SortByTime() {}
	virtual void show(vector<Event>_events) {
		sort(_events.begin(), _events.end(), sortByTime);
		for (int i = 0; i < _events.size(); ++i) {
			cout << "��ʼʱ�䣺" << _events[i].startTime << "  ��Ŀ���ƣ�" << _events[i].name << endl;
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
	v.push_back(Event{ "2021-10-18 08:00","����100m����"});
	v.push_back(Event{ "2021-10-19 14:00","Ů��100m��Ӿ" });
	v.push_back(Event{ "2021-10-21 10:00","����Ǧ��" });
	v.push_back(Event{ "2021-10-18 10:00","Ů������" });
	SortByTime* time = new SortByTime;
	SortByName* name = new SortByName;
	cout << "����ʱ������\n";
	Menu m1(time, v);
	m1.Show();
	cout << "������Ŀ����ĸ����\n";
	Menu m2(name, v);
	m2.Show();
}