
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<numeric>
#include<deque>
#include<time.h>
#include<functional>
#include "mvc.h"
using namespace std;

PlayerController::PlayerController(Player model, PlayerView view)
{
    this->model = model;
    this->view = view;
}

void PlayerController::setPlayerName(string name)
{
    this->model.setName(name);
}

string PlayerController::getPlayerName()
{
    return this->model.getName();
}

void PlayerController::updateView(int i)
{
    this->view.playerDetails(model,i);
}
void PlayerView::playerDetails(Player player,int i)
{
    cout <<player.getName()<<" "<<player.getScore(i);
}

string Player ::getName()
{
    return name;
}

void Player::setName(string name)
{
    this->name = name;
}
//class player
//{
//public:
//    string name;
//    int Score[3];
//};

void CreatePlayer(map<int, PlayerController>&plays, vector<int>&v1)//����ѡ��
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
void disorganize(vector<int>&v)//����ѡ��
{
    cout << "-------New Round Competition-----" << endl;
    random_shuffle(v.begin(), v.end());
}

void game(int index,map<int, PlayerController>&plays, vector<int>&AInput, vector<int>&AOut)//����
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
            cout << "Group Competition Results" << endl;
            for (multimap<int, int, greater<int>>::iterator it = TempScore.begin(); it
                                                                                    != TempScore.end();++it)
            {
                //��� ���� �÷�
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

void gameresult(int index,map<int, PlayerController>&plays,vector<int>&AOut)//��ӡ�������
{
    cout << " " << index << " round" <<" "<< "promotion list" << endl;
    for (vector<int>::iterator it = AOut.begin(); it != AOut.end();++it)
    {
        //��� ���� �÷�
//        cout << "No: " << *it << "\t" << plays[*it].getPlayerName() << "\t" <<
//             plays[*it].getPlayerScore(index) << endl;
        cout<<"No: "<<*it<<"\t";
        plays[*it].updateView(index);
        cout<<"\t"<<endl;
    }
}
int testMvc()
{
    srand(time(0));
    map<int, PlayerController>plays;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    CreatePlayer(plays,v1);

    //��һ��
    disorganize(v1);
    game(1,plays,v1,v2);
    gameresult(1,plays, v2);
    cout << endl;
    //�ڶ���
    disorganize(v2);
    game(2, plays, v2, v3);
    gameresult(2, plays, v3);
    cout << endl;
    //������
    disorganize(v3);
    game(3, plays, v3, v4);
    gameresult(3, plays, v4);
    return 0;
}
