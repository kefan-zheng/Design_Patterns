//写不同的比赛界面，需要出现不同的装饰
#include<iostream>
#include<vector>
#include<string>
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
    BasicInfo(string, string, string, int, double, vector<string>, vector<string>);
    virtual void Draw() {
        cout << contestName;
        if (contestState == 0) {
            cout << "未开始！\n";
        }
        if (contestState == 1) {
            cout << "正在进行！\n";
        }
        else if (contestState == 2) {
            cout << "处于暂停中！\n";
        }
        else if (contestState == 3) {
            cout << "已经结束！\n";
        }
        cout << "开始时间为：" << startTime << endl;
        if (contestState)cout << "比赛已经进行：" << elapsedTime << endl;
        cout << "比赛场所在：" << contestSite << endl;
        cout << "参赛名单为：\n";
        for (int i = 0; i < sportsmanName.size(); ++i) {
            cout << "来自 " << sportsmanNation[i] << " 的 " << sportsmanName[i] << "; ";
            if ((i + 1) % 3 == 0)cout << endl;
        }
        cout << endl;
    }
private:
    string contestName;
    string startTime;
    string contestSite;
    int contestState;//0表示未开始，1表示正在进行，2表示在比赛暂停，3表示比赛结束
    double elapsedTime;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
};

BasicInfo::BasicInfo(string cN, string sN, string cS, int cState, double eT, vector<string> sName, vector<string>sNation)
    : contestName(cN), startTime(sN), contestSite(cS), contestState(cState), elapsedTime(eT), sportsmanName(sName), sportsmanNation(sNation) {}


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
    ScoreComparison(ContestComponent* cc, int SL, int SR, int sL, int sR) :Decorator(cc),
        ScoreLeft(SL), ScoreRight(SR),//大比分
        scoreLeft(sL), scoreRight(sR) {}
    virtual void Draw() {
        Decorator::Draw();
        cout << "当前比分为：" << scoreLeft << "(" << ScoreLeft << "):" << scoreRight << "(" << ScoreRight << ")" << endl;
    }
private:
    int ScoreLeft, ScoreRight,//大比分
        scoreLeft, scoreRight;//小比分

};
class Rankings :public Decorator {
public:
    Rankings(ContestComponent* cc, vector<string>r) :Decorator(cc), _rankings(r) {}

    virtual void Draw() {
        Decorator::Draw();
        cout << "当前排名：\n";
        for (auto i : _rankings) {
            cout << i << endl;
        }
    }
    void reviseRanking(vector<string>v) {
        _rankings.clear();
        _rankings = v;
    }
private:
    vector<string>_rankings;
};

void ContestWindow::SetContents(ContestComponent* contents) {
    contents->Draw();
}