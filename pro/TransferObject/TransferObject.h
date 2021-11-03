#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<sstream>
using namespace std;


// 传输对象(Transfer Object)模式：用于从客户端向服务器一次性传递带有多个属性的数据。
// 传输对象也被称为数值对象(Value Object)。
// 实体：
//	业务对象（Business Object） - 为传输对象填充数据的业务服务。
//	传输对象（Transfer Object） - 简单的 POJO，只有设置 / 获取属性的方法。
//	客户端（Client） - 客户端可以发送请求或者发送传输对象到业务对象。


// 传输对象
class AthleteVO
{
private:
	string name;
	int serialNo;//编号
	int win;
	int fail;
	double winRate;//胜率
public:
	AthleteVO(string name, int serialNo, int win, int fail);
	string getName();
	void setName(string name);
	int getSerialNo();
	void setSerialNo(int serialNo);
	int getWin();
	void setWin(int win);
	int getFail();
	void setFail(int fail);
	int getWinRate();
	void setWinRate(double winRate);
	void updateWinRate(string result);
};

// 业务对象
class SerialNoBO
{
private:
	//列表是当作一个数据库
	vector<AthleteVO> athletes;

public:
	// 从数据库中增加一个运动员
	void addAthlete(AthleteVO athlete);
	// 从数据库中增加一堆运动员
	void addAthletes(vector<AthleteVO> athletes);

	// 从数据库中删除一个运动员
	void deleteAthlete(AthleteVO athlete);

	// 从数据库中更新一个运动员的信息(胜率)（一场比赛后调用）
	void updateAthlete(AthleteVO athlete);

	// 从数据库中检索运动员名单
	vector<AthleteVO> getAllAthletes();
	AthleteVO getAthlete(int serialNo);
};

int testTransferObject();