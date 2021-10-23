#include"Flyweight.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
	In this design pattern,we can use the track-and-field ground as flyweight.
*/
Flyweight::Flyweight() {}
Flyweight::~Flyweight() {}
ConcreteCompetition::ConcreteCompetition(string item)
{
	this->item = item;
}
void ConcreteCompetition::Execute(int extrinsicState)
{
	cout << "Competition " << extrinsicState << ": " << this->item<<endl;
}
ConcreteCompetition::~ConcreteCompetition() {}
FlyweightFactory::FlyweightFactory()
{
	Flyweights.insert(make_pair("100m race", new ConcreteCompetition("100m race")));
	Flyweights.insert(make_pair("200m race", new ConcreteCompetition("200m race")));
	Flyweights.insert(make_pair("400m race", new ConcreteCompetition("400m race")));
	Flyweights.insert(make_pair("800m race", new ConcreteCompetition("800m race")));
	Flyweights.insert(make_pair("1500m race", new ConcreteCompetition("1500m race")));
	Flyweights.insert(make_pair("5000m race", new ConcreteCompetition("5000m race")));
	Flyweights.insert(make_pair("110m hurdle race", new ConcreteCompetition("110m hurdle race ")));
	Flyweights.insert(make_pair("400m hurdle race", new ConcreteCompetition("400m hurdle race ")));
	Flyweights.insert(make_pair("4x100m relay", new ConcreteCompetition("4x100m relay ")));
}
ConcreteCompetition* FlyweightFactory::GetFlyweight(string key)
{
	if (!Flyweights.count(key))
	{
		Flyweights.insert(make_pair(key, new ConcreteCompetition(key)));
		cout << "Add Competition :" << key << endl;
	}
	return (ConcreteCompetition*)Flyweights[key];
}
FlyweightFactory::~FlyweightFactory() {}
int main()
{
	FlyweightFactory* factory = new FlyweightFactory();
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
	items->Execute(++i);
	items = factory->GetFlyweight("110m hurdle race");
	items->Execute(++i);
	items = factory->GetFlyweight("400m hurdle race");
	items->Execute(++i);
	items = factory->GetFlyweight("4x100m relay");
	items->Execute(++i);
	items = factory->GetFlyweight("8x100m relay");
	items->Execute(++i);
	return 0;
}