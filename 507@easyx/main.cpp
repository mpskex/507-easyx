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
// 创建绘图窗口
initgraph(640, 480);

IMAGE img;
loadimage(&img, _T("start.bmp"));

// 获取绘图窗口和 IMAGE 对象的句柄，TransparentBlt 函数需要用
HDC dstDC = GetImageHDC();
HDC srcDC = GetImageHDC(&img);

// 使用 Windows GDI 函数实现透明位图
TransparentBlt(dstDC, 0, 0, img.getwidth(), img.getheight(), srcDC, 0, 0, img.getwidth(), img.getheight(), 0xffffff);     // 最后一个参数是表示透明色为白色
// 使 GDI 操作生效
FlushBatchDraw();

// 按任意键退出
getchar();
closegraph();
*/
//-----------------------------------------------------
/*
// 初始化绘图窗口
initgraph(640, 480);

IMAGE img;
loadimage(&img, _T("IMAGE"), _T("Menu"));


// 获取指向显存的指针
DWORD* pMem = GetImageBuffer();
DWORD* pImg = GetImageBuffer(&img);
// 直接对显存赋值
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

// 使显存生效（注：操作指向 IMAGE 的显存不需要这条语句）

// 按任意键退出
getchar();
closegraph();
*/