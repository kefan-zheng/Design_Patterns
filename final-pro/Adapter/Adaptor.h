/*
 * C++ Design Patterns: VolunteerTranslator (Object scope)
 * Author: Zhibo Xu
 * 2021/10
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>
using std::string;
using std::cout;
using std::endl;
 /*
  * Volunteer
  * defines specific interface that Client uses
  */
class Volunteer1
{
public:

    virtual ~Volunteer1() {}

    virtual void request() = 0;
    // ...
};

/*
 * Mandarine
 * defines an existing interface that needs adapting and thanks
 * to VolunteerTranslator it will get calls that client makes on the Volunteer
 *
 */
class ForeignLanguage
{
    string nation;
    string languageType;
public:
    ForeignLanguage(){};
    ForeignLanguage(std::string nation,std::string language)
    {
      this->nation=nation;
      this->languageType=language;
    };
    void specificRequest()
    {
        cout << "translate content to "<<this->getLanguageType()<<".";
    };
    string getNation()
    {
        return this->nation;
    };
    string getLanguageType()
    {
        return this->languageType;
    };
    // ...
};

/*
 * VolunteerTranslator
 * implements the Volunteer interface and when it gets a method call it
 * delegates the call to a Mandarine
 */
class VolunteerTranslator : public Volunteer1
{
public:
    VolunteerTranslator(ForeignLanguage* adptee2)
    {
        this->adaptee=new ForeignLanguage();
        this->adaptee=adptee2;
    }
    ~VolunteerTranslator()
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
    ForeignLanguage* adaptee;
    // ...
};

void testAdaptor();



