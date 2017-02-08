#pragma once
#include <graphics.h>
#include <conio.h>

typedef struct intro
{
	IMAGE bk;
} INTRO;

void intro_loop(INTRO intro, int SCREEN_W, int SCREEN_H);
