//
// Created by xzb23 on 2021/10/23.
//
#include<iostream>
#include "Adaptor.h"
using namespace std;
void testAdaptor()
{
    cout<<"To solve the problem of language communication, "<<endl
    <<"Olympic organizers have sent volunteer translators to the national teams."<<endl;
    ForeignLanguage* japanese=new ForeignLanguage("Japan","Japanese");
    ForeignLanguage* german=new ForeignLanguage("German","German");
    ForeignLanguage* french=new ForeignLanguage("France","French");

    Volunteer1* v1 = new VolunteerTranslator(japanese);
    Volunteer1* v2 = new VolunteerTranslator(german);
    Volunteer1* v3 = new VolunteerTranslator(german);

    cout<<"The translator assigned to the Japanese team ";
    v1->request();cout<<endl;

    cout<<"The translator assigned to the German team ";
    v2->request();cout<<endl;

    cout<<"The translator assigned to the French team ";
    v3->request();;cout<<endl;


    delete v2;
    delete v1;
}


