#include "Strategy.h"

int testStrategy() {
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

	cout << endl;

	return 0;
}