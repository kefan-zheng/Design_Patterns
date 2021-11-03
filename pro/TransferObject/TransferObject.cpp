#include "TransferObject.h"


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


// 从数据库中增加一个运动员
void SerialNoBO::addAthlete(AthleteVO athlete)
{
	athletes.push_back(athlete);
}
// 从数据库中增加一堆运动员
void SerialNoBO::addAthletes(vector<AthleteVO> athletes)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		athletes.push_back(*iter);
	}
}

// 从数据库中删除一个运动员
void SerialNoBO::deleteAthlete(AthleteVO athlete)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		if (iter->getSerialNo() == athlete.getSerialNo() && iter->getName() == athlete.getName()) {
			athletes.erase(iter);
			break;
		}
	}
}

// 从数据库中更新一个运动员的信息(胜率)（一场比赛后调用）
void SerialNoBO::updateAthlete(AthleteVO athlete)
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

// 从数据库中检索运动员名单
vector<AthleteVO> SerialNoBO::getAllAthletes()
{
	return athletes;
}
AthleteVO SerialNoBO::getAthlete(int serialNo)
{
	for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
		if (iter->getSerialNo() == serialNo) {
			return *iter;
		}
	}
	return AthleteVO(NULL, -1, -1, -1);
}


//输出所有的运动员
void outputAll(SerialNoBO athleteBusinessObject)
{
	vector<AthleteVO> TestAthletes = athleteBusinessObject.getAllAthletes();
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "运动员清单：" << endl;
	for (vector<AthleteVO>::iterator iter = TestAthletes.begin(); iter != TestAthletes.end(); iter++) {
		cout << "Athlete: [SerialNo : " << iter->getSerialNo() << ", Name : " << iter->getName() << ", Win : " << iter->getWin() << ", Fail : " << iter->getFail() << ", Win Rate : " << iter->getWinRate() << " ]" << endl;
	}
	cout << "------------------------------" << endl;
	cout << endl;
}



int testTransferObject()
{
	// 使用 AthleteBO 来演示传输对象设计模式
	SerialNoBO athleteBusinessObject;

	//插入三个运动员
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 17, 5));
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 20, 7));
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 10, 13));

	//输出所有的运动员
	outputAll(athleteBusinessObject);

	//获取运动员信息
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // 序列号为0的运动员
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " <<  athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	//更新运动员胜场数win+1
	cout << athlete.getName() << " wins !" << endl;
	athlete.updateWinRate("win");
	athleteBusinessObject.updateAthlete(athlete);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	//更新运动员败场数fail+1
	cout << athlete.getName() << " fails !" << endl;
	athlete.updateWinRate("fail");
	athleteBusinessObject.updateAthlete(athlete);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

	// 删除运动员Tom
	athleteBusinessObject.deleteAthlete(athleteBusinessObject.getAthlete(1));

	//输出所有的运动员
	outputAll(athleteBusinessObject);

	return 0;
}