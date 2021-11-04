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
	AthleteVO(string name, int serialNo, int win, int fail);
	string getName();
	void setName(string name);
	int getSerialNo();
	void setSerialNo(int serialNo);
	int getWin();
	void setWin(int win);
	int getFail();
	void setFail(int fail);
	int getWinRate();
	void setWinRate(double winRate);
	void updateWinRate(string result);
};

// ҵ�����
class SerialNoBO
{
private:
	//�б��ǵ���һ�����ݿ�
	vector<AthleteVO> athletes;

public:
	// �����ݿ�������һ���˶�Ա
	void addAthlete(AthleteVO athlete);
	// �����ݿ�������һ���˶�Ա
	void addAthletes(vector<AthleteVO> athletes);

	// �����ݿ���ɾ��һ���˶�Ա
	void deleteAthlete(AthleteVO athlete);

	// �����ݿ��и���һ���˶�Ա����Ϣ(ʤ��)��һ����������ã�
	void updateAthlete(AthleteVO athlete);

	// �����ݿ��м����˶�Ա����
	vector<AthleteVO> getAllAthletes();
	AthleteVO getAthlete(int serialNo);
};

int testTransferObject();