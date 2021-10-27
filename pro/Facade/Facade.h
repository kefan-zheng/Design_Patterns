#pragma once
#ifndef _FACADE_H_
#define _FACADE_H_
#include <iostream>
#include <vector>
using namespace std;

//医院类
class Hospital
{
public:
    Hospital() {};
    ~Hospital() {};
    void AccountingDetection()
    {
        cout << "样品正在进行核酸检测！" << endl;
    };
};

struct HotelInfo {
    string hotelName;
    string location;
    HotelInfo(string h, string l) :
        hotelName(h), location(l) {}
};

//酒店类,采用了多例模式
class Hotel
{
private:
    const int hotelNum = 4;//4个可供选择的酒店
    static vector<HotelInfo*> hotelList;
    
public:
    Hotel() {};
    ~Hotel() {};
    void CheckIn()
    {
        if (hotelList.size() == 0) {
            hotelList.push_back(new HotelInfo("Great Hotel", "Heping Street"));
            hotelList.push_back(new HotelInfo("Yang Hotel", "Success Street"));
            hotelList.push_back(new HotelInfo("Cao Hotel", "Great Street"));
            hotelList.push_back(new HotelInfo("Zheng Hotel", "Sisyphus Street"));
        }
        srand((unsigned)time(NULL));
        int randNum = rand() % 4;
        HotelInfo* info = hotelList[randNum];
        //HotelInfo* info = new HotelInfo("Great Hotel", "Heping Street");
        cout << "Check in " << info->hotelName << "(location: " << info->location <<") successfully" << endl;
    }
    void Sampling()
    {
        cout << "已进行核酸采样，样品将送往医院检测。" << endl;
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
        cout << "已安排专车为您出行服务。" << endl;
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
        cout << "已安排专属的训练场所供特殊训练。" << endl;
    }
};

//Facade类
class Facade
{
public:
    Facade() {};
    ~Facade() {};
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

int testFacade();


#endif