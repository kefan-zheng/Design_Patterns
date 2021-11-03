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
	int win;
	int fail;
	double winRate;//ʤ��
public:
	AthleteVO(string name, int serialNo, int win, int fail)
	{
		this->name = name;
		this->serialNo = serialNo;
		this->win = win;
		this->fail = fail;
		this->winRate = (double)win / (win + fail);
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
	int getWin()
	{
		return this->win;
	}
	void setWin(int win)
	{
		this->win = win;
	}
	int getFail()
	{
		return this->fail;
	}
	void setFail (int fail)
	{
		this->fail = fail;
	}
	int getWinRate()
	{
		return this->winRate;
	}
	void setWinRate(double winRate)
	{
		this->winRate = winRate;
	}
	void updateWinRate(string result)
	{
		if (result == "win") {
			this->win++;
		}
		else if (result == "fail") {
			this->fail++;
		}
		this->winRate = (double)this->win / (this->win + this->fail);
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

	// �����ݿ��и���һ���˶�Ա����Ϣ(ʤ��)��һ����������ã�
	void updateAthlete(AthleteVO athlete)
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
		return AthleteVO(NULL, -1, -1, -1);
	}
};

int testTransferObject();