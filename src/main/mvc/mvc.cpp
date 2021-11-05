
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<numeric>
#include<deque>
#include<time.h>
#include "mvc.h"
#include<functional>
using namespace std;

void CreatePlayer(map<int, PlayerController>&plays, vector<int>&v1)//创建选手
{
    string No = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 24; i++)
    {
        Player p;
        string name(1,No[i]);
        p.setName("Player"+name);
        PlayerView pv;
        PlayerController pc(p,pv);

        plays.insert(pair<int, PlayerController>(1 + i, pc));
        v1.push_back(1 + i);
    }
}
void disorganize(vector<int>&v)//打乱选手
{
    cout << "----------Promotion event----------" << endl;
    random_shuffle(v.begin(), v.end());
}

void game(int index,map<int, PlayerController>&plays, vector<int>&AInput, vector<int>&AOut)//比赛
{
    multimap<int, int, greater<int>>TempScore;
    int couts = 0;

    for (vector<int>::iterator it = AInput.begin(); it != AInput.end();++it)
    {
        couts++;
        deque<int>score;
        for (int i = 0; i < 10; i++)
        {
            score.push_back(rand() % 40 + 60);
        }
        sort(score.begin(), score.end());
        score.pop_front();
        score.pop_back();
        int Sumscore = accumulate(score.begin(), score.end(), 0);
        int Avg = Sumscore / score.size();
        plays[*it].setPlayerScore(index,Avg);
        TempScore.insert(pair<int, int>(Avg, *it));
        if (couts%6==0)
        {
            cout << "Group Stage results" << endl;
            for (multimap<int, int, greater<int>>::iterator it = TempScore.begin(); it!= TempScore.end();++it)
            {
                //编号 姓名 得分
                cout << "No: "<< (*it).second <<"\t"<< plays[(*it).second].getPlayerName() <<
                     "\t" << (*it).first << endl;
            }
            while (TempScore.size()>3)
            {
                multimap<int, int, greater<int>>::iterator lit=TempScore.begin();
                AOut.push_back(lit->second);
                TempScore.erase(lit);
            }
            cout << endl;
            TempScore.clear();
        }
    }
}

void gameresult(int index,map<int, PlayerController>&plays,vector<int>&AOut)//打印比赛结果
{
    cout << index << " " <<" "<< "round" << endl;
    for (vector<int>::iterator it = AOut.begin(); it != AOut.end();++it)
    {
        //编号 姓名 得分
        cout << "No: " << *it << "\t" ;
        plays[*it].updateView(index);
        cout<<endl;
    }
}
int main()
{
    srand(time(0));
    map<int, PlayerController>plays;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    CreatePlayer(plays,v1);

    //第一轮
    disorganize(v1);
    game(1,plays,v1,v2);
    gameresult(1,plays, v2);
    cout << endl;
    //第二轮
    disorganize(v2);
    game(2, plays, v2, v3);
    gameresult(2, plays, v3);
    cout << endl;
    //第三轮
    disorganize(v3);
    game(3, plays, v3, v4);
    gameresult(3, plays, v4);
    return 0;
}