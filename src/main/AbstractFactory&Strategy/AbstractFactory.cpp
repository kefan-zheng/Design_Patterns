#include "AbstractFactory.h"
//����������һ���������������Բ����ܲ���ƹ�������



const double RunningGameProduct::getelapsedTime()
{
    return this->elapsedTime;
}

const double RunningGameProduct::getdistance()
{
    return this->distance;
}



const vector<double> RunningGameProduct::getdistanceTravelled()
{
    return this->distanceTravelled;
}

const vector<double> RunningGameProduct::getscore()
{
    return this->score;
}

void RunningGameProduct::setelapsedTime(double para)
{
    this->elapsedTime = para;
}



void RunningGameProduct::setdistanceTravelled(vector<double> para)
{
    distanceTravelled.clear();
    this->distanceTravelled = para;
}

void RunningGameProduct::setscore(vector<double> para)
{
    score.clear();
    this->score = para;
}










