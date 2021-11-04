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

using namespace std;

const string designpatterns[30] = { 

//����ǰ��Ӧ�ļ������ģʽ
"iterator",// ��Ļʽ
"adapter",//���ⷭ��
"facade",//(mutition)��ס���˴�
"templatemethod",//(flyweight)�������
"immutable",//��ӡ������Ŀ
"composite",//(stategy)��ӡ��������
"bridge",//�˶�Ա��������־Ը�����ҽ���

//������Ŀ
"builder",//������Ŀ
"factorymethod",//��Ӿ
"delegation",//(prototype)��ˮ
"decorator",//(abstracFactory)�ܲ���ƹ��
"visitor",//����
"mediator",//(command)����
"mvc","state",//����������������
"transferobject","interpreter",//��ë��
"specification",//����

//����
"observer",//���ڶԽ��ư�仯�ķ�Ӧ
"memento",// ���ư�״̬��¼��仯
"chainofresponsibility", //����
"proxy",//ҩ���ѯ

//�����������ģʽ���ϲ����������ģʽ���Ժ�����
"flyweight","strategy","command","frontController","abstractfactory","multition", "singleton" ,"prototype" 
};
//, "privateClassData";����ɾ���Ķ������ģʽ

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