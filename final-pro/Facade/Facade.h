#ifndef _FACADE_H_
#define _FACADE_H_
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//Hospital
class Hospital
{
public:
    Hospital() {};
    ~Hospital() {};
    void AccountingDetection();
};

struct HotelInfo {
    string hotelName;
    string location;
    HotelInfo(string h, string l);
};

//Hotel, multion is adopted
class Hotel
{
private:
    const int hotelNum = 4;//4 hotels to choose from
    static vector<HotelInfo*> hotelList;
    
public:
    Hotel() {};
    ~Hotel() {};
    void CheckIn();
    void Sampling();
};


//Transportation
class Transportation
{
public:
    Transportation() {};
    ~Transportation() {};
    void GetVehicle();
};

//Training
class Training
{
public:
    Training() {};
    ~Training() {};
    void TrainingLocation();
};

//Facade
class Facade
{
public:
    Facade() {};
    ~Facade() {};
    //nucleic acid test
    void Detection();
    //Appointment training
    void AppointTraining();
    //Handle settlement
    void CheckIn();
private:
    Hospital* _hospital;
    Hotel* _hotel;
    Transportation* _transportation;
    Training* _training;
};


void testFacade();

#endif