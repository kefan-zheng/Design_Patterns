#include "decorator.h"

GameProduct* produceTableTennis() {
    TableTennisFactory* ttfactory = new TableTennisFactory;
    vector<string>sName; vector<string>sNation;
    sName.push_back("Zhendong Fan");
    sName.push_back("Long Ma");
    sNation.push_back("China");
    sNation.push_back("China");
    return ttfactory->Produce("Table Tennis- Men's singles-Gold Medal match", "2021-10-10 08:00", "Tennis Room", sName, sNation, 0);
}
GameProduct* produceRunningGameProduct() {
    RunningFactory* rfactory = new RunningFactory;
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
    return rfactory->Produce("men's 100m run-final", "2021-10-11 14:00", "Field 25", sName2, sNation2, 0);
}
void mimicTableTennisGame() {
    GameProduct* tableTennis = produceTableTennis();
    ContestWindow* window = new ContestWindow;
    BasicInfo* bs = new BasicInfo(tableTennis);
    ScoreComparison* showGame = new ScoreComparison(bs, tableTennis);
    window->SetContents(new ScoreComparison(bs, tableTennis));
    cout << endl;
    tableTennis->setContestState(1);
    //生成随机函数
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned>distribution(0, 0xFFFFFFFFFFFFFFFF);
    while (true) {
        bool terminate = false;
        for (int i = 0; i < 3; ++i) {
            tableTennis->setScore(distribution(generator) % 2);
            int score1 = tableTennis->getScore1(), score2 = tableTennis->getScore2();
            if (score1 >= 11 && score1 - score2 >= 2 || score2 >= 11 && score2 - score1 >= 2) { terminate = true; tableTennis->setContestState(3); break; }
        }
        window->SetContents(new ScoreComparison(bs, tableTennis));
        cout << endl;
        if (terminate)break;
    }
}
void mimicRunningGame() {
    GameProduct* running = produceRunningGameProduct();
    BasicInfo* bs2 = new BasicInfo(running);
    ContestWindow* window2 = new ContestWindow;
    window2->SetContents(new Rankings(bs2, running));
    cout << endl;
    running->setContestState(1);
    vector<double>distance = running->getdistanceTravelled();
    vector<double>score = running->getscore();
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned>distribution(0, 0xFFFFFFFFFFFFFFFF);
    while (true) {
        double time = running->getelapsedTime();
        bool terminate = true;
        for (int i = 0; i < distance.size(); ++i) {
            if (100 - distance[i] <= 1e-6)continue;
            if (distance[i] >= 89) {
                score[i]=(time + (100 - distance[i]) / 11);
                distance[i] = 100;
            }
            else {
                terminate = false;
                distance[i] += (distribution(generator) % 18000 + 25200) / 3600.0;
            }
        }
        running->setdistanceTravelled(distance);
        running->setscore(score);
        running->setelapsedTime(time + 1);
        if (terminate) {
            running->setContestState(3);
            break;
        }
        window2->SetContents(new Rankings(bs2, running));
        cout << endl;
    }
    window2->SetContents(new Rankings(bs2, running));
}
int main() {
    mimicTableTennisGame();
    cout << endl;
    mimicRunningGame();
   
    return 0;
}