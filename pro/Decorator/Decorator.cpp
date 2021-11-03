#include "Decorator.h"

int testDecorator() {
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
    cout << endl;

    return 0;
}