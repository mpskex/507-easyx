#pragma once
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#include <menu_button.h>


// Menu

typedef struct menu
{
	IMAGE bk;
	BUTTON_FONT font;
} MENU;

void menu_loop(MENU menu, int SCREEN_W, int SCREEN_H);
