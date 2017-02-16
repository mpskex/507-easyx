#include <menu.h>
#define DEBUG

int menu_loop(MENU menu, int SCREEN_W, int SCREEN_H)
{
	int button_return, cursor = 1;
	float i = 0;
	while ((int)i < (menu.bk).getwidth())
	{
		BeginBatchDraw();
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

		button_return = menu_button_single(SCREEN_W, SCREEN_H, cursor);
		switch (button_return)
		{
		case KEY_QUIT:			
		{
			return MENU_QUIT;
		}
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
		//这里解决了清空缓存区的问题
		if (_kbhit()) _getch();

		FlushBatchDraw();
		Sleep(40);
		clearcliprgn();
	}
	return 0;
}

#define DEBUG

int menu_button_single(int SCREEN_W, int SCREEN_H, int cursor)
{
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT r = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };
	drawtext(_T("HOW DO YOU DO?"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	settextstyle(36, 0, _T("SYSTEM"));
	if (cursor == 1) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 40, _T("Newgame"));
	if (cursor == 2) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 80, _T("Resume"));
	if (cursor == 3) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 120, _T("Chapter"));
	if (cursor == 4) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 160, _T("About"));
	if (cursor == 5) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 200, _T("Exit"));


	if (GetAsyncKeyState(VK_ESCAPE) & 1)		return KEY_QUIT;
	else if (GetAsyncKeyState(VK_UP) & 1)		return KEY_UP;
	else if (GetAsyncKeyState(VK_DOWN) & 1)		return KEY_DOWN;
	else if (GetAsyncKeyState(VK_RIGHT) & 1)	return KEY_RIGHT;
	else if (GetAsyncKeyState(VK_LEFT) & 1)		return KEY_LEFT;
	else if (GetAsyncKeyState(VK_RETURN) & 1)	return KEY_ENTER;
	else return KEY_NONE;

}