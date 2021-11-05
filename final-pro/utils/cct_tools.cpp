#pragma once
#include "./cct_tools.h"

//������ƶ���ָ��λ��
void cct_gotoxy(int x, int y)
{
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//�ı������ɫ
void cct_setcolor(const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

//���ض�λ�����ض���ɫ��ӡ��ͬ�����ַ�
void cct_showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int rpt)
{
	int i;

	cct_gotoxy(X, Y);
	cct_setcolor(bg_color, fg_color);

	/* ѭ��n�Σ���ӡ�ַ�ch */
	for (i = 0; i < rpt; i++)
		putchar(ch);
}

//���������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
void cct_cls(void)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(__hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(__hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(__hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(__hout, coord);
	return;
}


