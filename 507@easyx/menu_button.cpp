#include <menu_button.h>


#define DEBUG

int menu_button_single(int SCREEN_W, int SCREEN_H, int cursor)
{
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT r = { 0, 0, SCREEN_W, 3*SCREEN_H / 4};
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
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 160, _T("Option"));
	if (cursor == 5) settextcolor(RED);
	else settextcolor(BLACK);
	outtextxy((int)SCREEN_W / 4, (int)SCREEN_H / 2 + 200, _T("Exit"));
#ifdef DEBUG
	if (GetAsyncKeyState(VK_ESCAPE) & 1)		return KEY_QUIT;
	else if (GetAsyncKeyState(VK_UP) & 1)		return KEY_UP;
	else if (GetAsyncKeyState(VK_DOWN) & 1)		return KEY_DOWN;
	else if (GetAsyncKeyState(VK_RIGHT) & 1)	return KEY_RIGHT;
	else if (GetAsyncKeyState(VK_LEFT) & 1)		return KEY_LEFT;
	else if (GetAsyncKeyState(VK_RETURN) & 1)	return KEY_ENTER;
	else return KEY_NONE;
#endif
#ifndef DEBUG
	return 0;
#endif
}
