#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<sstream>
using namespace std;

// ������ʽ��
class AbstractNode
{
public:
	virtual string interpret() = 0;
};

// And���ͣ����ս�����ʽ
class AndNode : public AbstractNode
{
private:
	AbstractNode* left;//And������ʽ
	AbstractNode* right;//And���ұ��ʽ

public:
	AndNode(AbstractNode* left, AbstractNode* right);
	//And���ʽ���Ͳ���
	string interpret();
};

// �򵥾��ӽ��ͣ����ս�����ʽ
class SentenceNode : public AbstractNode
{
private:
	AbstractNode* player;
	AbstractNode* action;
	AbstractNode* position;
	AbstractNode* tactics;

public:
	SentenceNode(AbstractNode* player, AbstractNode* action, AbstractNode* position, AbstractNode* tactics);
	//�򵥾��ӵĽ��Ͳ���
	string interpret();
};


// �˶�Ա���ͣ��ս�����ʽ
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

// ���������򷽷������ͣ��ս�����ʽ
class ActionNode : public AbstractNode
{
private:
	string action;
public:
	ActionNode(string action);
	//���ʽ�Ľ��Ͳ���
	string interpret();
};

// ����ʱ����λ�ý��ͣ��ս�����ʽ
class PositionNode : public AbstractNode
{
private:
	string position;
public:
	PositionNode(string position);
	//���ʽ�Ľ��Ͳ���
	string interpret();
};


// ս�����ͣ��ս�����ʽ
class TacticsNode : public AbstractNode
{
private:
	string tactics;
public:
	TacticsNode(string tactics);
	//���ʽ�Ľ��Ͳ���
	string interpret();
};


// ָ����ࣺ������
class InstructionHandler
{
private:
	string instruction;
	AbstractNode* node;

public:
	void handle(string instruction);
	string output();
};