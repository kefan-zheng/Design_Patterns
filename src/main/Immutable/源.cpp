#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
class EventList {
private:
	vector<string>Events;
public:
	EventList(vector<string>v) :Events(v) {}
	void show() {
		for (int i = 0; i < Events.size(); ++i) {
			cout << setw(20)<<left<<Events[i];
			if ((i + 1) % 3 == 0)cout << endl;
		}
	}
};
int main() {
	vector<string>events;
	string s[] = { "Artistic swimming","Diving","Marathon swimming","Swimming","Water polo","3-on-3 basketball"
	,"Basketball","Volleyball","Freestyle wrestling","Badminton","Boxing","Breaking","Football","Golf","Weightlifting",
	"Table tennis","Sport climbing","Sailing","Rugby sevens","Judo","Shooting","Baseball" };
	for (int i = 0; i < s->size(); ++i)events.push_back(s[i]);
	EventList e(events);
	e.show();
	return 0;
}