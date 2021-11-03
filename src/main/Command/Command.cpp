#include "Command.h"


int main1()
{
	Point* receiver = new Point();
	ScoreForm* scoreform = new ScoreForm();

	// 主队得2分
	scoreform->compute(new ScoreCommand(receiver, 0, 2));
	// 主队得3分
	scoreform->compute(new ScoreCommand(receiver, 0, 3));
	// 客队得2分
	scoreform->compute(new ScoreCommand(receiver, 1, 2));
	// 撤销上一次计分
	scoreform->undo();
	// 撤销上一次计分
	scoreform->undo();
	// 客队得1分
	scoreform->compute(new ScoreCommand(receiver, 1, 1));
	// 客队得3分
	scoreform->compute(new ScoreCommand(receiver, 1, 3));
	// 撤销上一次计分
	scoreform->undo();

	scoreform->redo();

	delete scoreform;
	return 0;
}