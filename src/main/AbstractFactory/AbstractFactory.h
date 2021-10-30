#pragma once
#include<vector>
#include <iostream>

using namespace std;
//��������ֻ��һ��ƹ���򹤳����������������Ŀ
 //���˱���
class GameProduct
{
public:
    string contestName;
    string startTime;
    string contestSite;
    vector<string>sportsmanName;
    vector<string>sportsmanNation;
    //����״̬������0��ʾδ��ʼ��1��ʾ���ڽ��У�2��ʾ������ͣ��3��ʾ��������
    int contestState;
    //��������
    virtual ~GameProduct() {}
    //���麯��
    virtual const string getcontestName() = 0;
    virtual const string getstartTime() = 0;
    virtual const string getcontestSite() = 0;
    virtual const vector<string> getsportsmanName() = 0;
    virtual const vector<string> getsportsmanNation() = 0;
    virtual const int getcontestState() = 0;
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
public:
    ~RunningGameProduct() {}
    //���麯����ʵ��
    const string getcontestName();
    const string getstartTime();
    const string getcontestSite();
    const vector<string> getsportsmanName();
    const vector<string> getsportsmanNation();
    const int getcontestState();

    const double getelapsedTime();
    const double getdistance();
    const vector<bool> getsportsmanState();
    const vector<double> getdistanceTravelled();
    const vector<double> getscore();

    //���ú���
    void setelapsedTime(double para);
    void setsportsmanState(vector<bool> para);
    void setdistanceTravelled(vector<double> para);
    void setscore(vector<double> para);
    void setcontestState(int para);
};

//ƹ�������
class TableTennisGameProduct : public GameProduct
{
private:
    //��ȷ�
    int bigScore[2];
    //С�ȷ�
    int smallScore[2];
    //�˶�Ա���������λ�ã�false����վ����ߣ�true����վ���ұ�
    bool location[2];
public:
    ~TableTennisGameProduct() {}
    //���麯����ʵ��
    const string getcontestName();
    const string getstartTime();
    const string getcontestSite();
    const vector<string> getsportsmanName();
    const vector<string> getsportsmanNation();
    const int getcontestState();

    const int* getbigScore();
    const int* getsmallScore();
    const bool getlocation();
    //���ú���
    void setbigScore(int para);
    void setsmallScore(int para);
    void setlocation(bool para);
    void setcontestState(int para);
};


//���󹤳�
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    //������Ʒ
    virtual RunningGameProduct* createRunningGameProduct() = 0;
    virtual TableTennisGameProduct* createTableTennisGameProduct() = 0;
};

//ƹ���򹤳����̳��Գ��󹤳�
class GameFactory : public AbstractFactory
{
public:
    ~GameFactory() {}

    RunningGameProduct* createRunningGameProduct();

    TableTennisGameProduct* createTableTennisGameProduct();
};

int testAbstractFactory();