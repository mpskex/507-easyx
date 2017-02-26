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
	int freq = 0;
	game.mouse.x = SCREEN_W / 2;
	game.mouse.y = SCREEN_H / 2;

	srand((unsigned)time(NULL));
	game.time_begin = time(NULL);
	//fish_add(game, 1000, SCREEN_W, 3*(int)(SCREEN_H / 4));

	RECT title_rect = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };
	FlushMouseMsgBuffer();
	Sleep(5);
	while (1)
	{
		if (game.fish == NULL) fish_init(game, SCREEN_W, SCREEN_H);
		if (freq % 100 == 0)fish_add(game, 2, SCREEN_W, 3 * (int)(SCREEN_H / 4));
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
		
		fish_judge(game, SCREEN_W, SCREEN_H);

		game_background_single(game, SCREEN_W, SCREEN_H);
		fish_single(game, SCREEN_W, 3 * (int)(SCREEN_H / 4));
		game_player_single(game, 2, SCREEN_W, 3 * (int)(SCREEN_H / 4));

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

		freq++;
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
	outtextxy(2 * (int)(SCREEN_W / 4), 5 * (int)(SCREEN_H / 6), (wchar_t)(((game.time_sec - game.time_begin) / 10 )% 10  + 48));
	outtextxy(2 * (int)(SCREEN_W / 4) + 15, 5 * (int)(SCREEN_H / 6), (wchar_t)((game.time_sec - game.time_begin) % 10 + 48));

	//	Score
	outtextxy((int)(SCREEN_W / 4), 3 * (int)(SCREEN_H / 4), _T("Score: "));
	outtextxy((int)(SCREEN_W / 4)	  , 5 * (int)(SCREEN_H / 6), (wchar_t)((game.score / 1000) % 10 + 48));
	outtextxy((int)(SCREEN_W / 4) + 15, 5 * (int)(SCREEN_H / 6), (wchar_t)((game.score / 100) % 10 + 48));
	outtextxy((int)(SCREEN_W / 4) + 30, 5 * (int)(SCREEN_H / 6), (wchar_t)((game.score / 10) % 10 + 48));
	outtextxy((int)(SCREEN_W / 4) + 45, 5 * (int)(SCREEN_H / 6), (wchar_t)(game.score % 10 + 48));

	//-------------------Time Box-----------------------


#ifdef DEBUG
	settextstyle(12, 0, _T("SYSTEM"));
	outtextxy(0, 0, _T("DEBUG MODE"));
	outtextxy(0, 20, _T("x:"));
	outtextxy(45, 20, (wchar_t)(game.mouse.x % 10 + 48));
	outtextxy(35, 20, (wchar_t)((game.mouse.x / 10) % 10 + 48));
	outtextxy(25, 20, (wchar_t)((game.mouse.x / 100) % 10 + 48));
	outtextxy(15, 20, (wchar_t)((game.mouse.x / 1000) % 10 + 48));
	outtextxy(0, 40, _T("y:"));
	outtextxy(45, 40, (wchar_t)(game.mouse.y % 10 + 48));
	outtextxy(35, 40, (wchar_t)((game.mouse.y / 10) % 10 + 48));
	outtextxy(25, 40, (wchar_t)((game.mouse.y / 100) % 10 + 48));
	outtextxy(15, 40, (wchar_t)((game.mouse.y / 1000) % 10 + 48));
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

int game_player_single(GAME &game, float level, int SCREEN_W, int SCREEN_H)
{
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(&game.player_fish);

	TransparentBlt(dstDC, 
					game.mouse.x - (int)(level * game.player_fish.getwidth() / 2),
					game.mouse.y - (int)(level * game.player_fish.getheight() / 2),
					(int)(level * game.player_fish.getheight()), 
					(int)(level * game.player_fish.getheight()), 
					srcDC, 0, 0, 
					game.player_fish.getwidth(), 
					game.player_fish.getheight(), 
					0x000000);
	return 0;
}

int fish_judge(GAME &game, int SCREEN_W, int SCREEN_H)
{
	FISH *p, *p_t = NULL;
	for (p = game.fish; p != NULL; p = p->next)
	{
		if	  ((p->x + (game.npc_fish.getwidth() / 2) <= game.mouse.x + (3 * game.player_fish.getwidth() / 8) &&
				p->x + (game.npc_fish.getwidth() / 2) >= game.mouse.x - (3 * game.player_fish.getwidth() / 8) &&
				p->y + (game.npc_fish.getheight() / 2) <= game.mouse.y + (3 * game.player_fish.getheight() / 8) &&
				p->y + (game.npc_fish.getheight() / 2) >= game.mouse.y - (3 * game.player_fish.getheight() / 8)))
		{
			p = fish_rm(game, p);
			game.score++;
			return 1;
		}
		else if (p->x > SCREEN_W + 100 || p->x < -100 || p->y > SCREEN_H + 100 || p->y < -100)
		{
			p = fish_rm(game, p);
			return 1;
		}
	}
	return 0;
}


int fish_single(GAME &game, int SCREEN_W, int SCREEN_H)
{
	FISH *p, *p_t = NULL;
	IMAGE tmp;
	tmp = game.npc_fish;
	//srand((unsigned)time(NULL));
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(&tmp);
	if (game.fish != NULL)
	{
		for (p = game.fish; p != NULL; p = p->next)
		{

			TransparentBlt(dstDC,
							(int)(p->x),
							(int)(p->y),
							(p->level/2) * tmp.getwidth(),
							(p->level/2) * tmp.getheight(),
							srcDC, 0, 0,
							tmp.getwidth(),
							tmp.getheight(),
							0x000000);

			if (p->x < 100)
			{
				p->x += rand() % 5 ;
			}
			else if (p->x > SCREEN_W - 100)
			{
				p->x -= rand() % 5;
			}
			else
			{
				if (p->flag == 2)
				{
					p->x += rand() % 20 / 10;
				}
				else if (p->flag == 1)
				{
					p->x -= rand() % 20 / 10;
				}
			}

			if (p->y <= 10)
			{
				p->y += 5;
			}
			else if (p->y >= 2 * SCREEN_H / 3)
			{
				p->y -= 10;
			}
			else
			{
				if (p->flag == 2)
				{
					p->y += rand() % 20 / 10 - 1;
				}
				else if (p->flag == 1)
				{
					p->y -= rand() % 20 / 10 - 1;
				}
			}
		}

	}

	return 0;
}

int fish_init(GAME &game, int SCREEN_W, int SCREEN_H)
{
	game.fish = (FISH*)malloc(sizeof(FISH));
	game.fish->next = NULL;
	game.fish->y = rand() % SCREEN_H;
	if (rand() % 2)
	{
		game.fish->x = SCREEN_W;
	}
	else
	{
		game.fish->x = 0;
	}
	return 0;
}

int fish_add(GAME &game, int num, int SCREEN_W, int SCREEN_H)
{
	FISH *temp;

	for (temp = game.fish; temp->next != NULL; temp = temp->next);

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
		_fish->level = rand() % 3 + 1 + game.score / 100;
		if (rand() % 2)
		{
			_fish->x = SCREEN_W;
			_fish->flag = 1;
		}
		else
		{
			_fish->x = 0;
			_fish->flag = 2;
		}
	}
	return 0;
}

FISH *fish_rm(GAME &game, FISH *fish)
{
	FISH *p = game.fish, *q = game.fish;
	while (p != NULL)
	{
		if (p == fish)
		{
			if (p == game.fish)
			{
				game.fish = p->next;
			}
			q->next = p->next;
			free(p);
			p = q->next;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
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