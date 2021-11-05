#include "TransferObject.h"
#include <ctime>

AthleteVO::AthleteVO(string name, int serialNo, int win, int fail)
{
	this->name = name;
	this->serialNo = serialNo;
	this->win = win;
	this->fail = fail;
	this->winRate = (double)win / (win + fail);
}
string AthleteVO::getName()
{
	return this->name;
}
void AthleteVO::setName(string name)
{
	this->name = name;
}
int AthleteVO::getSerialNo()
{
	return this->serialNo;
}
void AthleteVO::setSerialNo(int serialNo)
{
	this->serialNo = serialNo;
}
int AthleteVO::getWin()
{
	return this->win;
}
void AthleteVO::setWin(int win)
{
	this->win = win;
}
int AthleteVO::getFail()
{
	return this->fail;
}
void AthleteVO::setFail(int fail)
{
	this->fail = fail;
}
int AthleteVO::getWinRate()
{
	return this->winRate;
}
void AthleteVO::setWinRate(double winRate)
{
	this->winRate = winRate;
}
void AthleteVO::updateWinRate(string result)
{
	if (result == "win") {
		this->win++;
	}
	else if (result == "fail") {
		this->fail++;
	}
	this->winRate = (double)this->win / (this->win + this->fail);
}


// �����ݿ�������һ���˶�Ա
void AthleteBO::addAthlete(AthleteVO athlete)
{
	athletes.push_back(athlete);
}
// �����ݿ�������һ���˶�Ա
void AthleteBO::addAthletes(vector<AthleteVO> athletes)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		athletes.push_back(*iter);
	}
}

// �����ݿ���ɾ��һ���˶�Ա
void AthleteBO::deleteAthlete(AthleteVO athlete)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		if (iter->getSerialNo() == athlete.getSerialNo() && iter->getName() == athlete.getName()) {
			athletes.erase(iter);
			break;
		}
	}
}

// �����ݿ��и���һ���˶�Ա����Ϣ(ʤ��)��һ����������ã�
void AthleteBO::updateAthlete(AthleteVO athlete)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		if (iter->getSerialNo() == athlete.getSerialNo()) {
			iter->setName(athlete.getName());
			iter->setSerialNo(athlete.getSerialNo());
			iter->setWin(athlete.getWin());
			iter->setFail(athlete.getFail());
			iter->setWinRate(athlete.getWinRate());
			cout << "Serial No " << athlete.getSerialNo() << ", updated in the database." << endl;
			break;
		}
	}
}

// �����ݿ��м����˶�Ա����
vector<AthleteVO> AthleteBO::getAllAthletes()
{
	return athletes;
}
AthleteVO AthleteBO::getAthlete(int serialNo)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		if (iter->getSerialNo() == serialNo) {
			return *iter;
		}
	}
	return AthleteVO(NULL, -1, -1, -1);
}


//������е��˶�Ա
void outputAll(AthleteBO athleteBusinessObject)
{
	vector<AthleteVO> TestAthletes = athleteBusinessObject.getAllAthletes();
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "�˶�Ա�嵥��" << endl;
	for (vector<AthleteVO>::iterator iter = TestAthletes.begin(); iter != TestAthletes.end(); iter++) {
		cout << "Athlete: [SerialNo : " << iter->getSerialNo() << ", Name : " << iter->getName() << ", Win : " << iter->getWin() << ", Fail : " << iter->getFail() << ", Win Rate : " << iter->getWinRate() << " ]" << endl;
	}
	cout << "------------------------------" << endl;
	cout << endl;
}



#include "../Interpreter/Interpreter.h"


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




int testTransferObjectOri()
{
	// ʹ�� AthleteBO ����ʾ����������ģʽ
	AthleteBO athleteBusinessObject;

	//���������˶�Ա
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 17, 5));
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 20, 7));
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 10, 13));

	//������е��˶�Ա
	outputAll(athleteBusinessObject);

	//��ȡ�˶�Ա��Ϣ
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // ���к�Ϊ0���˶�Ա
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	//�����˶�Աʤ����win+1
	cout << athlete.getName() << " wins !" << endl;
	athlete.updateWinRate("win");
	athleteBusinessObject.updateAthlete(athlete);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	//�����˶�Ա�ܳ���fail+1
	cout << athlete.getName() << " fails !" << endl;
	athlete.updateWinRate("fail");
	athleteBusinessObject.updateAthlete(athlete);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	// ɾ���˶�ԱTom
	athleteBusinessObject.deleteAthlete(athleteBusinessObject.getAthlete(1));

	//������е��˶�Ա
	outputAll(athleteBusinessObject);

	return 0;
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

int testTransferObject()
{
	// ʹ�� AthleteBO ����ʾ����������ģʽ
	AthleteBO athleteBusinessObject;
	//������е��˶�Ա
	outputAll(athleteBusinessObject);
	//�����˶�Ա
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 17, 5)); // ѡ��һ
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 20, 7));	// ѡ�ֶ�
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 10, 13));
	athleteBusinessObject.addAthlete(AthleteVO("Tiger", 3, 15, 13));
	athleteBusinessObject.addAthlete(AthleteVO("Cris", 4, 30, 21));
	athleteBusinessObject.addAthlete(AthleteVO("Messi", 5, 1, 3));
	athleteBusinessObject.addAthlete(AthleteVO("Lin", 6, 9, 20));
	athleteBusinessObject.addAthlete(AthleteVO("Wang", 7, 7, 9));
	//������е��˶�Ա
	outputAll(athleteBusinessObject);
	//��ȡ�˶�Ա��Ϣ
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // ���к�Ϊ0���˶�Ա
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	cout << endl;

	/*
	�˶�Ա: 1 2
	���������򷽷���: fs hbs rths shd us sas s
	����ʱ����λ��: b f s l ls r rs a ba
	ս��: hcs fb rs np dfb
	*/
	cout << "Badminton Game Start ! Robert VS John" << endl;

	InstructionHandler hander;
	string outString;

	string player[2] = { "1", "2" };
	string action[7] = { "fs", "hbs", "rths", "shd", "us", "sas", "s" };
	string position[9] = { "b", "f", "s", "l", "ls", "r", "rs", "a", "ba" };
	string tactics[5] = { "hcs", "fb", "rs", "np", "dfb" };
	srand((int)time(0));  // ����������� 
	
	string instruction;
	for (int i = 0; i < 20; i++) {
		instruction = player[i % 2] + " " + action[rand() % 7] + " " + position[rand() % 9] + " " + tactics[rand() % 5];
		hander.handle(instruction);
		cout << hander.output() << endl;
	}
	
	cout << athlete.getName() << " wins !" << endl;

	//������е��˶�Ա
	outputAll(athleteBusinessObject);
	//�����˶�Աʤ����win+1
	athlete.updateWinRate("win");
	athleteBusinessObject.updateAthlete(athlete);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	// ɾ���˶�ԱTom
	cout << endl;
	cout << "delete Athlete with SerialNo 2." << endl;
	athleteBusinessObject.deleteAthlete(athleteBusinessObject.getAthlete(2));
	//������е��˶�Ա
	outputAll(athleteBusinessObject);

	return 0;
}