#include <fish.h>

int fish_single(FISH *head, int SCREEN_W, int SCREEN_H)
{
	FISH *p;
	for (p = head; p != NULL; p = p->next)
	{
		HDC dstDC = GetImageHDC();
		HDC srcDC = GetImageHDC(&(p->img));
		//HDC srcDC = GetImageHDC(img);

		TransparentBlt(dstDC, 
						p->x,
						p->y,
						(p->img).getwidth(), 
						(p->img).getheight(),
						srcDC, 0, 0, 
						(p->img).getwidth(),
						(p->img).getheight(),
						0x000000);

		/*
		TransparentBlt(dstDC,
						p->x,
						p->y,
						(*img).getwidth(),
						(*img).getheight(),
						srcDC, 0, 0,
						(*img).getwidth(),
						(*img).getheight(),
						0x000000);
		*/
		//FlushBatchDraw();
		if (p->x <= 0)
		{
			p->x += rand() % 5;
		}
		else if (p->x >=SCREEN_W)
		{
			p->x -= rand() % 5;
		}
		else
		{
			p->x += rand() % 6 - 3;
		}

		if (p->y <= 0)
		{
			p->y += rand() % 5;
		}
		else if (p->y >= SCREEN_W)
		{
			p->y -= rand() % 5;
		}
		else
		{
			p->y += rand() % 6 - 3;
		}
	}

	return 0;
}

int fish_init(FISH *fish)
{
	fish = (FISH*)malloc(sizeof(FISH));
	fish->next = NULL;
	return 0;
}

int fish_add(FISH *head, int num, int SCREEN_W, int SCREEN_H)
{
	FISH *temp = head;

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
		if (rand() % 1)
		{
			_fish->x = SCREEN_W;
		}
		else
		{
			_fish->y = 0;
		}
	}
	return 0;
}


int fish_rm(FISH *head, FISH *fish)
{
	FISH *p = head, *q = head;
	while(p != NULL)
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