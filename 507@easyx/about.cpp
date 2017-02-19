#include <about.h>

#define DEBUG

void about_loop(ABOUT about, int SCREEN_W, int SCREEN_H)
{
	settextcolor(BLACK);
	settextstyle(36, 0, _T("SYSTEM"));
	RECT r = { 50, 50, SCREEN_W - 50, SCREEN_H - 50};
	while (1)
	{
		clearcliprgn();
		BeginBatchDraw();
		// macro DT_WORDBREAK can enable auto-return 
		drawtext(_T("This game is developed as a homework at first.\nAuthor: Liu Fangrui\nPlease contact mpskex@163.com\nThe Project is on github:\n\n   https://github.com/mpskex/507-easyx\n\n\nHope you enjoy this game! :P\nLOL\n"), &r, DT_LEFT | DT_WORDBREAK);
		FlushBatchDraw();
		Sleep(50);

		if ((GetAsyncKeyState(VK_ESCAPE) & 1) || (GetAsyncKeyState(VK_RETURN) & 1))
		{
			return;
		}
	}
}
