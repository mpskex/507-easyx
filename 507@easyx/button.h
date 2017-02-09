#pragma once
#include <conio.h>
#include <Windows.h>
#include <graphics.h>

#define KEY_QUIT	-1
#define KEY_NONE	0
#define KEY_UP		1
#define KEY_DOWN	2
#define KEY_RIGHT	3
#define KEY_LEFT	4
#define KEY_ENTER	5


typedef struct button_font
{
	LOGFONT norm_font;
	LOGFONT sel_font;
} BUTTON_FONT;

