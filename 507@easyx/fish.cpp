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

FISH* fish_add(int num, int SCREEN_W, int SCREEN_H)
{
	int i;
	FISH *temp = NULL;
	FISH *head = NULL;

	for (i = 0; i < num - 1; i++)
	{
		//	Allocate the memory
		FISH *_fish = (FISH*)malloc(sizeof(FISH));
		temp = _fish;
		if (head == NULL)
		{
			head = _fish;
		}
		//	Setting the relationship
		temp->next = _fish;
		_fish->next = NULL;
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
	return head;
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