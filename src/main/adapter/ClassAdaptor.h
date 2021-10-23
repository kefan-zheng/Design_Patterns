/*
 * C++ Design Patterns: ForeignTranslator (Class scope)
 * Author: Zhibo Xu
 * 2021/10
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

 /*
  * Foreigner
  * defines specific interface that Client uses
  */
class Foreigner
{
public:
    virtual ~Foreigner() {}

    virtual void request() = 0;
    // ...
};

/*
 * Mandarine
 * all requests get delegated to the Mandarine which defines
 * an existing interface that needs adapting
 */
class Mandarine
{
public:
    ~Mandarine() {}

    void specificRequest()
    {
        std::cout << "specific request" << std::endl;
    }
    // ...
};

/*
 * ForeignTranslator
 * implements the Foreigner interface and lets the Mandarine respond
 * to request on a Foreigner by extending both classes
 * ie adapts the interface of Mandarine to the Foreigner interface
 */
class ForeignTranslator : public Foreigner, private Mandarine
{
public:
    virtual void request()
    {
        specificRequest();
    }
    // ...
};


//int main()
//{
//    Foreigner* t = new ForeignTranslator();
//    t->request();
//    delete t;
//
//    return 0;
//}