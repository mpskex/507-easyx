#include <main.h>

#pragma comment( lib, "MSIMG32.LIB")

//#define DEBUG
//#define ALPHA
// Home work of Liu Fangrui @ 2017 02


int main(void)
{
	// Define the Screen's Width and Height
	int SCREEN_W = 640, SCREEN_H = 480;
	initgraph(SCREEN_W, SCREEN_H);
/* This part only be compiled in alpha or released version */
#ifdef ALPHA
	// the Intro
	INTRO intro;
	// We can only load the image in main
	// For it can only be allocate (in memories)
	// in this scope
	loadimage(&intro.bk, _T("IMAGE"), _T("Intro"));
	// Do the Intro code
	intro_loop(intro, SCREEN_W, SCREEN_H);
#endif
	// We want a white background
	setbkcolor(WHITE);
	// Clear the whole clip
	clearcliprgn();
	// assign space for the Menu struct
	MENU menu; 
	loadimage(&(menu.bk), _T("IMAGE"), _T("Menu"));
	// Into the main loop
	while (1)
	{ 
		clearcliprgn();
		// Get the selected option from the loop return
		menu.select = menu_loop(menu, SCREEN_W, SCREEN_H);
		// Switch the cases with the return value
		switch (menu.select)
		{
		// New game
		case MENU_NEWGAME:
		{
			NAME name;
			name.str = NULL;
			clearcliprgn();
			int flag;
			flag = name_loop(name, SCREEN_W, SCREEN_H);
			break;
		}
		// About
		case MENU_ABOUT:
		{
			ABOUT about;
			about_loop(about, SCREEN_W, SCREEN_H);
			break;
		}
		// Exit
		case MENU_QUIT:
		{
			closegraph();
			return 0;
		}
		}
	}

}


/*
// ������ͼ����
initgraph(640, 480);

IMAGE img;
loadimage(&img, _T("start.bmp"));

// ��ȡ��ͼ���ں� IMAGE �����ľ�����TransparentBlt ������Ҫ��
HDC dstDC = GetImageHDC();
HDC srcDC = GetImageHDC(&img);

// ʹ�� Windows GDI ����ʵ��͸��λͼ
TransparentBlt(dstDC, 0, 0, img.getwidth(), img.getheight(), srcDC, 0, 0, img.getwidth(), img.getheight(), 0xffffff);     // ����һ�������Ǳ�ʾ͸��ɫΪ��ɫ
// ʹ GDI ������Ч
FlushBatchDraw();

// ���������˳�
getchar();
closegraph();
*/
