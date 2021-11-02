#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;
//体育馆类
class Stadium {
private:
	string overall;
	string bidding;
	string design;
	//将一个不带空格的长字符串（代表一个段落）在控制台打印出来，每行一百个字符左右，不会将一个单词拆成两行打印
	void printLineByLine(string s) {
		stringstream stream(s);
		string buffer, output;
		while (!stream.eof()) {
			if (output.size() <= 100) {
				stream >> buffer;
				output += buffer + ' ';
			}
			else {
				cout << output << endl;
				output.clear();
			}
		}
		
		cout << output << endl;
	}

public:
	Stadium(string _o, string  _b, string _d) :overall(_o), bidding(_b), design(_d) {}
	void show() {
		cout << "overall\n" ;
		printLineByLine(overall);
		cout << "bidding\n" ;
		printLineByLine(bidding);
		cout << "design\n";
		printLineByLine(design);
	}
};