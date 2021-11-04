#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
/*
 * Factory Method
 */
class fAthlete
{
public:
    fAthlete() {}
    fAthlete(std::string n) : name(n), distance(0), time(0) {}
    void nextSec();
    int getDis() const;
    std::string getName() const;
    bool isFinal() const;
    int getTime() const;

private:
    std::string name;
    int distance;
    int time;
};
/*
 *200米自由泳（女子/男子）
 *200米个人混合泳（女子/男子）
 */
/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Swimming
{
public:
    virtual ~Swimming() {}
    virtual const char* getName() = 0;
    virtual void addAth(fAthlete ath);
    virtual void run();

private:
    std::vector<fAthlete> Athletes;
    std::vector<fAthlete> Res;
};
/*
 * Factory Method
 * provides an abstract interface, preparing for creating various kinds of products
 */
class SwimmingFactory
{
public:
    virtual ~SwimmingFactory() {}
    virtual Swimming* createSwimming() = 0;
};

/*
 * ConcreteProducts
 * define objects to be created by concrete factory
 */

class ManFreestyle200 : public Swimming
{
public:
    ~ManFreestyle200() {}
    const char* getName() { return "200m Man Freestyle"; }
};
class WomenFreestyle200 : public Swimming
{
public:
    ~WomenFreestyle200() {}
    const char* getName() { return "200m Women Freestyle"; }
};
/*
 * Concrete Factorys
 * each concrete factory creates one kind of products and client uses these factories
 */
class ManFreestyle200Factory : public SwimmingFactory
{
public:
    ~ManFreestyle200Factory() {}
    Swimming* createSwimming() { return new ManFreestyle200(); }
};
class WomenFreestyle200Factory : public SwimmingFactory
{
public:
    ~WomenFreestyle200Factory() {}
    Swimming* createSwimming() { return new WomenFreestyle200(); }
};

int testFactoryMethod();