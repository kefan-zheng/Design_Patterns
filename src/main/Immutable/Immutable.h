#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;
//��������
class Stadium {
private:
	string overall;
	string bidding;
	string design;
	//��һ�������ո�ĳ��ַ���������һ�����䣩�ڿ���̨��ӡ������ÿ��һ�ٸ��ַ����ң����Ὣһ�����ʲ�����д�ӡ
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