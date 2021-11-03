#include "TransferObject.h"

//������е��˶�Ա
void outputAll(SerialNoBO athleteBusinessObject)
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

int testTransferObject()
{
	// ʹ�� AthleteBO ����ʾ����������ģʽ
	SerialNoBO athleteBusinessObject;

	//���������˶�Ա
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 17, 5));
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 20, 7));
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 10, 13));

	//������е��˶�Ա
	outputAll(athleteBusinessObject);

	//��ȡ�˶�Ա��Ϣ
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // ���к�Ϊ0���˶�Ա
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " <<  athlete.getName() << ", Win : " << athlete.getWin() << ", Fail : " << athlete.getFail() << ", Win Rate : " << athlete.getWinRate() << " ]" << endl;

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