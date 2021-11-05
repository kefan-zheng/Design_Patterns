#include "strategy.h"

SortByName::SortByName() {}
SortByNum::SortByNum() {}
SortByTime::SortByTime() {}

//按照名字排序
bool sortByName(Site s1, Site s2) {
	return s1.siteName < s2.siteName;
}
//按照编号排序
bool sortByNum(Site s1, Site s2) {
	return s1.num < s2.num;
}
//按照项目名称排序
bool sortByTime(Event* e1, Event* e2) {
	return e1->time < e2->time;
}

int testStrategy() {
	vector<Event>v;
	vector<Site>s;
	Menu m(&v, &s);
	int num = 100001;
	//插入场地和比赛项目数据
	s.push_back(Site{ "Swimming pool",num++ });
	s.push_back(Site{ "Running field",num++ });
	s.push_back(Site{ "Table Tennis room",num++ });
	s.push_back(Site{ "Badminton room",num++ });
	v.push_back(Event{ "Men's 100m freestyle","2021-07-23 08:00:00","Swimming pool" });
	v.push_back(Event{ "Women's 100m freestyle","2021-07-24 08:00:00","Swimming pool" });
	v.push_back(Event{ "Men's 100m breaststroke","2021-07-22 09:20:00","Swimming pool" });
	v.push_back(Event{ "Women's 100m breaststroke","2021-07-23 14:40:00","Swimming pool" });
	v.push_back(Event{ "Men's 100m run","2021-07-25 10:20:00","Running field" });
	v.push_back(Event{ "Women's 100m run","2021-07-26 09:30:00","Running field" });
	v.push_back(Event{ "Men's 2000m run","2021-07-23 08:20:00","Running field" });
	v.push_back(Event{ "Women's 2000m run","2021-07-27 08:45:00","Running field" });
	v.push_back(Event{ "Men's semifinal","2021-07-17 20:30:00","Table Tennis room" });
	v.push_back(Event{ "Women's semifinal","2021-07-20 20:30:00","Table Tennis room" });
	v.push_back(Event{ "Men's final","2021-07-25 20:30:00","Table Tennis room" });
	v.push_back(Event{ "Women's final","2021-07-23 20:30:00","Table Tennis room" });
	v.push_back(Event{ "Men's final","2021-07-30 21:30:00","Badminton room" });
	v.push_back(Event{ "Women's final","2021-07-27 21:30:00","Badminton room" });
	//在场地中插入其中所进行的比赛
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			if (v[i].heldSite == s[j].siteName)s[j]._events.push_back(&v[i]);
		}
	}
	cout << "Display sites sorted by name:\n";
	m.Show("name");
	cout << "\n\nDisplay sites sorted by number:\n";
	m.Show("number");
	cout << "\n\nDisplay sites sorted by the time of events held there:\n";
	m.Show("time");
	cout << endl;

	return 0;
}