#include <iostream>
using namespace std;

#include "visitor.h"

int main()
{
    Final* final = new Final("Final");
    SemiFinal1* semifinal1 = new SemiFinal1("SemiFinal1");
    SemiFinal2* semifinal2 = new SemiFinal2("SemiFinal2");
    VisitorFootBallRedPoint visitorFootBallRedPoint;
    VisitorFootBallBluePoint visitorFootBallBluePoint;
    VisitorFootBallRedFoulTimes visitorFootBallRedFoulTimes;
    VisitorFootBallBlueFoulTimes visitorFootBallBlueFoulTimes;
    VisitorFootBallCountary visitorFootBallCountary;
    visitorFootBallRedPoint.Visit(semifinal1);
    visitorFootBallBluePoint.Visit(semifinal1);
    visitorFootBallRedFoulTimes.Visit(semifinal1);
    visitorFootBallBlueFoulTimes.Visit(semifinal1);
    visitorFootBallCountary.Visit(semifinal1);
    cout << "��һ�����������˫��Ϊ��" << visitorFootBallCountary.GetCountary() << endl;
    cout << "�ȷ����Ϊ��" << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "˫��������Ϊ��" << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.Visit(semifinal2);
    visitorFootBallBluePoint.Visit(semifinal2);
    visitorFootBallRedFoulTimes.Visit(semifinal2);
    visitorFootBallBlueFoulTimes.Visit(semifinal2);
    visitorFootBallCountary.Visit(semifinal2);
    cout << "�ڶ������������˫��Ϊ��" << visitorFootBallCountary.GetCountary() << endl;
    cout << "�ȷ����Ϊ��" << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "˫��������Ϊ��" << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    cout << endl;

    visitorFootBallRedPoint.Visit(final);
    visitorFootBallBluePoint.Visit(final);
    visitorFootBallRedFoulTimes.Visit(final);
    visitorFootBallBlueFoulTimes.Visit(final);
    visitorFootBallCountary.Visit(final);
    cout << "��������˫��Ϊ��" << visitorFootBallCountary.GetCountary() << endl;
    cout << "�ȷ����Ϊ��" << visitorFootBallRedPoint.GetRedPoint() << ":" << visitorFootBallBluePoint.GetBluePoint() << endl;
    cout << "˫��������Ϊ��" << visitorFootBallRedFoulTimes.GetRedFoulTimes() << ":" << visitorFootBallBlueFoulTimes.GetBlueFoulTimes() << endl;
    system("pause");
    return 0;
}