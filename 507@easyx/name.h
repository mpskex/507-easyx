#pragma once
#include <graphics.h>
#include <tchar.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 25




typedef struct name
{
	wchar_t *str;
}NAME;

int name_loop(NAME name, int SCREEN_W, int SCREEN_H);