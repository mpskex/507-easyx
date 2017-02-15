#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>

#include <about.h>
#include <menu.h>
#include <intro.h>
#include <name.h>

#pragma comment( lib, "MSIMG32.LIB")

//#define DEBUG
//#define ALPHA
// Home work of Liu Fangrui @ 2017 02


int main(void)
{
	int SCREEN_W = 640, SCREEN_H = 480;
	initgraph(SCREEN_W, SCREEN_H);
#ifdef ALPHA
	INTRO intro;
	loadimage(&intro.bk, _T("IMAGE"), _T("Intro"));
	intro_loop(intro, SCREEN_W, SCREEN_H);
#endif
	setbkcolor(WHITE);
	clearcliprgn();
	MENU menu; 
	while (1)
	{
		clearcliprgn();
		loadimage(&(menu.bk), _T("IMAGE"), _T("Menu"));
		menu.select = menu_loop(menu, SCREEN_W, SCREEN_H);
		_getch();
		fflush(stdin);

		switch (menu.select)
		{
		case MENU_NEWGAME:
		{
			clearcliprgn();
			int flag;
			flag = name_loop(SCREEN_W, SCREEN_H);
			fflush(stdin);
			break;
		}
		case MENU_ABOUT:
		{
			ABOUT about;
			about_loop(about, SCREEN_W, SCREEN_H);
			break;
		}
		case MENU_QUIT:
		{
			closegraph();
			return 0;
		}
		}
	}

}


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
