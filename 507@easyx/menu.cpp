#include <menu.h>


#ifdef DEBUG
void menu_loop(MENU menu, int SCREEN_W, int SCREEN_H)
{
	DWORD* g_scr_pt = GetImageBuffer();
	float i = 0, factor = 0;
	RECT r = { 0, 0, SCREEN_W, SCREEN_H };
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	while ((int)i < (menu.bk).getwidth())
	{
		//if((int)i%2==0) cleardevice();
		//if ((int)i % 2 == 0) clearcliprgn();
		for (int m = -(menu.bk).getwidth(); m < SCREEN_W + (menu.bk).getwidth(); m += 2 * (menu.bk).getwidth())
		{
			for (int n = 0; n < SCREEN_H; n += 2 * (menu.bk).getheight())
			{
				putimage(m - i, n, &(menu.bk));
			}
		}
		for (int m = 0; m < SCREEN_W + (menu.bk).getwidth(); m += 2 * (menu.bk).getwidth())
		{
			for (int n = (menu.bk).getheight(); n < SCREEN_H; n += 2 * (menu.bk).getheight())
			{
				putimage(m - i, n, &(menu.bk));
			}
		}

		drawtext(_T("HOW DO YOU DO?"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		i += 1.0;
		if (i >= (menu.bk).getwidth()) i = -(menu.bk).getwidth();

		Sleep(50);
		clearcliprgn();
	}
}
#endif

#ifndef DEBUG
void menu_loop(MENU menu, int SCREEN_W, int SCREEN_H)
{
	DWORD* g_scr_pt = GetImageBuffer();
	float i = 0, factor = 0;
	RECT r = { 0, 0, 640, 480 };
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	while ((int)i < (menu.bk).getwidth())
	{
		//if((int)i%2==0) cleardevice();
		//if ((int)i % 2 == 0) clearcliprgn();
		for (int m = -(menu.bk).getwidth(); m < SCREEN_W + (menu.bk).getwidth(); m += 2 * (menu.bk).getwidth())
		{
			for (int n = 0; n < SCREEN_H; n += 2 * (menu.bk).getheight())
			{
				putimage(m - i, n, &(menu.bk));
			}
		}
		for (int m = 0; m < SCREEN_W + (menu.bk).getwidth(); m += 2 * (menu.bk).getwidth())
		{
			for (int n = (menu.bk).getheight(); n < SCREEN_H; n += 2 * (menu.bk).getheight())
			{
				putimage(m - i, n, &(menu.bk));
			}
		}

		drawtext(_T("HOW DO YOU DO?"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		i += 1.0;
		if (i >= (menu.bk).getwidth()) i = -(menu.bk).getwidth();

		Sleep(50);
		clearcliprgn();
	}
}
#endif