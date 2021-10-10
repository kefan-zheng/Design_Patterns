//本例子中只有一个工厂（乒乓球），产生多个比赛项目
#include <iostream>

 /*
  * Product A
  * products implement the same interface so that the classes can refer
  * to the interface not the concrete product
  */
class Single
{
public:
    virtual ~Single() {}

    virtual const char* getName() = 0;
};

/*
 * ConcreteProductAX and ConcreteProductAY
 * define objects to be created by concrete factory
 */
class MenSingle : public Single
{
public:
    ~MenSingle() {}

    const char* getName()
    {
        return "MenSingle";
    }
};

class WomenSingle : public Single
{
public:
    ~WomenSingle() {}

    const char* getName()
    {
        return "WomenSingle";
    }
};

/*
 * Product B
 * same as Product A, Product B declares interface for concrete products
 * where each can produce an entire set of products
 */
class Doubles
{
public:
    virtual ~Doubles() {}

    virtual const char* getName() = 0;
};

/*
 * ConcreteProductBX and ConcreteProductBY
 * same as previous concrete product classes
 */
class MenDoubles : public Doubles
{
public:
    ~MenDoubles() {}

    const char* getName()
    {
        return "MenDoubles";
    }
};

class WomenDoubles : public Doubles
{
public:
    ~WomenDoubles() {}

    const char* getName()
    {
        return "WomenDoubles";
    }
};

/*
 * Abstract Factory
 * provides an abstract interface for creating a family of products
 */
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}

    virtual Single* createSingleGame() = 0;
    virtual Doubles* createDoublesGame() = 0;
};

/*
 * Concrete Factory X and Y
 * each concrete factory create a family of products and client uses
 * one of these factories so it never has to instantiate a product object
 */
class TableTennisFactory : public AbstractFactory
{
public:
    ~TableTennisFactory() {}

    Single* createSingleGame()
    {
        return new MenSingle();
    }
    Doubles* createDoublesGame()
    {
        return new MenDoubles();
    }
};

int test_abstractfactory()
{
    TableTennisFactory* factory = new TableTennisFactory();

    Single* p1 = factory->createSingleGame();
    Doubles* p2 = factory->createDoublesGame();
    std::cout << "ProjectName1: " << p1->getName() << std::endl;
    std::cout << "ProjectName2: " << p2->getName() << std::endl;

    delete p1;
    delete p2;

    delete factory;

    return 0;
}