#include <option.h>

#define DEBUG
int option_button_single(int SCREEN_W, int SCREEN_H, int cursor)
{
	// Set title style
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT r = { 0, 0, SCREEN_W, SCREEN_H / 4 };
	// Draw the title
	drawtext(_T("- OPTION -"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// Change the text style
	settextstyle((int)(36*(SCREEN_W/1024)), 0, _T("SYSTEM"));
	if ((cursor & 0xf) == 1)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 8, (int)SCREEN_H / 3, _T("->Resolution<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 8, (int)SCREEN_H / 3, _T("Resolution"));
	}
	if ((cursor & 0xf) == 2)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 8, 2 * (int)SCREEN_H / 3, _T("->Difficulty<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 8, 2 * (int)SCREEN_H / 3, _T("Difficulty"));
	}

	if (cursor == 0x11)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("->640*480<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("640*480"));
	}
	if (cursor == 0x21)
	{
		settextcolor(RED);
		outtextxy(2 * (int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("->800*600<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(2 * (int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("800*600"));
	}
	if (cursor == 0x31)
	{
		settextcolor(RED);
		outtextxy(3 * (int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("->1024*576<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(3 * (int)SCREEN_W / 4, (int)SCREEN_H / 3 + 50, _T("1024*576"));
	}
	if (cursor == 0x12)
	{
		settextcolor(RED);
		outtextxy((int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("->EASY<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy((int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("EASY"));
	}
	if (cursor == 0x22)
	{
		settextcolor(RED);
		outtextxy(2 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("->MEDIUM<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(2 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("MEDIUM"));
	}
	if (cursor == 0x32)
	{
		settextcolor(RED);
		outtextxy(3 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("->HARD<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(3 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("HARD"));
	}
	if (cursor == 0x42)
	{
		settextcolor(RED);
		outtextxy(4 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("->EXTREME<-"));
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(4 * (int)SCREEN_W / 5, 2 * (int)SCREEN_H / 3 + 50, _T("EXTREME"));
	}

	// Handle the Key action
	if (GetAsyncKeyState(VK_ESCAPE) & 1)		return KEY_QUIT;
	else if (GetAsyncKeyState(VK_UP) & 1)		{_getch(); return KEY_UP;}
	else if (GetAsyncKeyState(VK_DOWN) & 1)		{_getch(); return KEY_DOWN;}
	else if (GetAsyncKeyState(VK_RIGHT) & 1)	{_getch(); return KEY_RIGHT;}
	else if (GetAsyncKeyState(VK_LEFT) & 1)		{_getch(); return KEY_LEFT;}
	else if (GetAsyncKeyState(VK_RETURN) & 1)	return KEY_ENTER;
	else return KEY_NONE;
	// Clear the input buffer
	while (_kbhit()) _getch();
}

int option_loop(OPTION option, int SCREEN_W, int SCREEN_H)
{
	clearcliprgn();
	int cursor = 0x11;
	while (1)
	{
		int button_return = 0;
		button_return = option_button_single(SCREEN_W, SCREEN_H, cursor);
		FlushBatchDraw();
		switch (button_return)
		{
		case KEY_UP:
		{
			if ((cursor & 0xf) > 1 && (cursor & 0xf) <= 2)
			{
				cursor--;
				cursor = (cursor & 0xf) + 0x10;
			}
			break;
		}
		case KEY_DOWN:
		{
			if ((cursor & 0xf) >= 1 && (cursor & 0xf) < 2)
			{
				cursor++;
				cursor = (cursor & 0xf) + 0x10;
			}
			break;
		}
		case KEY_RIGHT:
		{
			if ((cursor & 0xf) == 1)
			{
				if ((cursor & 0xf0) >= 0x10 && (cursor & 0xf0) < 0x30)
				{
					cursor += 0x10;
				}
			}
			else if ((cursor & 0xf) == 2)
			{
				if ((cursor & 0xf0) >= 0x10 && (cursor & 0xf0) < 0x40)
				{
					cursor += 0x10;
				}
			}
			break;
		}
		case KEY_LEFT:
		{
			if ((cursor & 0xf) == 1)
			{
				if ((cursor & 0xf0) > 0x10 && (cursor & 0xf0) <= 0x30)
				{
					cursor -= 0x10;
				}
			}
			else if ((cursor & 0xf) == 2)
			{
				if ((cursor & 0xf0) > 0x10 && (cursor & 0xf0) <= 0x40)
				{
					cursor -= 0x10;
				}
			}
			break;
		}
		case KEY_QUIT:
		{
			return 1;
			break;
		}
		case KEY_ENTER:
		{
			switch (cursor)
			{
			case OPTION_640:	option.setting.SCREEN_W = 640;	option.setting.SCREEN_H = 480; break;
			case OPTION_800:	option.setting.SCREEN_W = 800;	option.setting.SCREEN_H = 600; break;
			case OPTION_1024:	option.setting.SCREEN_W = 1024; option.setting.SCREEN_H = 576; break;
			case OPTION_EASY:	option.setting.mode = 2; option.setting.speed_ratio = 20; break;
			case OPTION_MEDUIM: option.setting.mode = 2; option.setting.speed_ratio = 10; break;
			case OPTION_HARD:	option.setting.mode = 1; option.setting.speed_ratio = 10; break;
			case OPTION_EXTREM:	option.setting.mode = 1; option.setting.speed_ratio = 5; break;
			}
			write_setting(option.setting); 
			break;
		}
		default:	break;
		}

		// Clear the input buffer
		Sleep(50);
		clearcliprgn();
	}
}
