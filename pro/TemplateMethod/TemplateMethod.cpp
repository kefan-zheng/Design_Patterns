#include "iostream"
#include <Windows.h>
#include "TemplateMethod.h"

void delay_time()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<'.';
        Sleep(200);
    }
    std::cout<<std::endl;
}

int testTemplateMethod()
{
    Venues* tm1 = new SwimmingVenues("Swimming pool");
    Venues* tm2 = new TrackFieldVenues("Track-and-field ground");
    delay_time();
    cout<<"Olympic Games Competition Venues"<<endl;
    delay_time();

    cout<<tm1->getName()<<" holds ";
    tm1->templateMethod();
    cout<<endl;
    delay_time();

    cout<<tm2->getName()<<" holds ";
    tm2->templateMethod();
    cout<<endl;
    delay_time();

    delete tm1,tm2;

    cout << endl;

    return 0;
}
