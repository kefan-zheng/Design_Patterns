#pragma once
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

struct Event {
	string eventName;//������Ŀ��
	string time;//�ٰ�ʱ��
	string heldSite;//�ٰ�ĳ�����
	bool operator<(Event& e) {
		return time < e.time;
	}
};
struct Site {
	string siteName;//������
	int num;//���ݱ��
	vector<Event*>_events;
};

//������������
bool sortByName(Site s1, Site s2);
//���ձ������
bool sortByNum(Site s1, Site s2);
//������Ŀ��������
bool sortByTime(Event* e1, Event* e2);

class Compositor {

public:
	Compositor() {}
	virtual void show(vector<Event>, vector<Site>) = 0;
	virtual void printEvents(vector<Event*>_e) {
		if (_e.empty())return;
		sort(_e.begin(), _e.end(), sortByTime);
		cout << "Events held here: \n";
		for (int i = 0; i < _e.size(); ++i) {
			cout << "\t" << _e[i]->time << "         " << _e[i]->eventName << endl;
		}
	}
};


class SortByName :public Compositor {
public:
	SortByName();
	virtual void show(vector<Event>_events,vector<Site>_sites) {
		sort(_sites.begin(), _sites.end(), sortByName);
		for (int i = 0; i < _sites.size(); ++i) {
			cout << "Name of site��" << setw(20) << left << _sites[i].siteName << "  Site number��" << _sites[i].num << endl;
			printEvents(_sites[i]._events);
		}
	}
};
class SortByNum :public Compositor {
public:
	SortByNum();
	virtual void show(vector<Event>_events, vector<Site>_sites) {
		sort(_sites.begin(), _sites.end(), sortByNum);
		for (int i = 0; i < _sites.size(); ++i) {
			cout << "Site number��" << _sites[i].num << "  Name of site��" << setw(20) << left << _sites[i].siteName << endl;
			printEvents(_sites[i]._events);
		}
	}
};
class SortByTime :public Compositor {
public:
	SortByTime();
	virtual void show(vector<Event>_events, vector<Site>_sites) {
		sort(_events.begin(), _events.end());
		for (int i = 0; i < _events.size(); ++i) {
			cout << "Event name: " << setw(25)<<_events[i].eventName << "  time: " << _events[i].time << "  site: " << _events[i].heldSite << endl;
		}
	}
};
class Menu {
private:
	Compositor* _compositor[3];
	vector<Event>* _events;
	vector<Site>* _sites;
public:
	Menu(vector<Event>*v,vector<Site>*s) :_events(v),_sites(s) {
		_compositor[0] = new SortByName;
		_compositor[1] = new SortByNum;
		_compositor[2] = new SortByTime;
	}
	//ʹ�����ֲ�ͬ���ԶԳ��ؽ���չʾ
	void Show(string Mode) {
		if(Mode=="name")
			_compositor[0]->show(*_events, *_sites);
		else if (Mode =="number")
			_compositor[1]->show(*_events, *_sites);
		else if(Mode=="time")
			_compositor[2]->show(*_events, *_sites);
	}
};

int testStrategy();