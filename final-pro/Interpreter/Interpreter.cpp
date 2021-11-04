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

AndNode::AndNode(AbstractNode* left, AbstractNode* right)
{
	this->left = left;
	this->right = right;
}
//And表达式解释操作
string AndNode::interpret()
{
	//递归调用每一个组成部分的interpret()方法
	//在递归调用时指定组成部分的连接方式，即非终结符的功能
	return this->left->interpret() + "，" + this->right->interpret();
}


SentenceNode::SentenceNode(AbstractNode* player, AbstractNode* action, AbstractNode* position, AbstractNode* tactics)
{
	this->player = player;
	this->action = action;
	this->position = position;
	this->tactics = tactics;
}
//简单句子的解释操作
string SentenceNode::interpret()
{
	return player->interpret() + " " + action->interpret() + " the ball in " + position->interpret() + " with " + tactics->interpret();
}


PlayerNode::PlayerNode(string current)
{
	this->current = current;
}
string PlayerNode::interpret()
{
	if (this->current == "1") {
		return player1;
	}
	if (this->current == "2") {
		return player2;
	}
	else {
		return "Invalid instructions";
	}
}


ActionNode::ActionNode(string action)
{
	this->action = action;
}
//表达式的解释操作
string ActionNode::interpret()
{
	if (this->action == "fs") {
		return "full strike";//全力击球
	}
	else if (this->action == "hbs") {
		return "high backhand stroke";//上手反拍击球
	}
	else if (this->action == "rths") {
		return "round-the-head stroke";//绕头顶击球
	}
	else if (this->action == "shd") {
		return "shoulder-high drive";//与肩齐高的平抽球
	}
	else if (this->action == "us") {
		return "underhand stroke";//低手击球
	}
	else if (this->action == "sas") {
		return "side-arm stroke";//侧手球
	}
	else if (this->action == "s") {
		return "smash";//杀球
	}
	else {
		return "Invalid instructions";
	}
}


PositionNode::PositionNode(string position)
{
	this->position = position;
}
//表达式的解释操作
string PositionNode::interpret()
{
	if (this->position == "b") {
		return "backcourt";//后场
	}
	else if (this->position == "f") {
		return "forecourt";//前场
	}
	else if (this->position == "s") {
		return "service court";//发球区
	}
	else if (this->position == "l") {
		return "left court";//左场区
	}
	else if (this->position == "ls") {
		return "left service court";//左发球区
	}
	else if (this->position == "r") {
		return "right court";//右场区
	}
	else if (this->position == "rs") {
		return "right service court";//右发球区
	}
	else if (this->position == "a") {
		return "alley";//单双打线之间的细长地带
	}
	else if (this->position == "ba") {
		return "back alley";//单双打端线之间的细长地带
	}
	else {
		return "Invalid instructions";//
	}
}


TacticsNode::TacticsNode(string tactics)
{
	this->tactics = tactics;
}
//表达式的解释操作
string TacticsNode::interpret()
{
	if (this->tactics == "hcs") {
		return "half-court shot";//半场球打法
	}
	else if (this->tactics == "fb") {
		return "front and back";//前后站位打法
	}
	else if (this->tactics == "rs") {
		return "rotation system";//轮转打法
	}
	else if (this->tactics == "np") {
		return "net play";//网前打法
	}
	else if (this->tactics == "dfb") {
		return "defense and fight back";//防守反击
	}
	else {
		return "Invalid instructions";
	}
}


void InstructionHandler::handle(string instruction)
{
	AbstractNode* left = NULL, * right = NULL;
	AbstractNode* player = NULL, * tactics = NULL, * action = NULL, * position = NULL;
	stack<AbstractNode*> s;//声明一个栈对象用于存储抽象语法树
	//以空格分隔指令字符串
	vector<string> words = split(instruction);
	//本实例采用栈的方式来处理指令
	for (int idx = 0; idx < words.size(); idx += 4) {
		//遇到“and”，将其后4个单词作为4个终结符连成一个SentenceNode作为“and”的右表达式，而将从栈顶弹出的表达式作为“and”的左表达式，最后将新的“and”表达式压入栈中。
		if (words[idx] == "and") {
			idx++;
			left = s.top();
			s.pop();
			string word1 = words[idx];
			player = new PlayerNode(word1);
			string word2 = words[idx + 1];
			action = new ActionNode(word2);
			string word3 = words[idx + 2];
			position = new PositionNode(word3);
			string word4 = words[idx + 3];
			tactics = new TacticsNode(word4);
			right = new SentenceNode(player, action, position, tactics);
			s.push(new AndNode(left, right));
		}
		//如果从头开始解释，将前4个单词连成一个SentenceNode并将压入栈中
		else {
			string word1 = words[idx];
			player = new PlayerNode(word1);
			string word2 = words[idx + 1];
			action = new ActionNode(word2);
			string word3 = words[idx + 2];
			position = new PositionNode(word3);
			string word4 = words[idx + 3];
			tactics = new TacticsNode(word4);
			left = new SentenceNode(player, action, position, tactics);
			s.push(left);
		}
	}
	this->node = s.top();
	s.pop();
}
string InstructionHandler::output()
{
	string result = this->node->interpret();
	return result;
}




int testInterpreter()
{
	/*
	运动员: 1 2
	动作（击球方法）: fs hbs rths shd us sas s
	击打时所处位置: b f s l ls r rs a ba
	战术: hcs fb rs np dfb
	*/
	string instruction = "1 fs b fb and 2 sas s rs";
	InstructionHandler hander;
	hander.handle(instruction);
	string outString;
	outString = hander.output();
	cout << outString << endl;

	return 0;
}