#pragma once
#include<iostream>
//#include <graphics.h>
#include <conio.h>
#include<fstream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <tchar.h>
#include <string.h>
#include <Windows.h>

/* 定义颜色（用宏定义取代数字，方便记忆） */
#define COLOR_BLACK		0	//黑
#define COLOR_BLUE		1	//蓝
#define COLOR_GREEN		2	//绿
#define COLOR_CYAN		3	//青
#define COLOR_RED		4	//红
#define COLOR_PINK		5	//粉
#define COLOR_YELLOW	6	//黄
#define COLOR_WHITE		7	//白
#define COLOR_HBLACK	8	//亮黑
#define COLOR_HBLUE		9	//亮蓝
#define COLOR_HGREEN	10	//亮绿
#define COLOR_HCYAN		11	//亮青
#define COLOR_HRED		12	//亮红
#define COLOR_HPINK		13	//亮粉
#define COLOR_HYELLOW	14	//亮黄
#define COLOR_HWHITE	15	//亮白

static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//取标准输出设备对应的句柄
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//取标准输入设备对应的句柄

using namespace std;

//将光标移动到指定位置
void cct_gotoxy(int x, int y);

//改变输出颜色
void cct_setcolor(const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);

//在特定位置用特定颜色打印相同若干字符
void cct_showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int rpt);

//清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
void cct_cls(void);