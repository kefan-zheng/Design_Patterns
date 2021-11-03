#include "Swimming.h"
using namespace std;

void Athlete::nextSec()
{
    if (distance < 200)
    {
        distance += 1 + rand() % 3;
        ++time;
    }
    if (distance > 200)
        distance = 200;
}
int Athlete::getDis() const
{
    return distance;
}
std::string Athlete::getName() const
{
    return name;
}
bool Athlete::isFinal() const
{
    return distance == 200;
}
int Athlete::getTime() const
{
    return time;
}
void Swimming::addAth(Athlete ath)
{
    Athletes.push_back(ath);
}
void Swimming::run()
{
    vector<bool> finale(Athletes.size(), false);
    cout << getName() << " begins!\n";
    for (int i = 0; i != 4; ++i)
    {
        for (int j = 0; j != 30; ++j)
        {
            for (auto index = 0ull; index != Athletes.size(); ++index)
            {
                Athletes[index].nextSec();
                if (!finale[index] && Athletes[index].isFinal())
                {
                    finale[index] = true;
                    Res.push_back(Athletes[index]);
                }
            }
        }
        cout << 30 * (i + 1) << "s:\n";
        for (const auto& ath : Athletes)
        {
            int dis = ath.getDis();
            bool direction = (dis / 50) % 2; //false -> true<-
            dis = direction ? (50 - dis % 50) : (dis % 50);
            cout << left << setw(12) << ath.getName()
                 << string(dis, '*') << (direction ? '<' : '>')
                 << string(49 - dis, '*') << endl;
        }
    }
    cout << getName() << " ends!\nResults:\n";
    for (auto index = 0ull; index != Res.size(); ++index)
    {
        cout << left << setw(4) << index + 1 << setw(15) << Res[index].getName() << setw(3) << Res[index].getTime() << "s\n";
    }
    cout << endl;
}

int main() //test
{
    srand(time(nullptr));
    ManFreestyle200Factory m;
    WomenFreestyle200Factory w;
    Swimming* s1 = m.createSwimming();
    Swimming* s2 = w.createSwimming();
    s1->addAth(string("NingZetao"));
    s1->addAth(string("LiGuangyuan"));
    s1->addAth(string("XuJiayu"));
    s2->addAth(string("YeShiwen"));
    s2->addAth(string("FuYuanhui"));
    s2->addAth(string("ZhangYufei"));
    s1->run();
    s2->run();
    return 0;
}