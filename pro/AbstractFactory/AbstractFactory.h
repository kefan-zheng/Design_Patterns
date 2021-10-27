#pragma once
//本例子中只有一个乒乓球工厂，产生多个比赛项目
 //单人比赛
class Single
{
public:
    virtual ~Single() {}

    virtual const char* getName() = 0;
};

//男子单打
class MenSingle : public Single
{
public:
    ~MenSingle() {}

    const char* getName();
};

//女子单打
class WomenSingle : public Single
{
public:
    ~WomenSingle() {}

    const char* getName();
};

//双人比赛
class Doubles
{
public:
    virtual ~Doubles() {}

    virtual const char* getName() = 0;
};

//男子双打
class MenDoubles : public Doubles
{
public:
    ~MenDoubles() {}

    const char* getName();
};

//女子双打
class WomenDoubles : public Doubles
{
public:
    ~WomenDoubles() {}

    const char* getName();
};

//抽象工厂
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    //两个产品
    virtual Single* createSingleGame() = 0;
    virtual Doubles* createDoublesGame() = 0;
};

//乒乓球工厂，继承自抽象工厂
class TableTennisFactory : public AbstractFactory
{
public:
    ~TableTennisFactory() {}

    Single* createSingleGame();

    Doubles* createDoublesGame();
};

int testAbstractFactory();