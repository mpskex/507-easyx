#pragma once
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#include <button.h>

#define MENU_QUIT		1000
#define MENU_NEWGAME	1001
#define MENU_RESUME		1002
#define MENU_CHAPT		1003
#define MENU_ABOUT		1004

// Menu

typedef struct menu
{
	int select;
	IMAGE bk;
	BUTTON_FONT font;
} MENU;

int menu_loop(MENU menu, int SCREEN_W, int SCREEN_H);
int menu_button_single(int SCREEN_W, int SCREEN_H, int cursor);
