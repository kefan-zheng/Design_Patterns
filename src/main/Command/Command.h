#pragma once
#include <iostream>
#include <stack>
using namespace std;


// 分数类：请求接收者Receiver
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
		if (flag == 0) {	// 主队
			this->score[0] += point;
		}
		else if (flag == 1) {	// 客队
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


// 抽象命令类
class Command
{
public:
	~Command()
	{
		//cout << "Command dtor" << endl;
	}
	virtual int* Execute() = 0; //声明命令执行方法Execute()
	//virtual void setScore(int a, int b) = 0;
	virtual int* Undo() = 0; //声明撤销方法Undo()

protected:
	Command()
	{
		//cout << "Command ctor" << endl;
		;
	}
	Point* scoreboard;
};

//具体命令类
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
	//实现抽象命令类中声明的Execute()方法，调用分数类的计分操作
	int* Execute()
	{
		return this->scoreboard->Action(this->flag, this->value);
	}
	int* Undo()
	{
		return this->scoreboard->Action(this->flag, -this->value);
		//cout << "当前比分为 : " << scoreboard->getScore()[0] << ":" << scoreboard->getScore()[1] << endl;
	}

private:
	int flag, value;
};


// 计分界面类：请求发送者
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

	//调用命令对象的Execute()方法执行运算
	void compute(Command* pCmd)
	{
		int* score = pCmd->Execute();
		//if (flag == 0 && value > 0) {	// 主队得分
		//	cout << "主队得" << value << "分，";
		//}
		//else if (flag == 1 && value > 0) {	// 客队得分
		//	cout << "客队得" << value << "分，";
		//}
		cout << "The current score : " << score[0] << ":" << score[1] << endl;
		mUndo.push(pCmd);
		// 每一次计分，清空mRedo
		while (!mRedo.empty()) {
			mRedo.pop();
		}
	}
	////调用命令对象的Undo()方法执行撤销
	//void undo() 
	//{
	//	int* score = command->Undo();
	//	cout << "撤销上一次计分，";
	//	cout << "当前比分为 : " << score[0] << ":" << score[1] << endl;
	//}

	void undo()
	{
		if (mUndo.size() < 2)
		{
			//无法后退撤销没有数据
			printf("undo failed.\n");
			return;
		}
		printf("undo -- ");
		//当前命令
		auto pCmd = mUndo.top();
		//保存当前命令
		mRedo.push(pCmd);
		////还原到上个命令
		//pCmd = mUndo.top();
		//弹出
		mUndo.pop();

		int* score = pCmd->Undo();
		cout << "The current score : " << score[0] << ":" << score[1] << endl;
	}

	void redo()
	{
		if (mRedo.empty())
		{
			//无法前进重做没有数据
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