#include"./LinkList.h"
using namespace std;
//比赛基类
class Events {
public:
	Events(string name) :eventName(name) {}
	virtual void add(Events* e) {

	}
	//删除某一分支的函数
	virtual void remove(Events*e,Events *o) {

	}
	//获取该类的类型，1代表复合比赛，2代表单个比赛
	virtual int getType() = 0;

	virtual LinkList<Events*>* getChildren() {
		LinkList<Events*>* null = new LinkList<Events*>;
		return null;
	}
	//获得比赛名称
	string getName() {
		return eventName;
	}
	virtual void show() = 0;
	virtual ~Events() {

	}
protected:
	string eventName;//比赛名称（既可以是单个比赛也可以是复合比赛）
};
//复合比赛，继承自比赛基类
class CompositeEvents :public Events {
public:
	CompositeEvents(string name) :Events(name) {}
	//在子类中增加比赛
	virtual void add(Events* e) {
		children.pushBack(e);
	}
	virtual int getType() {
		return 1;
	}
	//递归地删除某一分支,e是要删除的元素，o是递归过程中的当前父类
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
	//获得指向children数据的指针，主要用于remove操作
	virtual LinkList<Events*>* getChildren() {
		return &children;
	}
	//展示单个比赛
	virtual void show() {
		cout << eventName << " encompasses: ";
		for (int i = 0; i < children.size(); ++i) {
			if (i)cout << ", ";
			cout << children.at(i)->getName();
		}
		cout << endl;
		//递归展示下一层比赛（既有复合比赛，又有单个比赛）
		for (int i = 0; i < children.size(); ++i)children.at(i)->show();
		cout << endl;
	}
private:
	LinkList<Events*>children;//比赛的子类指针
};
//单个比赛，继承自比赛基类
class SingleEvents :public Events {
public:
	SingleEvents(string name, string date, string site) :Events(name), _date(date), _site(site) {}
	virtual void show() {
		cout << eventName << ", held time：" << _date << ", held site：" << _site << endl;
	}
	virtual int getType() {
		return 2;
	}
private:
	string _date;//比赛时间
	string _site;//比赛地点
};

int testComposite();