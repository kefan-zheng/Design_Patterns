#include "Interpreter.h"

//�Կո�ָ�ָ���ַ���
vector<string> split(string instruction) //instruction:���ָ���ַ��� 
{
	//���ڴ�ŷָ����ַ��� 
	vector<string> res;
	//�ݴ��word�ж�ȡ���ַ��� 
	string result;
	//���ַ�������input�� 
	stringstream input(instruction);
	//���������result�У�������res�� 
	while (input >> result)
		res.push_back(result);
	return res;
}

int testInterpreter()
{
	//string instruction = "180 throw 5 and 36 stab 10 and 60 toss 5";
	string instruction = "1 5 180 and 2 6 30 and 3 7 45 and 4 8 125";
	InstructionHandler hander;
	hander.handle(instruction);
	string outString;
	outString = hander.output();
	cout << outString << endl;

	return 0;
}