#include "Interpreter.h"

//以空格分隔指令字符串
vector<string> split(string instruction) //instruction:待分割的字符串 
{
	//用于存放分割后的字符串 
	vector<string> res;
	//暂存从word中读取的字符串 
	string result;
	//将字符串读到input中 
	stringstream input(instruction);
	//依次输出到result中，并存入res中 
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