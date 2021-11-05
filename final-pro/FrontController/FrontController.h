#pragma once
#include<iostream>
#include"../AbstractFactory/AbstractFactory.h"
#include"../Adapter/Adaptor.h"
#include"../Bridge/Bridge.h"
#include"../Builder/Builder.h"
#include"../ChainOfResponsibility/ChainOfResponsibility.h"
#include"../Command/Command.h"
#include"../Composite/Composite.h"
#include"../Decorator/Decorator.h"
#include"../Delegation/Delegation.h"
#include"../Facade/Facade.h"
#include"../FactoryMethod/Swimming.h"
#include"../Flyweight/Flyweight.h"
#include"../Immutable/Immutable.h"
#include"../Interpreter/Interpreter.h"
#include"../Iterator/Iterator.h"
#include"../Mediator/Mediator.h"
#include"../Mvc/Mvc.h"
#include"../Observer/Observer.h"
#include"../Memento/Memento.h"
#include"../Prototype/Prototype.h"
#include"../Proxy/Proxy.h"
#include"../Specification/Specification.h"
#include"../State/State.h"
#include"../Strategy/Strategy.h"
#include"../TemplateMethod/TemplateMethod.h"
#include"../TransferObject/TransferObject.h"
#include"../Visitor/Visitor.h"
#include"../utils/cct_tools.h"

using namespace std;

const string designpatterns[30] = { 

//比赛前对应的几个设计模式
"facade",//(mutition)入住奥运村
"iterator",// 开幕式
"adapter",//场外翻译
"templatemethod",//(flyweight)场外管理
"immutable",//打印比赛项目
"composite","strategy",//(stategy)打印比赛详情
"bridge",//运动员、教练、志愿者自我介绍

//比赛项目
"builder",//击剑
"factorymethod",//游泳
"delegation",//(prototype)跳水
"decorator",//(abstracFactory)跑步、乒乓
"visitor",//足球
"mediator",//(command)篮球
"mvc","state",//铁人三项介绍与过程
"transferobject","interpreter",//羽毛球
"specification",//举重

//其他
"observer",//观众对奖牌榜变化的反应
"memento",// 奖牌榜状态记录与变化
"chainofresponsibility", //申诉
"proxy",//药检查询

//下面所有设计模式被合并到其他设计模式测试函数中
"flyweight","command","frontController","abstractfactory","multition", "singleton" ,"prototype" 
};
//, "privateClassData";考虑删除的多余设计模式

class Dispatcher
{
public:
	Dispatcher(){}

	void dispatch(string request);
};

class FrontController
{
private:
	Dispatcher* dispatcher;

	void trackRequest(string request);
public:
	FrontController() : dispatcher(){}

	void set(Dispatcher* d);

	void dispatchRequest(string request);
};
