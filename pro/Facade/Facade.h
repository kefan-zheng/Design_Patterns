#pragma once
#ifndef _FACADE_H_
#define _FACADE_H_
#include <iostream>
#include <vector>
using namespace std;

//ҽԺ��
class Hospital
{
public:
    Hospital() {};
    ~Hospital() {};
    void AccountingDetection()
    {
        cout << "��Ʒ���ڽ��к����⣡" << endl;
    };
};

struct HotelInfo {
    string hotelName;
    string location;
    HotelInfo(string h, string l) :
        hotelName(h), location(l) {}
};

//�Ƶ���,�����˶���ģʽ
class Hotel
{
private:
    const int hotelNum = 4;//4���ɹ�ѡ��ľƵ�
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
        cout << "�ѽ��к����������Ʒ������ҽԺ��⡣" << endl;
    }
};


//��ͨ��
class Transportation
{
public:
    Transportation();
    ~Transportation();
    void GetVehicle()
    {
        cout << "�Ѱ���ר��Ϊ�����з���" << endl;
    }
};

//ѵ��������
class Training
{
public:
    Training();
    ~Training();
    void TrainingLocation()
    {
        cout << "�Ѱ���ר����ѵ������������ѵ����" << endl;
    }
};

//Facade��
class Facade
{
public:
    Facade() {};
    ~Facade() {};
    //������
    void Detection()
    {
        _hotel->Sampling();
        _hospital->AccountingDetection();
    }
    //ԤԼѵ��
    void AppointTraining()
    {
        _training->TrainingLocation();
        _transportation->GetVehicle();
    }
    //������פ
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