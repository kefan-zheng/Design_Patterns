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

/* ������ɫ���ú궨��ȡ�����֣�������䣩 */
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_GREEN		2	//��
#define COLOR_CYAN		3	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_YELLOW	6	//��
#define COLOR_WHITE		7	//��
#define COLOR_HBLACK	8	//����
#define COLOR_HBLUE		9	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HCYAN		11	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HWHITE	15	//����

static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//ȡ��׼����豸��Ӧ�ľ��
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//ȡ��׼�����豸��Ӧ�ľ��

using namespace std;

//������ƶ���ָ��λ��
void cct_gotoxy(int x, int y);

//�ı������ɫ
void cct_setcolor(const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);

//���ض�λ�����ض���ɫ��ӡ��ͬ�����ַ�
void cct_showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int rpt);

//���������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
void cct_cls(void);