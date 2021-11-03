#include "TransferObject.h"

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