#include "Facade.h"

vector<HotelInfo*> Hotel::hotelList;

void Hospital::AccountingDetection()
{
    cout << "The sample is undergoing nucleic acid testing!" << endl;
};

HotelInfo::HotelInfo(string h, string l) :
    hotelName(h), location(l) {}

// 采用多例模式创建的酒店
void Hotel::CheckIn()
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
void Hotel::Sampling()
{
    cout << "Nucleic acid sampling has been carried out and the sample will be sent to the hospital for testing." << endl;
}


void Transportation::GetVehicle()
{
    cout << "A special bus has been arranged to serve them." << endl;
}

void Training::TrainingLocation()
{
    cout << "Exclusive training venues have been arranged for special training." << endl;
}

void Facade::Detection()
{
    _hotel->Sampling();
    _hospital->AccountingDetection();
}

void Facade::AppointTraining()
{
    _training->TrainingLocation();
    _transportation->GetVehicle();
}

void Facade::CheckIn()
{
    _transportation->GetVehicle();
    _hotel->CheckIn();
}

void testFacade()
{
    Facade _facade;
    cout << "Players from China are Coming to the Olympic Villiage.\n";
    _facade.CheckIn();
    _facade.Detection();
    _facade.AppointTraining();

    cout << "\nPlayers from Japan are Coming to the Olympic Villiage.\n";
    _facade.CheckIn();
    _facade.Detection();
    _facade.AppointTraining();

    cout << "\nPlayers from other countrys are coming to to Olympic Village...\n";
    //system("pause");
}