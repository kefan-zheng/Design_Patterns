#include "Facade.h"
vector<HotelInfo*> Hotel::hotelList;

int testFacade()
{
    Facade _facade;
    _facade.CheckIn();
    _facade.Detection();
    _facade.AppointTraining();
    
    cout << endl;

    return 0;
}