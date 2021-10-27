#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"../MedalRanking.h"

using namespace std;

class Subject;

/*
 *  Observer: �۲��߳�����
 *  ��Subject�ı�ʱ������Observer�ᱻnotify������
 */
class Observer {
public:
	virtual ~Observer() {}

	virtual MedalRanking getState() = 0;
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
};

/*
 *  ConcreteObserver: �۲��߾����࣬�����Ӧ����ý��
 *  ý���״̬���ǽ��ư����Ϣ�������ư�ı�ʱ������ý��
 */
class ConcreteObserver : public Observer {
public:
	ConcreteObserver(string name, MedalRanking const state);//����ý�������뵱ǰ���ư���Ϣ��ʼ��
	~ConcreteObserver();
	MedalRanking getState(); // ��ȡý��״̬�������ư���Ϣ
	void update(Subject* subject); // ���ư���Ϣ�ı䣬����ý��Ľ��ư���Ϣ
	void showState(); // ��ӡý��״̬�������Ų�����ʽ����
private:
	MedalRanking state; // ���ư���Ϣ
	string name; // ý������
};


/*
 *  Subject: ���۲��ߣ�������������۲��ߵ���Ϣ������״̬�ı�ʱ֪ͨ���۲���
 */
class Subject {
public:
	void attach(Observer* observer); //��ӹ۲���
	void detach(const int index); //�������ɾ��ĳ�۲���
	void notify();//״̬�ı�ʱ������֪ͨ���۲���
	virtual MedalRanking getState() = 0; //��ȡ��ǰ״̬
	virtual void setState(const MedalRanking s) = 0; //����״̬
private:
	vector<Observer*> observers;// ��¼���еĹ۲���
};


/*
 *  ConcreteSubject: �����Ӧ���ǽ��ư񣬵����ư�ı�ʱ������ý����յ�֪ͨ����������������
 */
class ConcreteSubject :public Subject {
public:
	MedalRanking getState();//��ȡ��ǰ״̬��ֱ�ӷ�������洢�Ľ��ư�ʵ��
	void setState(MedalRanking s); //���½��ư�״̬
private:
	MedalRanking state; //���ư�״̬
};

int testObserver();//���Ժ���