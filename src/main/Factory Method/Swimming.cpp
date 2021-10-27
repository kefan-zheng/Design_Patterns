#include <vector>

/*
 * Factory Method
 */
/*
 *200米自由泳（女子/男子）
 *200米个人混合泳（女子/男子）
 *4×100米男女混合泳接力
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
    virtual const char *getName() = 0;
};
/*
 * Factory Method
 * provides an abstract interface, preparing for creating various kinds of products
 */
class SwimmingFactory
{
public:
    virtual ~SwimmingFactory() {}
    virtual Swimming *createSwimming() = 0;
};

/*
 * ConcreteProducts
 * define objects to be created by concrete factory
 */

class ManFreestyle200 : public Swimming
{
public:
    ~ManFreestyle200() {}
    const char *getName() { return "200m Man Freestyle"; }
};
class WomenFreestyle200 : public Swimming
{
public:
    ~WomenFreestyle200() {}
    const char *getName() { return "200m Women Freestyle"; }
};
class ManMedley200 : public Swimming
{
public:
    ~ManMedley200() {}
    const char *getName() { return "200m Man Medley"; }
};
class WomenMedley200 : public Swimming
{
public:
    ~WomenMedley200() {}
    const char *getName() { return "200m Women Medley"; }
};
class MNWMedleyDelay400 : public Swimming
{
public:
    ~MNWMedleyDelay400() {}
    const char *getName() { return "4*100m Man&Women Medley Delay"; }
};
/*
 * Concrete Factorys
 * each concrete factory creates one kind of products and client uses these factories
 */
class ManFreestyle200Factory : public SwimmingFactory
{
public:
    ~ManFreestyle200Factory() {}
    Swimming *createSwimming() { return new ManFreestyle200(); }
};
class WomenFreestyle200Factory : public SwimmingFactory
{
public:
    ~WomenFreestyle200Factory() {}
    Swimming *createSwimming() { return new WomenFreestyle200(); }
};
class ManMedley200Factory : public SwimmingFactory
{
public:
    ~ManMedley200Factory() {}
    Swimming *createSwimming() { return new ManMedley200(); }
};
class WomenMedley200Factory : public SwimmingFactory
{
public:
    ~WomenMedley200Factory() {}
    Swimming *createSwimming() { return new WomenMedley200(); }
};
class MNWMedleyDelay400Factory : public SwimmingFactory
{
public:
    ~MNWMedleyDelay400Factory() {}
    Swimming *createSwimming() { return new MNWMedleyDelay400(); }
};