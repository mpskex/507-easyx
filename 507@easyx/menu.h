#pragma once
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define DEBUG

// Menu

typedef struct menu
{
	IMAGE bk;
	LOGFONT title;
	LOGFONT newgame;
	LOGFONT resume;
	LOGFONT chapt;
	LOGFONT option;
	LOGFONT exit;
} MENU;

void menu_loop(MENU menu, int SCREEN_W, int SCREEN_H);
