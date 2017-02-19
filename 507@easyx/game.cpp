#include <game.h>

//#define DEBUG

int name_loop(GAME game, int SCREEN_W, int SCREEN_H)
{
	int pos = 0;
	wchar_t ch;
	//game.player = (wchar_t*)calloc(BUFFSIZE, sizeof(wchar_t));
	int i;
	for (i = 0; i < BUFFSIZE; i++)
	{
		game.player[i] = 0;
	}
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
				return 0;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Escaped!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				// Release the pointer
				Sleep(200);
				clearcliprgn();
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
	clearcliprgn();
	RECT title_rect = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };

	while (1)
	{
		clearcliprgn();
		game.mouse = GetMouseMsg();
		switch (game.mouse.uMsg)
		{
		case WM_MOUSEMOVE:
			break;

		case WM_LBUTTONDOWN:
			break;

		case WM_RBUTTONUP:
			break;
		}

		FlushMouseMsgBuffer();
		BeginBatchDraw();
		game_player_single(game, game.mouse.x, game.mouse.y, 5, SCREEN_W, SCREEN_H);
		game_status_single(game, SCREEN_W, SCREEN_H);
		Sleep(10);
		//FlushBatchDraw();
		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			clearcliprgn();
			//BeginBatchDraw();
			drawtext(_T("Returned!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			FlushBatchDraw();
			Sleep(500);
			return 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 1)
		{

		}
		//Sleep(10);
		// Clear the input buffer
		if (_kbhit()) _getch();
		FlushBatchDraw();
	}
}

int game_main(GAME game, int SCREEN_W, int SCREEN_H)
{
	int _return = name_loop(game, SCREEN_W, SCREEN_H);
	if (_return == 0)
	{
		clearcliprgn();
		game_loop(game, SCREEN_W, SCREEN_H);
		clearcliprgn();
		return 0;
	}
	else
	{
		clearcliprgn();
		return 0;
	}
}

int game_status_single(GAME game, int SCREEN_W, int SCREEN_H)
{
	settextstyle(36, 0, _T("SYSTEM"));
	// This function need restruct with drawtext();
	outtextxy(3 * (int)(SCREEN_W / 4), 3 * (int)(SCREEN_H / 4), _T("Player: "));
	outtextxy(3 * (int)(SCREEN_W / 4), 5 * (int)(SCREEN_H / 6), game.player);
	return 0;
}

int game_background_single(GAME game, int SCREEN_W, int SCREEN_H)
{
	return 0;
}

int game_npc_single(GAME game, int SCREEN_W, int SCREEN_H)
{
	return 0;
}

int game_player_single(GAME game, int mouse_x, int mouse_y, float level, int SCREEN_W, int SCREEN_H)
{
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(&game.player_fish);

	TransparentBlt(dstDC, 
					mouse_x - (int)(level * game.player_fish.getwidth() / 2),
					mouse_y - (int)(level * game.player_fish.getheight() / 2),
					(int)(level * game.player_fish.getheight()), 
					(int)(level * game.player_fish.getheight()), 
					srcDC, 0, 0, 
					game.player_fish.getwidth(), 
					game.player_fish.getheight(), 
					0x000000);
	//FlushBatchDraw();
	return 0;
}