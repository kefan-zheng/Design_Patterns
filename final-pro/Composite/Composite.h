#include"./LinkList.h"
using namespace std;
//��������
class Events {
public:
	Events(string name) :eventName(name) {}
	virtual void add(Events* e) {

	}
	//ɾ��ĳһ��֧�ĺ���
	virtual void remove(Events*e,Events *o) {

	}
	//��ȡ��������ͣ�1�����ϱ�����2����������
	virtual int getType() = 0;

	virtual LinkList<Events*>* getChildren() {
		LinkList<Events*>* null = new LinkList<Events*>;
		return null;
	}
	//��ñ�������
	string getName() {
		return eventName;
	}
	virtual void show() = 0;
	virtual ~Events() {

	}
protected:
	string eventName;//�������ƣ��ȿ����ǵ�������Ҳ�����Ǹ��ϱ�����
};
//���ϱ������̳��Ա�������
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	//�����������ӱ���
	virtual void add(Events* e) {
		children.pushBack(e);
	}
	virtual int getType() {
		return 1;
	}
	//�ݹ��ɾ��ĳһ��֧,e��Ҫɾ����Ԫ�أ�o�ǵݹ�����еĵ�ǰ����
	virtual void remove(Events*e,Events *o) {
		LinkList<Events*>* _children = o->getChildren();
		for (int i = 0; i < _children->size(); ++i) {
			if (e == _children->at(i)) {
				Events* del = _children->at(i);
				if (del->getType() == 1) {
					LinkList<Events*>* p = del->getChildren();
					while (p->size()) {
						remove(p->at(0),del);
					}
				}
				_children->del(i);
			}
		}
	}
	//���ָ��children���ݵ�ָ�룬��Ҫ����remove����
	virtual LinkList<Events*>* getChildren() {
		return &children;
	}
	//չʾ��������
	virtual void show() {
		cout << eventName << " encompasses: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children.at(i)->getName();
		}
		cout << endl;
		//�ݹ�չʾ��һ����������и��ϱ��������е���������
		for (int i = 0; i < children.size(); ++i)children.at(i)->show();
		cout << endl;
	}
private:
	LinkList<Events*>children;//����������ָ��
};
//�����������̳��Ա�������
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << ", held time��" << _date << ", held site��" << _site << endl;
	}
	virtual int getType() {
		return 2;
	}
private:
	string _date;//����ʱ��
	string _site;//�����ص�
};

int testComposite();