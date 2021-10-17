//д��ͬ�ı������棬��Ҫ���ֲ�ͬ��װ��
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ContestComponent;

//��������
class ContestWindow {
public:
    void SetContents(ContestComponent* contents);
};

class ContestComponent {
public:
    ContestComponent(){}
    virtual void Draw() {};
private:

};



class BasicInfo :public ContestComponent {
public:
    BasicInfo(string, string, string, int, double, vector<string>,vector<string>);
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
            if ((i+1) % 3 == 0 )cout << endl;
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

BasicInfo::BasicInfo(string cN, string sN, string cS, int cState, double eT, vector<string> sName,vector<string>sNation)
    : contestName(cN), startTime(sN), contestSite(cS), contestState(cState), elapsedTime(eT), sportsmanName(sName),sportsmanNation(sNation) {}


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
    Rankings(ContestComponent*cc,vector<string>r):Decorator(cc),_rankings(r){}
    
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

void ContestWindow::SetContents(ContestComponent* contents) {
    contents->Draw();
}
int main() {
    ContestWindow* window=new ContestWindow;
    vector<string>sName;
    sName.push_back( "����");
    sName.push_back("����");
    vector<string>sNation;
    sNation.push_back("�й�");
    sNation.push_back("�й�");
    BasicInfo* bs=new BasicInfo("����ƹ���򵥴�-������", "2021-10-10 08:00", "ƹ������", 0, 0, sName, sNation);
    window->SetContents(new ScoreComparison(bs, 0, 0, 0, 0));
    cout << endl;
    vector<string>sName2;
    vector<string>sNation2;
    sName2.push_back("Ngoni Makusha");
    sName2.push_back("Fabrice Dabla");
    sName2.push_back("Yeykell Romero");
    sName2.push_back("Hassan Saaid");
    sName2.push_back("Shaun Gill");
    sName2.push_back("Pen Sokong");
    sName2.push_back("Sha Mahmood Noor Zahi");
    sName2.push_back("Lataisi Mwea");
    sName2.push_back("Nathan Crumpton");
    sNation2.push_back("Zimbabwe");
    sNation2.push_back("Togo");
    sNation2.push_back("Nicaragua");
    sNation2.push_back("Maldives");
    sNation2.push_back("Belize");
    sNation2.push_back("Cambodia");
    sNation2.push_back("Afghanistan");
    sNation2.push_back("Kiribati");
    sNation2.push_back("American Samoa");
    BasicInfo* bs2 = new BasicInfo("100������-����", "2021-10-11 14:00", "�ﾶ��", 0, 0, sName2, sNation2);
    ContestWindow* window2 = new ContestWindow;
    vector<string>rankings;
    rankings.push_back("Fabrice Dabla");
    rankings.push_back("Yeykell Romero");
    rankings.push_back("Hassan Saaid");
    rankings.push_back("Pen Sokong");
    rankings.push_back("Ngoni Makusha");
    rankings.push_back("Sha Mahmood Noor Zahi");
    rankings.push_back("Lataisi Mwea");
    rankings.push_back("Nathan Crumpton");
    rankings.push_back("Shaun Gill");
    
    window2->SetContents(new Rankings(bs2, rankings));
    return 0;
}