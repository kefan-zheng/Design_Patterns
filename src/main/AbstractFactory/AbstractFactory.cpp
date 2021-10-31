#include "AbstractFactory.h"
//本例子中有一个比赛工厂，可以产生跑步和乒乓球比赛



const double RunningGameProduct::getelapsedTime()
{
    return this->elapsedTime;
}

const double RunningGameProduct::getdistance()
{
    return this->distance;
}

const vector<bool> RunningGameProduct::getsportsmanState()
{
    return this->sportsmanState;
}

const vector<double> RunningGameProduct::getdistanceTravelled()
{
    return this->distanceTravelled;
}

const vector<double> RunningGameProduct::getscore()
{
    return this->score;
}

void RunningGameProduct::setelapsedTime(double para)
{
    this->elapsedTime = para;
}

void RunningGameProduct::setsportsmanState(vector<bool> para)
{
    this->sportsmanState = para;
}

void RunningGameProduct::setdistanceTravelled(vector<double> para)
{
    this->distanceTravelled = para;
}

void RunningGameProduct::setscore(vector<double> para)
{
    this->score = para;
}


const int* TableTennisGameProduct::getbigScore()
{
    return this->bigScore;
}
const int* TableTennisGameProduct::getsmallScore()
{
    return this->smallScore;
}

const bool* TableTennisGameProduct::getlocation()
{
    return this->location;
}







