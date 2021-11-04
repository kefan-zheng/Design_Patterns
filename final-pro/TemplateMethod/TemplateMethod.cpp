#include "iostream"
#include "TemplateMethod.h"
#include "../Flyweight/Flyweight.h"
#include <windows.h>
class SwimmingFactory:public FlyweightFactory
{
public:
    SwimmingFactory()
    {
        map<string,ConcreteCompetition*>* p=this->getFlyWeights();
        p->insert(make_pair("100m freestyle", new ConcreteCompetition("100m freestyle")));
        p->insert(make_pair("200m back stroke", new ConcreteCompetition("200m back stroke")));
        p->insert(make_pair("100m butterfly stroke", new ConcreteCompetition("100m butterfly stroke")));
        p->insert(make_pair("400m medly stroke", new ConcreteCompetition("400m medly stroke")));
    }
    ~SwimmingFactory(){};
    ConcreteCompetition* GetFlyweight(string key)
    {
        map<string,ConcreteCompetition*>* p=this->getFlyWeights();
        if (!p->count(key))
        {
            p->insert(make_pair(key, new ConcreteCompetition(key)));
        }
        return (ConcreteCompetition*)(*p)[key];
    }
};
class WudokanFactory:public FlyweightFactory
{
public:
    WudokanFactory(){
        map<string,ConcreteCompetition*>* p=this->getFlyWeights();
        p->insert(make_pair("Taekwondo 49kg class", new ConcreteCompetition("Taekwondo 49kg class")));
        p->insert(make_pair("Taekwondo 58kg class", new ConcreteCompetition("Taekwondo 58kg class")));
        p->insert(make_pair("Judo 48kg class", new ConcreteCompetition("Judo 48kg class")));
        p->insert(make_pair("Judo 60kg class", new ConcreteCompetition("Judo 60kg class")));
        p->insert(make_pair("Karate 67kg class", new ConcreteCompetition("Karate 67kg class")));
        p->insert(make_pair("Karate 55kg class", new ConcreteCompetition("Karate 55kg class")));
    }
    ~WudokanFactory(){};
    ConcreteCompetition* GetFlyweight(string key)
    {
        map<string,ConcreteCompetition*>* p=this->getFlyWeights();
        if (!p->count(key))
        {
            p->insert(make_pair(key, new ConcreteCompetition(key)));
        }
        return (ConcreteCompetition*)(*p)[key];
    }
};
void TrackFieldVenues::holdGame() {
    FlyweightFactory*factory = new FlyweightFactory();
    ConcreteCompetition* items;
    int i = 0;
    items = factory->GetFlyweight("100m race");
    items->Execute(++i);
    items = factory->GetFlyweight("200m race");
    items->Execute(++i);
    items = factory->GetFlyweight("400m race");
    items->Execute(++i);
    items = factory->GetFlyweight("800m race");
    items->Execute(++i);
    items = factory->GetFlyweight("1500m race");
    items->Execute(++i);
    items = factory->GetFlyweight("5000m race");
}
void SwimmingVenues::holdGame() {
    SwimmingFactory*factory = new SwimmingFactory();
    ConcreteCompetition* items;
    int i = 0;
    items = factory->GetFlyweight("100m freestyle");
    items->Execute(++i);
    items = factory->GetFlyweight("200m back stroke");
    items->Execute(++i);
    items = factory->GetFlyweight("100m butterfly stroke");
    items->Execute(++i);
    items = factory->GetFlyweight("400m medly stroke");
    items->Execute(++i);
}
void Wudokan::holdGame() {
    WudokanFactory*factory = new WudokanFactory();
    ConcreteCompetition* items;
    int i = 0;
    items = factory->GetFlyweight("Taekwondo 49kg class");
    items->Execute(++i);
    items = factory->GetFlyweight("Taekwondo 58kg class");
    items->Execute(++i);
    items = factory->GetFlyweight("Judo 48kg class");
    items->Execute(++i);
    items = factory->GetFlyweight("Judo 60kg class");
    items->Execute(++i);
    items = factory->GetFlyweight("Karate 67kg class");
    items->Execute(++i);
    items = factory->GetFlyweight("Karate 55kg class");
}
void delay_time()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<'.';
        //Sleep(200);//暂时注释掉，最后记得加回来
    }
    std::cout<<std::endl;
}
int testTemplateMethod()
{
    TrackFieldVenues* tm1 = new TrackFieldVenues("Track-and-field ground");
    SwimmingVenues* tm2 = new SwimmingVenues("Swimming pool");
    Wudokan* tm3 = new Wudokan("Wudokan");
    delay_time();
    cout<<"Olympic Games Competition Venues"<<endl;
    delay_time();

    cout<<tm1->getName()<<" holds "<<endl;
    tm1->templateMethod();
    cout<<endl;
    delay_time();

    cout<<tm2->getName()<<" holds ";
    tm2->templateMethod();
    cout<<endl;
    delay_time();

    cout<<tm3->getName()<<" holds ";
    tm3->templateMethod();
    cout<<endl;
    delay_time();
    delete tm1,tm2,tm3;
    return 0;
}

