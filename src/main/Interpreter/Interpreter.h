#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<sstream>
using namespace std;

// 抽象表达式类
class AbstractNode
{
public:
	virtual string interpret() = 0;
};

// And解释：非终结符表达式
class AndNode : public AbstractNode
{
private:
	AbstractNode* left;//And的左表达式
	AbstractNode* right;//And的右表达式

public:
	AndNode(AbstractNode* left, AbstractNode* right)
	{
		this->left = left;
		this->right = right;
	}
	//And表达式解释操作
	string interpret()
	{
		//递归调用每一个组成部分的interpret()方法
		//在递归调用时指定组成部分的连接方式，即非终结符的功能
		return this->left->interpret() + "，" + this->right->interpret();
	}
};

// 简单句子解释：非终结符表达式
class SentenceNode : public AbstractNode
{
private:
	AbstractNode* action;
	AbstractNode* target;
	AbstractNode* direction;

public:
	SentenceNode(AbstractNode* action, AbstractNode* target, AbstractNode* direction)
	{
		this->action = action;
		this->target = target;
		this->direction = direction;
	}
	//简单句子的解释操作
	string interpret()
	{
		return action->interpret() + " " + target->interpret() + " " + direction->interpret();
	}
};



// 动作（击球方法：弹、甩、刺、抛）解释：终结符表达式
class ActionNode : public AbstractNode
{
private:
	string action;
public:
	ActionNode(string action)
	{
		this->action = action;
	}
	//方向表达式的解释操作
	string interpret()
	{
		if (this->action == "1") { 
			return "flip";
		}
		else if (this->action == "2") {
			return "toss";
		}
		else if (this->action == "3") {
			return "stab";
		}
		else if (this->action == "4") {
			return "throw";
		}
		else {
			return "Invalid instructions";
		}
	}
};

// 击打目标解释：终结符表达式
class TargetNode : public AbstractNode
{
private:
	string target;
public:
	TargetNode(string target)
	{
		this->target = target;
	}
	//方向表达式的解释操作
	string interpret()
	{
		return "the No." + target + " ball";
	}
};


// 方向解释：终结符表达式
// 极坐标法：方位角x度
class DirectionNode : public AbstractNode
{
private:
	string angle;
public:
	DirectionNode(string angle)
	{
		this->angle = to_string(atoi(angle.c_str()) % 360);
	}
	//方向表达式的解释操作
	string interpret()
	{
		return "at " + this->angle + " azimuth";
	}
};


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

// 指令处理类：工具类
class InstructionHandler
{
private:
	string instruction;
	AbstractNode* node;

public:
	void handle(string instruction)
	{
		AbstractNode* left = NULL, * right = NULL;
		AbstractNode* direction = NULL, * action = NULL, * target = NULL;
		stack<AbstractNode*> s;//声明一个栈对象用于存储抽象语法树
		//以空格分隔指令字符串
		vector<string> words = split(instruction);
		//本实例采用栈的方式来处理指令
		for (int idx = 0; idx < words.size(); idx += 3) {
			//遇到“and”，将其后3个单词作为3个终结符连成一个SentenceNode作为“and”的右表达式，而将从栈顶弹出的表达式作为“and”的左表达式，最后将新的“and”表达式压入栈中。
			if (words[idx] == "and") {
				idx++;
				left = s.top();
				s.pop();
				string word1 = words[idx];
				action = new ActionNode(word1);
				string word2 = words[idx + 1];
				target = new TargetNode(word2);
				string word3 = words[idx + 2];
				direction = new DirectionNode(word3);
				right = new SentenceNode(action, target, direction);
				s.push(new AndNode(left, right));
			}
			//如果从头开始解释，将前3个单词连成一个SentenceNode并将压入栈中
			else {
				string word1 = words[idx];
				action = new ActionNode(word1);
				string word2 = words[idx + 1];
				target = new TargetNode(word2);
				string word3 = words[idx + 2];
				direction = new DirectionNode(word3);
				left = new SentenceNode(action, target, direction);
				s.push(left);
			}
		}
		this->node = s.top();
		s.pop();
	}
	string output()
	{
		string result = this->node->interpret();
		return result;
	}
};