#include "Interpreter.h"


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

AndNode::AndNode(AbstractNode* left, AbstractNode* right)
{
	this->left = left;
	this->right = right;
}
//And���ʽ���Ͳ���
string AndNode::interpret()
{
	//�ݹ����ÿһ����ɲ��ֵ�interpret()����
	//�ڵݹ����ʱָ����ɲ��ֵ����ӷ�ʽ�������ս���Ĺ���
	return this->left->interpret() + "��" + this->right->interpret();
}


SentenceNode::SentenceNode(AbstractNode* player, AbstractNode* action, AbstractNode* position, AbstractNode* tactics)
{
	this->player = player;
	this->action = action;
	this->position = position;
	this->tactics = tactics;
}
//�򵥾��ӵĽ��Ͳ���
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
//���ʽ�Ľ��Ͳ���
string ActionNode::interpret()
{
	if (this->action == "fs") {
		return "full strike";//ȫ������
	}
	else if (this->action == "hbs") {
		return "high backhand stroke";//���ַ��Ļ���
	}
	else if (this->action == "rths") {
		return "round-the-head stroke";//��ͷ������
	}
	else if (this->action == "shd") {
		return "shoulder-high drive";//�����ߵ�ƽ����
	}
	else if (this->action == "us") {
		return "underhand stroke";//���ֻ���
	}
	else if (this->action == "sas") {
		return "side-arm stroke";//������
	}
	else if (this->action == "s") {
		return "smash";//ɱ��
	}
	else {
		return "Invalid instructions";
	}
}


PositionNode::PositionNode(string position)
{
	this->position = position;
}
//���ʽ�Ľ��Ͳ���
string PositionNode::interpret()
{
	if (this->position == "b") {
		return "backcourt";//��
	}
	else if (this->position == "f") {
		return "forecourt";//ǰ��
	}
	else if (this->position == "s") {
		return "service court";//������
	}
	else if (this->position == "l") {
		return "left court";//����
	}
	else if (this->position == "ls") {
		return "left service court";//������
	}
	else if (this->position == "r") {
		return "right court";//�ҳ���
	}
	else if (this->position == "rs") {
		return "right service court";//�ҷ�����
	}
	else if (this->position == "a") {
		return "alley";//��˫����֮���ϸ���ش�
	}
	else if (this->position == "ba") {
		return "back alley";//��˫�����֮���ϸ���ش�
	}
	else {
		return "Invalid instructions";//
	}
}


TacticsNode::TacticsNode(string tactics)
{
	this->tactics = tactics;
}
//���ʽ�Ľ��Ͳ���
string TacticsNode::interpret()
{
	if (this->tactics == "hcs") {
		return "half-court shot";//�볡���
	}
	else if (this->tactics == "fb") {
		return "front and back";//ǰ��վλ��
	}
	else if (this->tactics == "rs") {
		return "rotation system";//��ת��
	}
	else if (this->tactics == "np") {
		return "net play";//��ǰ��
	}
	else if (this->tactics == "dfb") {
		return "defense and fight back";//���ط���
	}
	else {
		return "Invalid instructions";
	}
}


void InstructionHandler::handle(string instruction)
{
	AbstractNode* left = NULL, * right = NULL;
	AbstractNode* player = NULL, * tactics = NULL, * action = NULL, * position = NULL;
	stack<AbstractNode*> s;//����һ��ջ�������ڴ洢�����﷨��
	//�Կո�ָ�ָ���ַ���
	vector<string> words = split(instruction);
	//��ʵ������ջ�ķ�ʽ������ָ��
	for (int idx = 0; idx < words.size(); idx += 4) {
		//������and���������4��������Ϊ4���ս������һ��SentenceNode��Ϊ��and�����ұ��ʽ��������ջ�������ı��ʽ��Ϊ��and��������ʽ������µġ�and�����ʽѹ��ջ�С�
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
		//�����ͷ��ʼ���ͣ���ǰ4����������һ��SentenceNode����ѹ��ջ��
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
	�˶�Ա: 1 2
	���������򷽷���: fs hbs rths shd us sas s
	����ʱ����λ��: b f s l ls r rs a ba
	ս��: hcs fb rs np dfb
	*/
	string instruction = "1 fs b fb and 2 sas s rs";
	InstructionHandler hander;
	hander.handle(instruction);
	string outString;
	outString = hander.output();
	cout << outString << endl;

	return 0;
}