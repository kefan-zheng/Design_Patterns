#pragma once
#include <iostream>
#include <stack>
using namespace std;


// �����ࣺ���������Receiver
class Point
{
public:
	Point()
	{
		this->score[0] = 0;
		this->score[1] = 0;
	}
	Point(int a, int b)
	{
		this->score[0] = a;
		this->score[1] = b;
	}
	int* Action(int flag, int point)
	{
		if (flag == 0) {	// ����
			this->score[0] += point;
		}
		else if (flag == 1) {	// �Ͷ�
			this->score[1] += point;
		}
		return score;
	}
	int* getScore()
	{
		return score;
	}
private:
	int score[2];
};


// ����������
class Command
{
public:
	~Command()
	{
		//cout << "Command dtor" << endl;
	}
	virtual int* Execute() = 0; //��������ִ�з���Execute()
	//virtual void setScore(int a, int b) = 0;
	virtual int* Undo() = 0; //������������Undo()

protected:
	Command()
	{
		//cout << "Command ctor" << endl;
		;
	}
	Point* scoreboard;
};

//����������
class ScoreCommand : public Command {
public:
	ScoreCommand(int flag, int value)
	{
		this->scoreboard = new Point();
		this->value = value;
		this->flag = flag;
	}
	ScoreCommand(Point* point, int flag, int value)
	{
		this->scoreboard = point;
		this->value = value;
		this->flag = flag;
	}
	//ʵ�ֳ�����������������Execute()���������÷�����ļƷֲ���
	int* Execute()
	{
		return this->scoreboard->Action(this->flag, this->value);
	}
	int* Undo()
	{
		return this->scoreboard->Action(this->flag, -this->value);
		//cout << "��ǰ�ȷ�Ϊ : " << scoreboard->getScore()[0] << ":" << scoreboard->getScore()[1] << endl;
	}

private:
	int flag, value;
};


// �Ʒֽ����ࣺ��������
class ScoreForm {
public:
	ScoreForm()
	{
		;
	}
	ScoreForm(Command* command)
	{
		mUndo.push(command);
	}
	~ScoreForm()
	{
		while (false == mUndo.empty())
		{
			delete mUndo.top();
			mUndo.pop();
		}
		while (false == mRedo.empty())
		{
			delete mRedo.top();
			mRedo.pop();
		}
	}

	//������������Execute()����ִ������
	void compute(Command* pCmd)
	{
		int* score = pCmd->Execute();
		//if (flag == 0 && value > 0) {	// ���ӵ÷�
		//	cout << "���ӵ�" << value << "�֣�";
		//}
		//else if (flag == 1 && value > 0) {	// �Ͷӵ÷�
		//	cout << "�Ͷӵ�" << value << "�֣�";
		//}
		cout << "The current score : " << score[0] << ":" << score[1] << endl;
		mUndo.push(pCmd);
		// ÿһ�μƷ֣����mRedo
		while (!mRedo.empty()) {
			mRedo.pop();
		}
	}
	////������������Undo()����ִ�г���
	//void undo() 
	//{
	//	int* score = command->Undo();
	//	cout << "������һ�μƷ֣�";
	//	cout << "��ǰ�ȷ�Ϊ : " << score[0] << ":" << score[1] << endl;
	//}

	void undo()
	{
		if (mUndo.size() < 2)
		{
			//�޷����˳���û������
			printf("undo failed.\n");
			return;
		}
		printf("undo -- ");
		//��ǰ����
		auto pCmd = mUndo.top();
		//���浱ǰ����
		mRedo.push(pCmd);
		////��ԭ���ϸ�����
		//pCmd = mUndo.top();
		//����
		mUndo.pop();

		int* score = pCmd->Undo();
		cout << "The current score : " << score[0] << ":" << score[1] << endl;
	}

	void redo()
	{
		if (mRedo.empty())
		{
			//�޷�ǰ������û������
			printf("redo failed.\n");
			return;
		}
		printf("redo -- ");

		auto pCmd = mRedo.top();

		//this->compute(pCmd);
		int* score = pCmd->Execute();
		cout << "The current score : " << score[0] << ":" << score[1] << endl;

		mRedo.pop();

		mUndo.push(pCmd);
	}


private:
	//Command* command;
	//stack<int*> mUndo, mRedo;
	stack< Command* > mUndo;
	stack< Command* > mRedo;
};

int testCommand();