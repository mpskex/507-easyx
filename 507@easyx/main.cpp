#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>

#include <menu.h>
#include <intro.h>

#pragma comment( lib, "MSIMG32.LIB")

#define DEBUG
// Home work of Liu Fangrui @ 2017 02

#ifdef DEBUG
int main(void)
{
	int SCREEN_W = 640, SCREEN_H = 480;
	initgraph(SCREEN_W, SCREEN_H);


	setbkcolor(WHITE);
	clearcliprgn();

	MENU menu;
	loadimage(&(menu.bk), _T("IMAGE"), _T("Menu"));
	menu_loop(menu, SCREEN_W, SCREEN_H);

	closegraph();
}
#endif

#ifndef DEBUG
int main(void)
{
	int SCREEN_W = 640, SCREEN_H = 480;
	initgraph(SCREEN_W, SCREEN_H);

	INTRO intro;
	loadimage(&intro.bk, _T("IMAGE"), _T("Intro"));
	intro_loop(intro, SCREEN_W, SCREEN_H);

	setbkcolor(WHITE);
	clearcliprgn();

	MENU menu;
	loadimage(&(menu.bk), _T("IMAGE"), _T("Menu"));
	menu_loop(menu, SCREEN_W, SCREEN_H);

	closegraph();
}
#endif

/*
// ������ͼ����
initgraph(640, 480);

IMAGE img;
loadimage(&img, _T("start.bmp"));

// ��ȡ��ͼ���ں� IMAGE ����ľ����TransparentBlt ������Ҫ��
HDC dstDC = GetImageHDC();
HDC srcDC = GetImageHDC(&img);

// ʹ�� Windows GDI ����ʵ��͸��λͼ
TransparentBlt(dstDC, 0, 0, img.getwidth(), img.getheight(), srcDC, 0, 0, img.getwidth(), img.getheight(), 0xffffff);     // ���һ�������Ǳ�ʾ͸��ɫΪ��ɫ
// ʹ GDI ������Ч
FlushBatchDraw();

// ��������˳�
getchar();
closegraph();
*/
//-----------------------------------------------------
/*
// ��ʼ����ͼ����
initgraph(640, 480);

IMAGE img;
loadimage(&img, _T("IMAGE"), _T("Menu"));


// ��ȡָ���Դ��ָ��
DWORD* pMem = GetImageBuffer();
DWORD* pImg = GetImageBuffer(&img);
// ֱ�Ӷ��Դ渳ֵ
while (1)
{
for (int k = 155; k < 255; k += 2)
{
for (int i = 0; i < 640 * 480; i++)
{
pMem[i] = BGR(RGB(255 - k, k, i * 256 / (640 * 480)));
}
FlushBatchDraw();
putimage(0, 0, &img);
Sleep(50);
}
for (int k = 255; k > 155; k -= 2)
{
for (int i = 0; i < 640 * 480; i++)
{
pMem[i] = BGR(RGB(255 - k, k, i * 256 / (640 * 480)));
}
FlushBatchDraw();
putimage(0, 0, &img);
Sleep(50);
}
}

// ʹ�Դ���Ч��ע������ָ�� IMAGE ���Դ治��Ҫ������䣩

// ��������˳�
getchar();
closegraph();
*/