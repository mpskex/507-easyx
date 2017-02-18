#include <game.h>

//#define DEBUG


int name_loop(GAME game, int SCREEN_W, int SCREEN_H)
{
	int pos = 0;
	wchar_t ch;
	game.player = (wchar_t*)calloc(BUFFSIZE, sizeof(wchar_t));
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT title_rect = { 0, 0, SCREEN_W, 3*SCREEN_H/4};
	RECT name_rect = { 0,SCREEN_H/2,SCREEN_W,SCREEN_H };
	while (1)
	{
		clearcliprgn();
		Sleep(50);
		BeginBatchDraw();
		drawtext(_T("WHAT IS YOUR NAME?"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(game.player, &name_rect, DT_CENTER | DT_WORDBREAK);
		FlushBatchDraw();

		if (_kbhit())
		{
			ch = _getch();
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				// Clear the input buffer
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				//Clear the input buffer
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				//Clear the input buffer
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				//Clear the input buffer
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Returned!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				game.player[pos + 1] = '\0';
				Sleep(200);
				return 1;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Escaped!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				// Release the pointer
				free(game.player);
				Sleep(200);
				return 1;
			}
			else if (GetAsyncKeyState(VK_BACK) & 1)
			{
				if(pos>0) game.player[--pos] = 0;
			}
			else if(ch >=33 && ch <= 126)
			{
				if(pos<BUFFSIZE-1) game.player[pos++] = ch;
			}
		}
	}
}

int game_loop(GAME game, int SCREEN_W, int SCREEN_H)
{
	while (1)
	{
		game_player_single(game, 30, 30, SCREEN_W, SCREEN_H);
		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			return 0;
		}
		// Clear the input buffer
		if (_kbhit()) _getch();
	}
}

int game_status_single(GAME game, int SCREEN_W, int SCREEN_H)
{
	return 0;
}

int game_content_single(GAME game, int SCREEN_W, int SCREEN_H)
{
	return 0;
}

int game_player_single(GAME game, int x, int y, int SCREEN_W, int SCREEN_H)
{
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(&game.player_fish);

	TransparentBlt(dstDC, x, y, 10*game.player_fish.getwidth(), 10*game.player_fish.getheight(), srcDC, 0, 0, game.player_fish.getwidth(), game.player_fish.getheight(), 0x000000);   
	FlushBatchDraw();
	return 0;
}