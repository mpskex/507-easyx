#include <intro.h>

void intro_loop(INTRO intro, int SCREEN_W, int SCREEN_H)
{
	// The pointer handle image by pixels
	DWORD* pbWnd = GetImageBuffer();
	DWORD* pbImg = GetImageBuffer(&(intro.bk));

	int r, g, b;
	// Dark -> Bright
	for (int light = 1; light <= 64; light++)
	{
		// for 64 level lights
		for (int i = 0; i < (intro.bk).getheight(); i++)
		{
			for (int j = 0; j < (intro.bk).getwidth(); j++)
			{
			// travel all pixels on the image
				// Binary operations:
				// First get the gray-level-value from the image
				// Then multiply it with light value 
				// In decimal sys we have to divide it into 64
				// But it would ignore lots of info after the dividing operation
				// So here we move the value by 6
				// It is the same to dividing with 64(2^6)
				r = (int)(GetRValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				g = (int)(GetGValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				b = (int)(GetBValue(pbImg[i*(intro.bk).getwidth() + j]) * light >> 6);
				pbWnd[(SCREEN_H/2 - (intro.bk).getheight()/2 + i)*SCREEN_W + j + SCREEN_W/2 - (intro.bk).getwidth()/2] = RGB(r, g, b);
			}
		}
		FlushBatchDraw();
		Sleep(50);
	}
	// Bright -> Dark
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
		// Clear the input buffer
		if (_kbhit()) _getch();
		FlushBatchDraw();
		Sleep(50);
	}
}
