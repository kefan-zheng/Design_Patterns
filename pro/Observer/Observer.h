#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"../utils/AbstractMedalRanking.h"
#include"../utils/MedalRanking.h"
#include"../utils/SingletonMedalRanking.h"
using namespace std;

class Subject;

/*
 *  Observer: �۲��߳�����
 *  ��Subject�ı�ʱ������Observer�ᱻnotify������
 */
class Observer {
public:
	virtual ~Observer() {}
	virtual void update(Subject* subject) = 0;
	virtual void showState() = 0;
};

/*
 *  ObserverAudience: �۲��߾����࣬�����Ӧ����ý��
 *  ý���״̬���ǽ��ư����Ϣ�������ư�ı�ʱ������ý��
 */
class ObserverMedia : public Observer {
public:
	ObserverMedia(string name, MedalRanking const state);//����ý�������뵱ǰ���ư���Ϣ��ʼ��
	~ObserverMedia();
	MedalRanking getState(); // ��ȡý��״̬�������ư���Ϣ
	void update(Subject* subject); // ���ư���Ϣ�ı䣬����ý��Ľ��ư���Ϣ
	void showState(); // ��ӡý��״̬�������Ų�����ʽ����
private:
	MedalRanking state; // ���ư���Ϣ
	string name; // ý������
};


//�۲���(����)��״̬�����ư����ǰΪsleepy�����ư���º�Ϊexcited
enum class ObserverAudienceState { sleepy=0, excited=1 };

/*
 *  ObserverAudience: �۲��߾����࣬�����Ӧ���ǹ���
 *  ��״̬���µĽ���Ǵ�ӡ��Ӧ����Ϣ
 */
class ObserverAudience : public Observer {
public:
	ObserverAudience(string name);//���ݹ������ֳ�ʼ��
	void update(Subject* s); // ���ư���Ϣ�ı䣬���ڱ��˷�
	void showState();// ��ӡ��ǰ״̬��Ϣ
private:
	string name; // ��������
	ObserverAudienceState state;
};


/*
 *  Subject: ���۲��ߣ�������������۲��ߵ���Ϣ������״̬�ı�ʱ֪ͨ���۲���
 */
class Subject {
public:
	void attach(Observer* observer); //��ӹ۲���
	void detach(const int index); //�������ɾ��ĳ�۲���
	void notify();//״̬�ı�ʱ������֪ͨ���۲���
	virtual SingletonMedalRanking& getState()=0;
private:
	vector<Observer*> observers;// ��¼���еĹ۲���
};


/*
 *  ConcreteSubject: �����Ӧ���ǽ��ư񣬵����ư�ı�ʱ������ý����յ�֪ͨ����������������
 */
class ConcreteSubject :public Subject {
public:
	ConcreteSubject():state(SingletonMedalRanking::Instance()) {}
	SingletonMedalRanking& getState();//��ȡ��ǰ״̬��ֱ�ӷ�������洢�Ľ��ư�ʵ��
private:
	SingletonMedalRanking& state; //���ư�״̬
};

void testObserver();//���Ժ���