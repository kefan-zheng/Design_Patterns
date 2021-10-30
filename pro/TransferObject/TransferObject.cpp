#include "TransferObject.h"

//������е��˶�Ա
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
	// ʹ�� AthleteBO ����ʾ����������ģʽ
	SerialNoBO athleteBusinessObject;
	athleteBusinessObject.addAthlete(AthleteVO("Robert", 0, 0));
	athleteBusinessObject.addAthlete(AthleteVO("John", 1, 0));
	athleteBusinessObject.addAthlete(AthleteVO("Tom", 2, 0));

	//������е��˶�Ա
	output(athleteBusinessObject);

	//�����˶�Ա������+1
	AthleteVO athlete = athleteBusinessObject.getAthlete(0); // ��һ��ѧ��
	athlete.setMedals(athlete.getMedals() + 1);
	athleteBusinessObject.updateAthlete(athlete);

	//��ȡ�˶�Ա��Ϣ
	athleteBusinessObject.getAthlete(0);
	cout << "Athlete: [SerialNo : " << athlete.getSerialNo() << ", Name : " << athlete.getName() << ", Medals : " << athlete.getMedals() << " ]" << endl;

	// ɾ���˶�ԱTom
	athleteBusinessObject.deleteAthlete(athleteBusinessObject.getAthlete(1));

	//������е��˶�Ա
	output(athleteBusinessObject);

	return 0;
}