#include "Immutable.h"

int testImmutable() {
	vector<string>events;
	string s[] = { "Artistic swimming","Diving","Marathon swimming","Swimming","Water polo","3-on-3 basketball"
	,"Basketball","Volleyball","Freestyle wrestling","Badminton","Boxing","Breaking","Football","Golf","Weightlifting",
	"Table tennis","Sport climbing","Sailing","Rugby sevens","Judo","Shooting","Baseball" };
	for (int i = 0; i < s->size(); ++i)events.push_back(s[i]);
	EventList e(events);
	e.show();
	cout << endl;

	return 0;
}