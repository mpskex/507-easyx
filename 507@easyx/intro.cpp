#include <intro.h>

void intro_loop(INTRO intro, int SCREEN_W, int SCREEN_H)
{

	DWORD* pbWnd = GetImageBuffer();
	DWORD* pbImg = GetImageBuffer(&(intro.bk));

	int r, g, b;
	for (int light = 1; light <= 64; light++)
	{
		for (int i = 0; i < (intro.bk).getheight(); i++)
		{
			for (int j = 0; j < (intro.bk).getwidth(); j++)
			{
				r = (int)(GetRValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				g = (int)(GetGValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				b = (int)(GetBValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				pbWnd[(SCREEN_H/2 - (intro.bk).getheight()/2 + i)*SCREEN_W + j + SCREEN_W/2 - (intro.bk).getwidth()/2] = RGB(r, g, b);
			}
		}
		FlushBatchDraw();
		Sleep(50);
	}
	for (int light = 64; light >= 1; light--)
	{
		for (int i = 0; i < (intro.bk).getheight(); i++)
		{
			for (int j = 0; j < (intro.bk).getwidth(); j++)
			{
				r = (int)(GetRValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				g = (int)(GetGValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				b = (int)(GetBValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				pbWnd[(SCREEN_H / 2 - (intro.bk).getheight() / 2 + i)*SCREEN_W + j + SCREEN_W / 2 - (intro.bk).getwidth() / 2] = RGB(r, g, b);
			}
		}
		FlushBatchDraw();
		Sleep(50);
	}
}
