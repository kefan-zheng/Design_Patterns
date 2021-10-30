#include "TransferObject.h"

//输出所有的运动员
void output(SerialNoBO athleteBusinessObject)
{
	vector<AthleteVO> TestAthletes = athleteBusinessObject.getAllAthletes();
	cout << "------------------------------" << endl;
	for (vector<AthleteVO>::iterator iter = TestAthletes.begin(); iter != TestAthletes.end(); iter++) {
		cout << "Athlete: [SerialNo : " << iter->getSerialNo() << ", Name : " << iter->getName() << ", Medals : " << iter->getMedals() << "]" << endl;
	}
	cout << "------------------------------" << endl;
}

int testTransferObject()
{
	// 使用 AthleteBO 来演示传输对象设计模式
	SerialNoBO athleteBusinessObject;
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 0));
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 0));
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 0));

	//输出所有的运动员
	output(athleteBusinessObject);

	//更新运动员奖牌数+1
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // 第一个学生
	athlete.setMedals(athlete.getMedals() + 1);
	athleteBusinessObject.updateAthlete(athlete);

	//获取运动员信息
	athleteBusinessObject.getAthlete(0);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Medals : " << athlete.getMedals() << " ]" << endl;

	// 删除运动员Tom
	athleteBusinessObject.deleteAthlete(athleteBusinessObject.getAthlete(1));

	//输出所有的运动员
	output(athleteBusinessObject);

	return 0;
}