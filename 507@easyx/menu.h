#pragma once
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#include <button.h>
#include <file_operator.h>
#define DEV				"DEBUG"
#define VERSION			"0.8.2"

//	DEBUG SWITCH
//------VER------
#define SHOW_VER
//---------------

//-------MESSAGES-----------
#define MENU_QUIT		1000
#define MENU_NEWGAME	1001
#define MENU_RESUME		1002
#define MENU_OPTION		1003
#define MENU_ABOUT		1004

// Menu

typedef struct menu
{
	int select;
	IMAGE bk;
	MOUSEMSG mouse;
} MENU;

int menu_loop(MENU &menu, int SCREEN_W, int SCREEN_H);
void menu_show_version(int SCREEN_W, int SCREEN_H);
