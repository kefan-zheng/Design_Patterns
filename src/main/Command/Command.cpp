#include "Command.h"


int main1()
{
	Point* receiver = new Point();
	ScoreForm* scoreform = new ScoreForm();

	// ���ӵ�2��
	scoreform->compute(new ScoreCommand(receiver, 0, 2));
	// ���ӵ�3��
	scoreform->compute(new ScoreCommand(receiver, 0, 3));
	// �Ͷӵ�2��
	scoreform->compute(new ScoreCommand(receiver, 1, 2));
	// ������һ�μƷ�
	scoreform->undo();
	// ������һ�μƷ�
	scoreform->undo();
	// �Ͷӵ�1��
	scoreform->compute(new ScoreCommand(receiver, 1, 1));
	// �Ͷӵ�3��
	scoreform->compute(new ScoreCommand(receiver, 1, 3));
	// ������һ�μƷ�
	scoreform->undo();

	scoreform->redo();

	delete scoreform;
	return 0;
}