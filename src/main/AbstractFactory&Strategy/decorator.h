//写不同的比赛界面，需要出现不同的装饰
#include<iostream>
#include<vector>
#include<string>
#include<random>
#include "AbstractFactory.h"
using namespace std;

class ContestComponent;

//比赛窗口
class ContestWindow {
public:
    void SetContents(ContestComponent* contents);
};

class ContestComponent {
public:
    ContestComponent() {}
    virtual void Draw() {};
private:

};



class BasicInfo :public ContestComponent {
public:
    BasicInfo(GameProduct*_gp):GP(_gp){}
    virtual void Draw() {
        cout << GP->getcontestName();
        switch (GP->getcontestState()) {
        case 0:
            cout << " has not begun！\n";
            break;
        case 1:
            cout << " is in progress！\n";
            break;
        case 2:
            cout << " is suspended！\n";
            break;
        case 3:
            cout << " is over！\n";
            break;
        }
        cout << "Start time of the game：" << GP->getstartTime() << endl;
        cout << "Site：" << GP->getcontestSite() << endl;
        cout << "Sportsman list：\n";
        vector<string>sportsmanName = GP->getsportsmanName();
        vector<string>sportsmanNation = GP->getsportsmanNation();
        for (int i = 0; i < sportsmanName.size(); ++i) {
            cout <<  sportsmanName[i] << " from " << sportsmanNation[i] << "; ";
            if ((i + 1) % 3 == 0)cout << endl;
        }
        cout << endl;
    }
private:
    GameProduct* GP;
};




class Decorator : public ContestComponent {
public:
    Decorator(ContestComponent*);

    virtual void Draw() {
        _component->Draw();
    }
    // ...
private:
    ContestComponent* _component;
};
Decorator::Decorator(ContestComponent* cc) :_component(cc) {}



class ScoreComparison :public Decorator {
public:

    ScoreComparison(ContestComponent* cc,GameProduct* _gp) :Decorator(cc), GP(_gp) {};
    virtual void Draw() {
        Decorator::Draw();
        vector<string> name;
        name = GP->getsportsmanName();
        int Score1 = GP->getScore1();
        int Score2 = GP->getScore2();
        cout << "Score: " << name[0] << " " << Score1 << " : " << Score2 << " " << name[1] << endl;
    }
private:
    GameProduct* GP;


};
struct runningSportsman {
    string name;
    string nation;
    double distance;
    double velocity;
    bool operator<(runningSportsman& r) {
        return velocity > r.velocity;
    }
};
class Rankings :public Decorator {
public:
    Rankings(ContestComponent* cc, GameProduct* _gp) :Decorator(cc), GP(_gp) {
    }

    virtual void Draw() {
        Decorator::Draw();
        cout << "Current ranking：\n";

        vector<runningSportsman>sportsman;
        vector<string>name = GP->getsportsmanName();
        vector<string>nation = GP->getsportsmanNation();
        vector<double>Score = GP->getscore();
        vector<double>distance = GP->getdistanceTravelled();
        double time = GP->getelapsedTime();
        for (int i = 0; i < name.size(); ++i) {
            sportsman.push_back(runningSportsman{ name[i],nation[i],distance[i],(Score[i] < 1e-6 ? distance[i] / (time+1e-6) : Score[i]) });
        }
        sort(sportsman.begin(), sportsman.end());
        for (auto i : sportsman)
            cout << i.name << " from " << i.nation << " has covered " << i.distance << ", whose velocity is " << i.velocity << endl;
    }
private:
    GameProduct* GP;
};

void ContestWindow::SetContents(ContestComponent* contents) {
    contents->Draw();
}