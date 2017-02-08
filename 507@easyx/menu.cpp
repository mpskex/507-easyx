#include <menu.h>
#define DEBUG

#ifdef DEBUG
int menu_loop(MENU menu, int SCREEN_W, int SCREEN_H)
{
	int button_return, cursor = 1;
	float i = 0;
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

		//if (menu_button_single(SCREEN_W, SCREEN_H) == QUIT) break;
		button_return = menu_button_single(SCREEN_W, SCREEN_H, cursor);
		switch (button_return)
		{
		case KEY_QUIT:			return MENU_QUIT;
		//case KEY_ENTER:		if(cursor == 0) cursor == 1;
		case KEY_UP:
		{
			if (cursor > 1 && cursor <= 5)
			{
				cursor--;
			}
			break;
		}
		case KEY_DOWN:
		{
			if (cursor >= 1 && cursor < 5)
			{
				cursor++;
			}
			break;
		}
		case KEY_ENTER:
		{
			if (cursor != 5)
			{
				return 1000 + cursor;
			}
			else
			{
				return MENU_QUIT;
			}
		}
		defalut:			break;
		}

		i += 1.0;
		if (i >= (menu.bk).getwidth()) i = -(menu.bk).getwidth();

		Sleep(50);
		clearcliprgn();
	}
	return 0;
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