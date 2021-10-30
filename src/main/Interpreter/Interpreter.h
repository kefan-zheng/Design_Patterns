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
	AndNode(AbstractNode* left, AbstractNode* right)
	{
		this->left = left;
		this->right = right;
	}
	//And���ʽ���Ͳ���
	string interpret()
	{
		//�ݹ����ÿһ����ɲ��ֵ�interpret()����
		//�ڵݹ����ʱָ����ɲ��ֵ����ӷ�ʽ�������ս���Ĺ���
		return this->left->interpret() + "��" + this->right->interpret();
	}
};

// �򵥾��ӽ��ͣ����ս�����ʽ
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
	//�򵥾��ӵĽ��Ͳ���
	string interpret()
	{
		return action->interpret() + " " + target->interpret() + " " + direction->interpret();
	}
};



// ���������򷽷�������˦���̡��ף����ͣ��ս�����ʽ
class ActionNode : public AbstractNode
{
private:
	string action;
public:
	ActionNode(string action)
	{
		this->action = action;
	}
	//������ʽ�Ľ��Ͳ���
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

// ����Ŀ����ͣ��ս�����ʽ
class TargetNode : public AbstractNode
{
private:
	string target;
public:
	TargetNode(string target)
	{
		this->target = target;
	}
	//������ʽ�Ľ��Ͳ���
	string interpret()
	{
		return "the No." + target + " ball";
	}
};


// ������ͣ��ս�����ʽ
// �����귨����λ��x��
class DirectionNode : public AbstractNode
{
private:
	string angle;
public:
	DirectionNode(string angle)
	{
		this->angle = to_string(atoi(angle.c_str()) % 360);
	}
	//������ʽ�Ľ��Ͳ���
	string interpret()
	{
		return "at " + this->angle + " azimuth";
	}
};


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

// ָ����ࣺ������
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
		stack<AbstractNode*> s;//����һ��ջ�������ڴ洢�����﷨��
		//�Կո�ָ�ָ���ַ���
		vector<string> words = split(instruction);
		//��ʵ������ջ�ķ�ʽ������ָ��
		for (int idx = 0; idx < words.size(); idx += 3) {
			//������and���������3��������Ϊ3���ս������һ��SentenceNode��Ϊ��and�����ұ��ʽ��������ջ�������ı��ʽ��Ϊ��and��������ʽ������µġ�and�����ʽѹ��ջ�С�
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
			//�����ͷ��ʼ���ͣ���ǰ3����������һ��SentenceNode����ѹ��ջ��
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