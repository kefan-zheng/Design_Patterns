#pragma once
//��������ֻ��һ��ƹ���򹤳����������������Ŀ
 //���˱���
class Single
{
public:
    virtual ~Single() {}

    virtual const char* getName() = 0;
};

//���ӵ���
class MenSingle : public Single
{
public:
    ~MenSingle() {}

    const char* getName();
};

//Ů�ӵ���
class WomenSingle : public Single
{
public:
    ~WomenSingle() {}

    const char* getName();
};

//˫�˱���
class Doubles
{
public:
    virtual ~Doubles() {}

    virtual const char* getName() = 0;
};

//����˫��
class MenDoubles : public Doubles
{
public:
    ~MenDoubles() {}

    const char* getName();
};

//Ů��˫��
class WomenDoubles : public Doubles
{
public:
    ~WomenDoubles() {}

    const char* getName();
};

//���󹤳�
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    //������Ʒ
    virtual Single* createSingleGame() = 0;
    virtual Doubles* createDoublesGame() = 0;
};

//ƹ���򹤳����̳��Գ��󹤳�
class TableTennisFactory : public AbstractFactory
{
public:
    ~TableTennisFactory() {}

    Single* createSingleGame();

    Doubles* createDoublesGame();
};

int testAbstractFactory();