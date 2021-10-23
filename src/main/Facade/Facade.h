#ifndef _FACADE_H_
#define _FACADE_H_
#include <iostream>
using namespace std;

//医院类
class Hospital
{
public:
    Hospital(){};
    ~Hospital(){};
    void AccountingDetection()
    {
        cout<<"样品正在进行核酸检测！"<<endl;
    };
};

//酒店类
class Hotel
{
public:
    Hotel(){};
    ~Hotel(){};
    void CheckIn()
    {
        cout<<"已成功办理入驻！"<<endl;
    }
    void Sampling()
    {
        cout<<"已进行核酸采样，样品将送往医院检测。"<<endl;
    }
};

//交通类
class Transportation
{
public:
    Transportation();
    ~Transportation();
    void GetVehicle()
    {
        cout<<"已安排专车为您出行服务。"<<endl;
    }
};

//训练场馆类
class Training
{
public:
    Training();
    ~Training();
    void TrainingLocation()
    {
        cout<<"已安排专属的训练场所供特殊训练。"<<endl;
    }
};

//Facade类
class Facade
{
public:
    Facade(){};
    ~Facade(){};
    //核酸检测
    void Detection()
    {
        _hotel->Sampling();
        _hospital->AccountingDetection();
    }
    //预约训练
    void AppointTraining()
    {
        _training->TrainingLocation();
        _transportation->GetVehicle();
    }
    //办理入驻
    void CheckIn()
    {
        _transportation->GetVehicle();
        _hotel->CheckIn();
    }
private:
    Hospital* _hospital;
    Hotel* _hotel;
    Transportation* _transportation;
    Training* _training;
};




#endif