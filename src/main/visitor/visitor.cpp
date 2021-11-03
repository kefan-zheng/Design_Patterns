#include <iostream>
using namespace std;

#include "visitor.h"

void FootBallData::SetData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    RedPoint = REDPOINT;
    BluePoint = BLUEPOINT;
    RedFoulTimes = REDFOULTIMES;
    BlueFoulTimes = BLUEFOULTIMES;
    Countary = COUNTARY;
}

FootBall::FootBall(const std::string& name) : _name(name) {};
int FootBall::RedPoint() { return _footballdata.RedPoint; };
int FootBall::BluePoint() { return _footballdata.BluePoint; };
int FootBall::RedFoulTimes() { return _footballdata.RedFoulTimes; };
int FootBall::BlueFoulTimes() { return _footballdata.BlueFoulTimes; };
string FootBall::Countary() { return _footballdata.Countary; }

Final::Final(const std::string& name) : FootBall(name) {};
void Final::SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    _footballdata.SetData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int Final::RedPoint() { return _footballdata.RedPoint; };
int Final::BluePoint() { return _footballdata.BluePoint; };
int Final::RedFoulTimes() { return _footballdata.RedFoulTimes; };
int Final::BlueFoulTimes() { return _footballdata.BlueFoulTimes; };
string Final::Countary() { return _footballdata.Countary; }

SemiFinal::SemiFinal(const std::string& name) : FootBall(name) {};
void SemiFinal::SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    _footballdata.SetData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int SemiFinal::RedPoint() { return _footballdata.RedPoint; };
int SemiFinal::BluePoint() { return _footballdata.BluePoint; };
int SemiFinal::RedFoulTimes() { return _footballdata.RedFoulTimes; };
int SemiFinal::BlueFoulTimes() { return _footballdata.BlueFoulTimes; };
string SemiFinal::Countary() { return _footballdata.Countary; }

GroupGame::GroupGame(const std::string& name) : FootBall(name) {};
void GroupGame::SetFootBallData(int REDPOINT, int BLUEPOINT, int REDFOULTIMES, int BLUEFOULTIMES, string COUNTARY)
{
    _footballdata.SetData(REDPOINT, BLUEPOINT, REDFOULTIMES, BLUEFOULTIMES, COUNTARY);
}
int GroupGame::RedPoint() { return _footballdata.RedPoint; };
int GroupGame::BluePoint() { return _footballdata.BluePoint; };
int GroupGame::RedFoulTimes() { return _footballdata.RedFoulTimes; };
int GroupGame::BlueFoulTimes() { return _footballdata.BlueFoulTimes; };
string GroupGame::Countary() { return _footballdata.Countary; }

int& VisitorFootBallRedPoint::GetRedPoint() { return _total; }
void VisitorFootBallRedPoint::Visit(Final* final){
    _total = final->RedPoint();
}
void VisitorFootBallRedPoint::Visit(SemiFinal* semifinal){
    _total = semifinal->RedPoint();
}
void VisitorFootBallRedPoint::Visit(GroupGame* groupgame){
    _total = groupgame->RedPoint();
}

int& VisitorFootBallBluePoint::GetBluePoint() { return _total; }
void VisitorFootBallBluePoint::Visit(Final* final){
    _total = final->BluePoint();
}
void VisitorFootBallBluePoint::Visit(SemiFinal* semifinal){
    _total = semifinal->BluePoint();
}
void VisitorFootBallBluePoint::Visit(GroupGame* groupgame){
    _total = groupgame->BluePoint();
}

int& VisitorFootBallRedFoulTimes::GetRedFoulTimes() { return _total; }
void VisitorFootBallRedFoulTimes::Visit(Final* final){
    _total = final->RedFoulTimes();
}
void VisitorFootBallRedFoulTimes::Visit(SemiFinal* semifinal){
    _total = semifinal->RedFoulTimes();
}
void VisitorFootBallRedFoulTimes::Visit(GroupGame* groupgame){
    _total = groupgame->RedFoulTimes();
}

int& VisitorFootBallBlueFoulTimes::GetBlueFoulTimes() { return _total; }
void VisitorFootBallBlueFoulTimes::Visit(Final* final){
    _total = final->BlueFoulTimes();
}
void VisitorFootBallBlueFoulTimes::Visit(SemiFinal* semifinal){
    _total = semifinal->BlueFoulTimes();
}
void VisitorFootBallBlueFoulTimes::Visit(GroupGame* groupgame){
    _total = groupgame->BlueFoulTimes();
}

string& VisitorFootBallCountary::GetCountary() { return _total; }
void VisitorFootBallCountary::Visit(Final* final){
    _total = final->Countary();
}
void VisitorFootBallCountary::Visit(SemiFinal* semifinal){
    _total = semifinal->Countary();
}
void VisitorFootBallCountary::Visit(GroupGame* groupgame){
    _total = groupgame->Countary();
}

int main()
{
    Final* final = new Final("Final");
    SemiFinal* semifinal1 = new SemiFinal("SemiFinal1");
    SemiFinal* semifinal2 = new SemiFinal("SemiFinal2");
    GroupGame* groupgame = new GroupGame("GroupGame");
    final->SetFootBallData(3, 1, 2, 2, "SpainVSGermany");
    semifinal1->SetFootBallData(2, 4, 3, 2, "BrazilVSSpain");
    semifinal2->SetFootBallData(2, 0, 4, 1, "GermanyVSArgentina");
    groupgame->SetFootBallData(1, 2, 5, 3, "EnglandVSFrance");

    VisitorFootBallRedPoint visitorFootBallRedPoint;
    VisitorFootBallBluePoint visitorFootBallBluePoint;
    VisitorFootBallRedFoulTimes visitorFootBallRedFoulTimes;
    VisitorFootBallBlueFoulTimes visitorFootBallBlueFoulTimes;
    VisitorFootBallCountary visitorFootBallCountary;

    visitorFootBallRedPoint.Visit(groupgame);
    visitorFootBallBluePoint.Visit(groupgame);
    visitorFootBallRedFoulTimes.Visit(groupgame);
    visitorFootBallBlueFoulTimes.Visit(groupgame);
    visitorFootBallCountary.Visit(groupgame);  
    cout << "In the opener, the two sides are " << visitorFootBallCountary.GetCountary() << endl;
    cout << "The score is " << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "The number of fouls on both sides is " << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.Visit(semifinal1);
    visitorFootBallBluePoint.Visit(semifinal1);
    visitorFootBallRedFoulTimes.Visit(semifinal1);
    visitorFootBallBlueFoulTimes.Visit(semifinal1);
    visitorFootBallCountary.Visit(semifinal1);
    cout << "In the first semi-final matchup, the two sides are " << visitorFootBallCountary.GetCountary() << endl;
    cout << "The score is " << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "The number of fouls on both sides is " << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.Visit(semifinal2);
    visitorFootBallBluePoint.Visit(semifinal2);
    visitorFootBallRedFoulTimes.Visit(semifinal2);
    visitorFootBallBlueFoulTimes.Visit(semifinal2);
    visitorFootBallCountary.Visit(semifinal2);
    cout << "In the second semi-final matchup, the two sides are " << visitorFootBallCountary.GetCountary() << endl;
    cout << "The score is " << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "The number of fouls on both sides is " << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.Visit(final);
    visitorFootBallBluePoint.Visit(final);
    visitorFootBallRedFoulTimes.Visit(final);
    visitorFootBallBlueFoulTimes.Visit(final);
    visitorFootBallCountary.Visit(final);
    cout << "In the final matchup, the two sides are " << visitorFootBallCountary.GetCountary() << endl;
    cout << "The score is " << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "The number of fouls on both sides is " << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    system("pause");
    return 0;
}