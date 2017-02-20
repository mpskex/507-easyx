#pragma once
#include <conio.h>
#include <Windows.h>
#include <graphics.h>

#include <button.h>

#include<math.h>
#include <stdio.h>
#include <stdlib.h>

#define OPTION_RESOLUTION   2001
#define OPTION_DIFFICULTY	2002

#define OPTION_640			0x11
#define OPTION_800			0x21
#define OPTION_1024			0x31

#define OPTION_EASY         0x12
#define OPTION_MEDUIM       0x22
#define OPTION_HARD         0x32
#define OPTION_EXTREM       0x42

typedef struct option
{

}OPTION;

int option_loop(OPTION option, int SCREEN_W, int SCREEN_H);