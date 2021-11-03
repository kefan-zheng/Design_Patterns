#pragma once
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
			cout << setw(20) << left << Events[i];
			if ((i + 1) % 3 == 0)cout << endl;
		}
	}
};

int testImmutable();