#pragma once
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

class Props
{
private:
    string propsName;
public:
    ~Props() {}
    Props(string name) : propsName(name) {}

    string getPropsName() { return propsName; }
    virtual void display() = 0;
};

class Timer : public Props
{
public:
    Timer(string name) : Props(name) {}
    ~Timer() {}

    virtual void display() {
        cout << "Timer" << endl;
    }
};

class Table : public Props
{
public:
    Table(string name) : Props(name) {}
    ~Table() {}

    virtual void display() {
        cout << "Table" << endl;
    }
};

//��������ֻ��һ��ƹ���򹤳����������������Ŀ
 //���˱���
class GameProduct
{
private:
    string contestName;
    string startTime;
    string contestSite;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
    //����״̬������0��ʾδ��ʼ��1��ʾ���ڽ��У�2��ʾ������ͣ��3��ʾ��������
    int contestState;
public:
    GameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        contestName(cN), startTime(sT), contestSite(cS), sportsmanName(sName), sportsmanNation(sNation), contestState(cState) {}
    const string getcontestName() {
        return contestName;
    }
    const string getstartTime() {
        return startTime;
    }
    const string getcontestSite() {
        return contestSite;
    }
    const vector<string> getsportsmanName() {
        return sportsmanName;
    }
    const vector<string> getsportsmanNation() {
        return sportsmanNation;
    }
    const int getcontestState() {
        return contestState;
    };
    void setContestState(int state) {
        contestState = state;
    }
    //�ܲ����麯��
    //��ȡ��Ϣ����
    virtual const double getelapsedTime() { return 0; }
    virtual const double getdistance() { return 0; }
    virtual const vector<double> getdistanceTravelled() { vector<double>null; return null; }
    virtual const vector<double> getscore() { vector<double>null; return null; }
    //���ú���
    virtual void setelapsedTime(double para){}
    virtual void setdistanceTravelled(vector<double> para){}
    virtual void setscore(vector<double> para){}

    //ƹ������麯��
    virtual int getScore1() { return 0; }
    virtual int getScore2() { return 0; }
        
    //���ú���
    virtual void setScore(int i) {}
};

//�ܲ�����
class RunningGameProduct : public GameProduct
{
private:
    double elapsedTime;
    //�������ܣ���ʼ��Ϊ100
    double distance;
    //�˶�Ա�������״̬��Ԫ�����������˶�Ա��������ʼ��Ϊ[0,...,0]
    vector<bool> sportsmanState;
    //��ʾ�˶�Ա�������ľ��룬Ԫ�����������˶�Ա��������ʼ��Ϊ[0,...,0]
    vector<double> distanceTravelled;
    //��ʾ�˶�Ա�����ɼ�
    vector<double> score;
    Timer* timer;
public:
    ~RunningGameProduct() {}
    RunningGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        timer = new Timer("timer1");
        elapsedTime = 0;
        distance = 100;
        for (int i = 0; i < sName.size(); ++i)sportsmanState.push_back(0), distanceTravelled.push_back(0), score.push_back(0);
    }
    //��ȡ��Ϣ����
    virtual const double getelapsedTime();
    virtual const double getdistance();
    virtual const vector<double> getdistanceTravelled();
    virtual const vector<double> getscore();
    //���ú���
    virtual void setelapsedTime(double para);
    virtual void setdistanceTravelled(vector<double> para);
    virtual void setscore(vector<double> para);

};

//ƹ�������
class TableTennisGameProduct : public GameProduct
{
private:
    int Score[2];
    Table* table;
public:
    ~TableTennisGameProduct() {};
    TableTennisGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        table = new Table("table1");
       Score[0] = Score[1] = 0;
    }
    virtual int getScore1() {
        return Score[0];
    }
    virtual int getScore2() {
        return Score[1];
    }
    //���ú���
    virtual void setScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++Score[i]; 
    }
};


//���󹤳�

class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) = 0;
};

//ƹ���򹤳����̳��Գ��󹤳�
class TableTennisFactory : public AbstractFactory
{
public:
    ~TableTennisFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new TableTennisGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};
//�ܲ��������̳��Գ��󹤳�
class RunningFactory :public AbstractFactory
{
public:
    ~RunningFactory() {}
    virtual GameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new RunningGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};

