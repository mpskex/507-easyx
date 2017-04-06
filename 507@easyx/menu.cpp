#include <menu.h>
#define DEBUG

int menu_button_single(int SCREEN_W, int SCREEN_H, int cursor)
{
	// Set title style
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT r = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };
	// Draw the title
	drawtext(_T("THE ADV OF LinUs"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// Change the text style
	settextstyle(36, 0, _T("SYSTEM"));
	if (cursor == 1)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 40, _T("->Newgame<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 40, _T("Newgame"));
	}
	if (cursor == 2)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 80, _T("->Resume<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 80, _T("Resume"));
	}
	if (cursor == 3)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 120, _T("->Option<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 120, _T("Option"));
	}
	if (cursor == 4)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 160, _T("->About<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 160, _T("About"));
	}
	if (cursor == 5)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 200, _T("->Exit<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 200, _T("Exit"));
	}

	// Handle the Key action
	if (GetAsyncKeyState(VK_ESCAPE) & 1)		return KEY_QUIT;
	else if (GetAsyncKeyState(VK_UP) & 1)		return KEY_UP;
	else if (GetAsyncKeyState(VK_DOWN) & 1)		return KEY_DOWN;
	else if (GetAsyncKeyState(VK_RIGHT) & 1)	return KEY_RIGHT;
	else if (GetAsyncKeyState(VK_LEFT) & 1)		return KEY_LEFT;
	else if (GetAsyncKeyState(VK_RETURN) & 1)	return KEY_ENTER;
	else return KEY_NONE;
}

int menu_loop(MENU &menu, int SCREEN_W, int SCREEN_H)
{
	loadimage(&(menu.bk), _T("IMAGE"), _T("Menu"));
	int button_return, cursor = 1;
	int i = 0;
	while (i < (menu.bk).getwidth())
	{
		// Begin to draw
		BeginBatchDraw();
		// Fill the Screen with bk
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
		// Calling the button drawing function
		button_return = menu_button_single(SCREEN_W, SCREEN_H, cursor);
#ifdef SHOW_VER
		settextcolor(BLACK);
		settextstyle(12, 0, _T("SYSTEM"));
		outtextxy(0, SCREEN_H - 20, _T(DEV));
		outtextxy(0 + 100, SCREEN_H - 20, _T(VERSION));
#endif
		// Take action according the key action
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
		default:	break;
		}

		i += 1;
		if (i >= (menu.bk).getwidth()) i = -(menu.bk).getwidth();
		// Clear the input buffer
		if (_kbhit()) _getch();
		// Apply those drawing
		FlushBatchDraw();
		// lock fps
		Sleep(60);
		// Clear the screen
		clearcliprgn();
	}
	return 0;
}
