#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Events {
public:
	Events(string name) :eventName(name),parent(NULL) {}
	virtual void add(Events*e) {
		children.push_back(e);
	}
	virtual string getName() {
		return eventName;
	}
	virtual void show() {
	}
	virtual ~Events() {
		
	}
protected:
	string eventName;
	Events* parent;
	vector<Events*>children;
};
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	virtual void show() {
		cout << eventName << "����: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children[i]->getName();
		}
		cout << endl;
		for (auto i : children)i->show();
	}
private:
};
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << " �ľٰ�ʱ��Ϊ��" << _date << "���ٰ�ص�Ϊ��" << _site << endl;
	}
private:
	string _date;
	string _site;
};
int main() {
	CompositeEvents* overallEvents=new CompositeEvents("����");
	CompositeEvents* swimming=new CompositeEvents("��Ӿ");
	CompositeEvents* running = new CompositeEvents("�ܲ�");
	overallEvents->add(swimming);
	overallEvents->add(running);
	swimming->add(new SingleEvents("����50����Ӿ", "2021-10-19 14:00", "1����Ӿ��"));
	swimming->add(new SingleEvents("Ů��50������Ӿ", "2021-10-20 15:00", "1����Ӿ��"));
	swimming->add(new SingleEvents("����100�׵�Ӿ", "2021-10-18 10:00", "3����Ӿ��"));
	running->add(new SingleEvents("����100������", "2021-10-17 10:30", "1���ﾶ��"));
	running->add(new SingleEvents("Ů��1000������", "2021-10-20 14:30", "2���ﾶ��"));
	overallEvents->show();
	return 0;
}