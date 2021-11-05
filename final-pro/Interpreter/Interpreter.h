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
	AndNode(AbstractNode* left, AbstractNode* right);
	//And表达式解释操作
	string interpret();
};

// 简单句子解释：非终结符表达式
class SentenceNode : public AbstractNode
{
private:
	AbstractNode* player;
	AbstractNode* action;
	AbstractNode* position;
	AbstractNode* tactics;

public:
	SentenceNode(AbstractNode* player, AbstractNode* action, AbstractNode* position, AbstractNode* tactics);
	//简单句子的解释操作
	string interpret();
};


// 运动员解释：终结符表达式
class PlayerNode : public AbstractNode
{
private:
	string current;
	string player1 = "Robert";
	string player2 = "John";
public:
	PlayerNode(string current);
	string interpret();
};

// 动作（击球方法）解释：终结符表达式
class ActionNode : public AbstractNode
{
private:
	string action;
public:
	ActionNode(string action);
	//表达式的解释操作
	string interpret();
};

// 击打时所处位置解释：终结符表达式
class PositionNode : public AbstractNode
{
private:
	string position;
public:
	PositionNode(string position);
	//表达式的解释操作
	string interpret();
};


// 战术解释：终结符表达式
class TacticsNode : public AbstractNode
{
private:
	string tactics;
public:
	TacticsNode(string tactics);
	//表达式的解释操作
	string interpret();
};


// 指令处理类：工具类
class InstructionHandler
{
private:
	string instruction;
	AbstractNode* node;

public:
	void handle(string instruction);
	string output();
};