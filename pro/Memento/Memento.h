#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include"../MedalRanking.h"
using namespace std;

/*
 *  Memento: ��¼��Originatorʵ����state����ֻ�ܱ�Originator�����
 *  �����state����һ�����ư�MedalRankingʵ��
 */
class Memento {
private:
	friend class Originator;
	Memento(const MedalRanking& m); //���ݽ��ư�ʵ������Memento����
	MedalRanking getState(); // ��ȡ��ǰ״̬
private:
	MedalRanking medalState; // ״̬(state)��Ϣ����һ�����ư�ʵ��
};


/*
 *  Originator: ΪĳЩ��Ϣ��������¼��ÿһ������¼��״̬����¼��һ��Menmentoʵ����
 *  �����OrignatorΪ���ư���Ϣ��������¼
 */
class Originator {
public:
	void setState(MedalRanking m); //���ݽ��ư���ʵ��ֱ������state
	void setState(Memento* m); //����Menmento�д�ŵĽ��ư���Ϣ����state
	void showState(); //��ӡ��ǰ״̬
	MedalRanking getState(); //��ȡ��ǰ״̬
	Memento* createMemento(); //���ݵ�ǰ״̬����һ���µ�Memento��ʵ����������ָ��
private:
	MedalRanking state; // ״̬��������һ�����ư�ʵ��
};


/*
 *  CareTaker: ����Ӧһ��Originator����Originator������ÿһ��״̬��Ӧ��Memento�����¼������
 *	���ݳ�Աhistory(Vector<Memento*>)��; CareTaker���ڱ��桢�ָ���ʷ��Ϣ
 */
class CareTaker {
public:
	CareTaker(Originator* const o); //���캯���д���Originatorָ���Գ�ʼ�����Ӧ��Ա
	~CareTaker(); 
	void save();//���浱ǰ״̬
	void undo();//�ָ�Ϊ��һ��״̬
	void showState(); //��ӡ��ǰ״̬
private:
	Originator* originator;
	vector<Memento*> history; //���������ڼ�¼����ʷ״̬
};

int testMemento();//���Ժ���