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
	int medals;//奖牌数
public:
	AthleteVO(string name, int serialNo, int medals = 0)
	{
		this->name = name;
		this->serialNo = serialNo;
		this->medals = medals;
	}
	string getName()
	{
		return this->name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	int getSerialNo()
	{
		return this->serialNo;
	}
	void setSerialNo(int serialNo)
	{
		this->serialNo = serialNo;
	}
	int getMedals()
	{
		return this->medals;
	}
	void setMedals(int medals)
	{
		this->medals = medals;
	}
};

// 业务对象
class SerialNoBO
{
private:
	//列表是当作一个数据库
	vector<AthleteVO> athletes;

public:
	SerialNoBO()
	{
		;
	}

	// 从数据库中增加一个运动员
	void addAthlete(AthleteVO athlete)
	{
		athletes.push_back(athlete);
	}
	// 从数据库中增加一堆运动员
	void addAthletes(vector<AthleteVO> athletes)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			athletes.push_back(*iter);
		}
	}

	// 从数据库中删除一个运动员
	void deleteAthlete(AthleteVO athlete)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == athlete.getSerialNo() && iter->getName() == athlete.getName()) {
				athletes.erase(iter);
				break;
			}
		}
	}

	// 从数据库中更改一个运动员的奖牌数
	void updateAthlete(AthleteVO athlete)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == athlete.getSerialNo()) {
				iter->setMedals(athlete.getMedals());
				cout << "Athlete: Serial No " << athlete.getSerialNo() << ", updated in the database." << endl;
				break;
			}
		}
	}

	// 从数据库中检索运动员名单
	vector<AthleteVO> getAllAthletes()
	{
		return athletes;
	}
	AthleteVO getAthlete(int serialNo)
	{
		for (vector<AthleteVO>::iterator iter = athletes.begin(); iter != athletes.end(); iter++) {
			if (iter->getSerialNo() == serialNo) {
				return *iter;
			}
		}
		return AthleteVO("error", -1);
	}
};