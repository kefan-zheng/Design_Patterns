#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<sstream>
using namespace std;


// �������(Transfer Object)ģʽ�����ڴӿͻ����������һ���Դ��ݴ��ж�����Ե����ݡ�
// �������Ҳ����Ϊ��ֵ����(Value Object)��
// ʵ�壺
//	ҵ�����Business Object�� - Ϊ�������������ݵ�ҵ�����
//	�������Transfer Object�� - �򵥵� POJO��ֻ������ / ��ȡ���Եķ�����
//	�ͻ��ˣ�Client�� - �ͻ��˿��Է���������߷��ʹ������ҵ�����


// �������
class AthleteVO
{
private:
	string name;
	int serialNo;//���
	int medals;//������
public:
	AthleteVO(string name, int serialNo, int medals = 0)
	{
		this->name = name;
		this->serialNo = serialNo;
		this->medals = medals;
	}
	string getName()
	{
		return this->name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	int getSerialNo()
	{
		return this->serialNo;
	}
	void setSerialNo(int serialNo)
	{
		this->serialNo = serialNo;
	}
	int getMedals()
	{
		return this->medals;
	}
	void setMedals(int medals)
	{
		this->medals = medals;
	}
};

// ҵ�����
class SerialNoBO
{
private:
	//�б��ǵ���һ�����ݿ�
	vector<AthleteVO> athletes;

public:
	SerialNoBO()
	{
		;
	}

	// �����ݿ�������һ���˶�Ա
	void addAthlete(AthleteVO athlete)
	{
		athletes.push_back(athlete);
	}
	// �����ݿ�������һ���˶�Ա
	void addAthletes(vector<AthleteVO> athletes)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			athletes.push_back(*iter);
		}
	}

	// �����ݿ���ɾ��һ���˶�Ա
	void deleteAthlete(AthleteVO athlete)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == athlete.getSerialNo() && iter->getName() == athlete.getName()) {
				athletes.erase(iter);
				break;
			}
		}
	}

	// �����ݿ��и���һ���˶�Ա�Ľ�����
	void updateAthlete(AthleteVO athlete)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == athlete.getSerialNo()) {
				iter->setMedals(athlete.getMedals());
				cout << "Athlete: Serial No " << athlete.getSerialNo() << ", updated in the database." << endl;
				break;
			}
		}
	}

	// �����ݿ��м����˶�Ա����
	vector<AthleteVO> getAllAthletes()
	{
		return athletes;
	}
	AthleteVO getAthlete(int serialNo)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == serialNo) {
				return *iter;
			}
		}
		return AthleteVO("error", -1);
	}
};