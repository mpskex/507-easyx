#include <name.h>

int name_loop(int SCREEN_W, int SCREEN_H)
{
	int pos = 0;
	wchar_t ch;
	wchar_t *name;
	name = (wchar_t*)calloc(BUFFSIZE, sizeof(wchar_t));
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT title_rect = { 0, 0, SCREEN_W, 3*SCREEN_H/4};
	RECT name_rect = { 0,SCREEN_H/2,SCREEN_W,SCREEN_H };
	while (1)
	{
		clearcliprgn();
		BeginBatchDraw();
		drawtext(_T("WHAT IS YOUR NAME?"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(name, &name_rect, DT_CENTER | DT_WORDBREAK);
		FlushBatchDraw();
		//if		(((GetAsyncKeyState(VK_BACK) & 1)||(GetAsyncKeyState(VK_DELETE)) )&& (pos > 0)) pos--;
		//else if (GetAsyncKeyState(VK_ESCAPE) & 1) { *flag = 1; return NULL; }
		//else if (GetAsyncKeyState(VK_RETURN) & 1) { *flag = 1; return name; }
		//else
		ch = _getch();
		if ( ch == 13 || ch == 10 || ch == 27)
		{
			clearcliprgn();
			BeginBatchDraw();
			drawtext(_T("Returned!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			FlushBatchDraw();
			Sleep(200);
			return 1;
		}
		else 
		{
			if(pos<BUFFSIZE-1) name[pos++] = ch;
		}
		Sleep(50);
	}
}
