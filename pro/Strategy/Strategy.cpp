#include "Strategy.h"

int testStrategy() {
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

	cout << endl;

	return 0;
}