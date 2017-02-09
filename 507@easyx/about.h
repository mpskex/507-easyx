#pragma once
#include <conio.h>
#include <Windows.h>
#include <graphics.h>

#include <button.h>

typedef struct about
{
	IMAGE bk;
} ABOUT;

void about_loop(ABOUT about, int SCREEN_W, int SCREEN_H);
