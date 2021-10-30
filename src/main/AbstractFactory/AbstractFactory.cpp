#include "AbstractFactory.h"
//本例子中有一个比赛工厂，可以产生跑步和乒乓球比赛

const string RunningGameProduct::getcontestName()
{
    return this->contestName;
}

const string RunningGameProduct::getstartTime()
{
    return this->startTime;
}

const string RunningGameProduct::getcontestSite()
{
    return this->contestSite;
}

const vector<string> RunningGameProduct::getsportsmanName()
{
    return this->sportsmanName;
}

const vector<string> RunningGameProduct::getsportsmanNation()
{
    return this->sportsmanNation;
}

const int RunningGameProduct::getcontestState()
{
    return this->contestState;
}

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

void RunningGameProduct::setcontestState(int para)
{
    this->contestState = para;
}

//乒乓球
const string TableTennisGameProduct::getcontestName()
{
    return this->contestName;
}

const string TableTennisGameProduct::getstartTime()
{
    return this->startTime;
}

const string TableTennisGameProduct::getcontestSite()
{
    return this->contestSite;
}

const vector<string> TableTennisGameProduct::getsportsmanName()
{
    return this->sportsmanName;
}

const vector<string> TableTennisGameProduct::getsportsmanNation()
{
    return this->sportsmanNation;
}

const int TableTennisGameProduct::getcontestState()
{
    return this->contestState;
}

const int* TableTennisGameProduct::getbigScore()
{
    return this->bigScore;
}
const int* TableTennisGameProduct::getsmallScore()
{
    return this->smallScore;
}

const bool TableTennisGameProduct::getlocation()
{
    return this->location;
}

void TableTennisGameProduct::setbigScore(int para)
{
    this->bigScore[2] = para;
}

void TableTennisGameProduct::setsmallScore(int para)
{
    this->smallScore[2] = para;
}

void TableTennisGameProduct::setlocation(bool para)
{
    this->location[2] = para;
}

void TableTennisGameProduct::setcontestState(int para)
{
    this->contestState = para;
}

//比赛工厂
RunningGameProduct* GameFactory::createRunningGameProduct()
{
    return new RunningGameProduct();
}

TableTennisGameProduct* GameFactory::createTableTennisGameProduct()
{
    return new TableTennisGameProduct();
}

int testAbstractFactory()
{
    GameFactory* factory = new GameFactory();

    //创建一个跑步比赛和一个乒乓球比赛
    RunningGameProduct* game1 = factory->createRunningGameProduct();
    TableTennisGameProduct* game2 = factory->createTableTennisGameProduct();

    game1->setelapsedTime(100);
    game2->setcontestState(3);

    cout << game1->getelapsedTime() << endl;
    cout << game2->getcontestState() << endl;

    delete game1;
    delete game2;

    delete factory;

    cout << endl;

    return 0;
}