#pragma once
//д��ͬ�ı������棬��Ҫ���ֲ�ͬ��װ��
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ContestComponent {
public:
    ContestComponent() {}
    virtual void Draw() {};
private:

};

//��������
class ContestWindow {
public:
    void SetContents(ContestComponent* contents)
    {
        contents->Draw();
    }
};


class BasicInfo :public ContestComponent {
public:
    BasicInfo(string cN, string sN, string cS, int cState, double eT, vector<string> sName, vector<string>sNation)
        : contestName(cN), startTime(sN), contestSite(cS), contestState(cState), elapsedTime(eT), sportsmanName(sName), sportsmanNation(sNation) {}
    virtual void Draw() {
        cout << contestName;
        if (contestState == 0) {
            cout << "δ��ʼ��\n";
        }
        if (contestState == 1) {
            cout << "���ڽ��У�\n";
        }
        else if (contestState == 2) {
            cout << "������ͣ�У�\n";
        }
        else if (contestState == 3) {
            cout << "�Ѿ�������\n";
        }
        cout << "��ʼʱ��Ϊ��" << startTime << endl;
        if (contestState)cout << "�����Ѿ����У�" << elapsedTime << endl;
        cout << "���������ڣ�" << contestSite << endl;
        cout << "��������Ϊ��\n";
        for (int i = 0; i < sportsmanName.size(); ++i) {
            cout << "���� " << sportsmanNation[i] << " �� " << sportsmanName[i] << "; ";
            if ((i + 1) % 3 == 0)cout << endl;
        }
        cout << endl;
    }
private:
    string contestName;
    string startTime;
    string contestSite;
    int contestState;//0��ʾδ��ʼ��1��ʾ���ڽ��У�2��ʾ�ڱ�����ͣ��3��ʾ��������
    double elapsedTime;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
};


class Decorator : public ContestComponent {
public:
    Decorator(ContestComponent* cc) :_component(cc) {}

    virtual void Draw() {
        _component->Draw();
    }
    // ...
private:
    ContestComponent* _component;
};


class ScoreComparison :public Decorator {
public:
    ScoreComparison(ContestComponent* cc, int SL, int SR, int sL, int sR) :Decorator(cc),
        ScoreLeft(SL), ScoreRight(SR),//��ȷ�
        scoreLeft(sL), scoreRight(sR) {}
    virtual void Draw() {
        Decorator::Draw();
        cout << "��ǰ�ȷ�Ϊ��" << scoreLeft << "(" << ScoreLeft << "):" << scoreRight << "(" << ScoreRight << ")" << endl;
    }
private:
    int ScoreLeft, ScoreRight,//��ȷ�
        scoreLeft, scoreRight;//С�ȷ�

};

class Rankings :public Decorator {
public:
    Rankings(ContestComponent* cc, vector<string>r) :Decorator(cc), _rankings(r) {}

    virtual void Draw() {
        Decorator::Draw();
        cout << "��ǰ������\n";
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

int testDecorator();