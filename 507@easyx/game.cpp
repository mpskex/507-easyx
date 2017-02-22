#include <game.h>

#define DEBUG

int name_loop(GAME &game, int SCREEN_W, int SCREEN_H)
{
	int pos = 0;
	game.player = (wchar_t *)malloc(BUFFSIZE * sizeof(wchar_t));
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
				settextstyle(36, 0, _T("SYSTEM"));
				drawtext(_T("\n\n\nUse your MOUSE to move LinUs.\n\n\nPRESS ANY KEY TO CONTINUE..."), &title_rect, DT_CENTER | DT_WORDBREAK);
				game.player[pos + 1] = '\0';
				FlushBatchDraw();
				_getch();
				clearcliprgn();
				return 0;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Escaped!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				// Release the pointer
				Sleep(100);
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
int game_loop(GAME &game, int SCREEN_W, int SCREEN_H)
{
	clearcliprgn();
	float level = 0;
	game.mouse.x = SCREEN_W / 2;
	game.mouse.y = SCREEN_H / 2;

	srand((unsigned)time(NULL));
	game.time_begin = time(NULL);
	fish_add(game, 1000, SCREEN_W, 3*(int)(SCREEN_H / 4));


	RECT title_rect = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };
	FlushMouseMsgBuffer();
	Sleep(5);
	while (1)
	{
		if (MouseHit())
		{
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
		}
		level = rand() % 50 / 10 + 0.5;
		BeginBatchDraw();
		game_background_single(game, SCREEN_W, SCREEN_H);
		fish_single(game, SCREEN_W, 3 * (int)(SCREEN_H / 4));
		game_player_single(game, game.mouse.x, game.mouse.y, 2, SCREEN_W, 3 * (int)(SCREEN_H / 4));

		game_status_single(game, SCREEN_W, SCREEN_H);



		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			clearcliprgn();
			//BeginBatchDraw();
			settextstyle(72, 0, _T("SYSTEM"));
			drawtext(_T("Loading..."), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			FlushBatchDraw();
			fish_clear(game);
			Sleep(200);
			return 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 1)
		{

		}
		// Clear the input buffer
		if (_kbhit()) _getch();
		//Sleep(5);
		FlushBatchDraw();
		//FlushMouseMsgBuffer();
		clearcliprgn();
	}
}

int game_main(GAME &game, int SCREEN_W, int SCREEN_H)
{
	int _return = 0;
	loadimage(&game.player_fish, _T("IMAGE"), _T("GAME_FISH_PLAYER"));
	loadimage(&game.npc_fish, _T("IMAGE"), _T("GAME_FISH_01"));
	loadimage(&game.background, _T("IMAGE"), _T("GAME_BACKGROUND"));
	_return = name_loop(game, SCREEN_W, SCREEN_H);
	if (_return == 0)
	{
		game_loop(game, SCREEN_W, SCREEN_H);
		return 0;
	}
	else
	{
		return 1;
	}
}

int game_status_single(GAME &game, int SCREEN_W, int SCREEN_H)
{
	//-------------------Player Box-----------------------
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(3 * (int)(SCREEN_W / 4) - 12, 3 * (int)(SCREEN_H / 4) - 12, SCREEN_W - 8, SCREEN_H - 8);
	rectangle(3 * (int)(SCREEN_W / 4) - 10, 3 * (int)(SCREEN_H / 4) - 10, SCREEN_W - 10, SCREEN_H - 10);
	settextstyle(36, 0, _T("SYSTEM"));
	// This function need restruct with drawtext();
	outtextxy(3 * (int)(SCREEN_W / 4), 3 * (int)(SCREEN_H / 4), _T("Player: "));
	outtextxy(3 * (int)(SCREEN_W / 4), 5 * (int)(SCREEN_H / 6), game.player);
	//-------------------Player Box-----------------------

	//-------------------Static Box-----------------------
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(12, 3 * (int)(SCREEN_H / 4) - 12, 3 * (int)(SCREEN_W / 4) - 72, SCREEN_H - 10);
	rectangle(10, 3 * (int)(SCREEN_H / 4) - 10, 3 * (int)(SCREEN_W / 4) - 72, SCREEN_H - 10);
	settextstyle(36, 0, _T("SYSTEM"));
	// This function need restruct with drawtext();

	//	Timer
	game.time_sec = time(NULL);
	outtextxy(2 * (int)(SCREEN_W / 4), 3 * (int)(SCREEN_H / 4), _T("Time: "));
	outtextxy(2 * (int)(SCREEN_W / 4), 5 * (int)(SCREEN_H / 6), (wchar_t)((game.time_sec - game.time_begin) / 10 + 48));
	outtextxy(2 * (int)(SCREEN_W / 4) + 15, 5 * (int)(SCREEN_H / 6), (wchar_t)((game.time_sec - game.time_begin) % 10 + 48));


	//-------------------Time Box-----------------------


#ifdef DEBUG
	settextstyle(12, 0, _T("SYSTEM"));
	outtextxy(0, 0, _T("DEBUG MODE"));
#endif
	return 0;
}

int game_background_single(GAME &game, int SCREEN_W, int SCREEN_H)
{
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(&game.background);

	TransparentBlt(dstDC,
		0,
		0,
		SCREEN_W,
		SCREEN_H,
		srcDC, 0, 0,
		game.background.getwidth(),
		game.background.getheight(),
		0x000000);
	return 0;
}

int game_npc_single(GAME &game, int SCREEN_W, int SCREEN_H)
{
	return 0;
}

int game_player_single(GAME &game, int mouse_x, int mouse_y, float level, int SCREEN_W, int SCREEN_H)
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
	return 0;
}

int fish_single(GAME &game, int SCREEN_W, int SCREEN_H)
{
	FISH *p;
	IMAGE tmp;
	tmp = game.npc_fish;
	srand((unsigned)time(NULL));
	for (p = game.fish; p != NULL; p = p->next)
	{

		HDC dstDC = GetImageHDC();
		HDC srcDC = GetImageHDC(&tmp);
		
		TransparentBlt(dstDC,
						p->x,
						p->y,
						tmp.getwidth(),
						tmp.getheight(),
						srcDC, 0, 0,
						tmp.getwidth(),
						tmp.getheight(),
						0x000000);

		if (p->x < 0)
		{
			p->x += rand() % 5 + 10;
		}
		else if (p->x > SCREEN_W)
		{
			p->x -= rand() % 5 - 10;
		}
		else
		{
			p->x += rand() % 10 - 5;
		}

		if (p->y <= 0)
		{
			p->y += rand() % 5 + 10;
		}
		else if (p->y >= SCREEN_W)
		{
			p->y -= rand() % 5 - 10;
		}
		else
		{
			p->y += rand() % 10 - 5;
		}
	}

	return 0;
}

int fish_add(GAME &game, int num, int SCREEN_W, int SCREEN_H)
{
	game.fish = (FISH*)malloc(sizeof(FISH));
	game.fish->next = NULL;
	FISH *temp = game.fish;
	game.fish->y = rand() % SCREEN_H;
	if (rand() % 2)
	{
		game.fish->x = SCREEN_W;
	}
	else
	{
		game.fish->x = 0;
	}
	for (int i = 0; i < num - 1; i++)
	{
		//	Allocate the memory
		FISH *_fish = (FISH*)malloc(sizeof(FISH));
		temp->next = _fish;
		//	Setting the relationship
		_fish->next = NULL;
		temp = _fish;
		//	Intiating the fish object
		//loadimage(&(_fish->img), _T("IMAGE"), _T("GAME_FISH_01"));
		_fish->y = rand() % SCREEN_H;
		if (rand() % 2)
		{
			_fish->x = SCREEN_W;
		}
		else
		{
			_fish->x = 0;
		}
	}
	return 0;
}

int fish_rm(FISH *head, FISH *fish)
{
	FISH *p = head, *q = head;
	while (p != NULL)
	{
		if (p == fish)
		{
			q->next = p->next;
			free(p);
			p = q->next;
			return 0;
		}
		q = p;
		p = p->next;
	}
	return -1;
}

int fish_clear(GAME &game)
{
	FISH *ptr = NULL, *ptr_b = NULL;
	while (game.fish->next != NULL)
	{
		for (ptr = game.fish; ptr->next != NULL; ptr = ptr->next)
		{
			ptr_b = ptr;
		}
		ptr_b->next = NULL;
		free(ptr);
	}
	free(game.fish);
	return 0;
}