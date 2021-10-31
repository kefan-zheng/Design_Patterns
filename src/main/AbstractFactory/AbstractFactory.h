
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;
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
    RunningGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState, int num) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        elapsedTime = 0;
        distance = 100;
        for (int i = 0; i < num; ++i)sportsmanState.push_back(0), distanceTravelled.push_back(0), score.push_back(0);
    }
    //��ȡ��Ϣ����
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
    ~TableTennisGameProduct() {};
    TableTennisGameProduct(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) :
        GameProduct(cN, sT, cS, sName, sNation, cState) {
        bigScore[0] = bigScore[1] = smallScore[0] = smallScore[1] = 0;
        location[0] = location[1] = false;
    }
    const int* getbigScore();
    const int* getsmallScore();
    const bool* getlocation();
    //���ú���
    void setbigScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++bigScore[i]; 
    }
    void setsmallScore(int i) { 
        if (i != 0 && i != 1) { return; }
        ++smallScore[i]; 
    }
    void flipLocation() {
        swap(location[0], location[1]);
    }
};


//���󹤳�
template<class T>
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
};

//ƹ���򹤳����̳��Գ��󹤳�
class TableTennisFactory : public AbstractFactory<TableTennisGameProduct>
{
public:
    ~TableTennisFactory() {}
    TableTennisGameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState) {
        return new TableTennisGameProduct(cN, sT, cS, sName, sNation, cState);
    }
};
//�ܲ��������̳��Գ��󹤳�
class RunningFactory {
public:
    ~RunningFactory() {}
    RunningGameProduct* Produce(string cN, string sT, string cS, vector<string>sName, vector<string>sNation, int cState,int num) {
        return new RunningGameProduct(cN, sT, cS, sName, sNation, cState, num);
    }
};
