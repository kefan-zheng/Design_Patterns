#include<iostream>
#include<string>
#include "Mvc.h"
using namespace std;

//Model模型类Student
int testMVC()
{
    Player model;
    model.setName("Robert");
    model.setNation("Canada");
    PlayerView view;
    PlayerController controller(model, view);

    controller.updateView();
    controller.setPlayerName("John");
    controller.updateView();

    cout << endl;

    return 0;
}
