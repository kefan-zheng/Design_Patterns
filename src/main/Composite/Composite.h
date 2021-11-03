#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<string>
using namespace std;
//��������
class Events {
public:
	Events(string name) :eventName(name), parent(NULL) {}
	//�����µ��������
	virtual void add(Events* e) {
		children.push_back(e);
	}
	//��ñ�������
	virtual string getName() {
		return eventName;
	}
	virtual void show() {
	}
	virtual ~Events() {

	}
protected:
	string eventName;//�������ƣ��ȿ����ǵ�������Ҳ�����Ǹ��ϱ�����
	Events* parent;//�ñ����ĸ���ָ��
	vector<Events*>children;//����������ָ��
};
//���ϱ������̳��Ա�������
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	//չʾ��������
	virtual void show() {
		cout << eventName << " encompasses: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children[i]->getName();
		}
		cout << endl;
		//�ݹ�չʾ��һ����������и��ϱ��������е���������
		for (auto i : children)i->show();
		cout << endl;
	}
private:
};
//�����������̳��Ա�������
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << ", held time��" << _date << ", held site��" << _site << endl;
	}
private:
	string _date;//����ʱ��
	string _site;//�����ص�
};