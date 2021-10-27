#pragma once
/*
 * C++ Design Patterns: ForeignTranslator (Object scope)
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
 * defines an existing interface that needs adapting and thanks
 * to ForeignTranslator it will get calls that client makes on the Foreigner
 *
 */
class Mandarin
{
public:
    void specificRequest()
    {
        std::cout << "Translate to their own language" << std::endl;
    }
    // ...
};

/*
 * ForeignTranslator
 * implements the Foreigner interface and when it gets a method call it
 * delegates the call to a Mandarine
 */
class ForeignTranslator : public Foreigner
{
public:
    ForeignTranslator() : adaptee() {}

    ~ForeignTranslator()
    {
        delete adaptee;
    }

    void request()
    {
        adaptee->specificRequest();
        // ...
    }
    // ...

private:
    Mandarin* adaptee;
    // ...
};

int testAdaptor();




