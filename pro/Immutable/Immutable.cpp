#include "Immutable.h"
void testImmutable() {
	cout << "This is a brief introduction to our stadium named Bird's Nest: \n";
	string s[3];
	ifstream input;
	input.open("./Immutable/input.txt");
	if (!input) {
		cout << "fail to open input.txt! Program exits!\n";
		return;
	}
	for (int i = 0; i < 3; ++i)getline(input, s[i]);
	Stadium stadium(s[0], s[1], s[2]);
	stadium.show();
	input.close();
}