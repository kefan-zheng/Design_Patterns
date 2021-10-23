#include<iostream>
#include<string>
#include "mvc.h"
using namespace std;

//Model模型类Student
void testMVC()
{
    Player model;
    model.setName("Robert");
    model.setNation("Canada");
    PlayerView view;
    PlayerController controller(model, view);

    controller.updateView();
    controller.setPlayerName("John");
    controller.updateView();
}
int main()
{
    testMVC();
    return 0;
}