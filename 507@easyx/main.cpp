#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>


#define DEBUG
// Home work of Liu Fangrui @ 2017 02 07

#ifdef DEBUG
int main(void)
{
	float i = 0;
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, _T("menu.jpg"));
	setbkcolor(WHITE);
	while (i < img.getwidth())
	{
		for (int m = -img.getwidth(); m < 640 + img.getwidth(); m += 2*img.getwidth())
		{
			for (int n = 0; n < 480; n += 2*img.getheight())
			{
				putimage(m-i, n, &img);
			}
		}
		for (int m = 0; m < 640 + img.getwidth(); m += 2 * img.getwidth())
		{
			for (int n = img.getheight(); n < 480; n += 2 * img.getheight())
			{
				putimage(m-i, n, &img);
			}
		}
		//putimage(i + img.getwidth(), img.getheight(), &img);
		i += 0.5;
		if (i >= img.getwidth()) i = -img.getwidth();
		Sleep(10);
		cleardevice();
	}
	getchar();
	closegraph();
	return 0;
}

#endif

#ifndef DEBUG
int main(void)
{
	float i = 0;
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, _T("menu.jpg"));
	while (i < 640)
	{
		putimage(i, 0, &img);
		i += 0.1;
		if (i >= 640) i = 0;
		Sleep(10);
		cleardevice();
	}
	getchar();
	closegraph();
	return 0;
}
#endif