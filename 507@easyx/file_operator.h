#pragma once
#include <fish.h>
#include <pearl.h>

#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#define	BUFFSIZE	25
//	Setting :
//	SCREEN_W	SCREEN_H	mode	speed_ratio
typedef struct Save
{
	wchar_t		*player = NULL;
	float		level = 1.0;
	int			score = 0;
	int			time = 0;
	FISH		*fish = NULL;
	PEARL		pearl;
} SAVE;

typedef struct Setting
{
	int SCREEN_W = 1024;		// Option only
	int SCREEN_H = 576;			// Option only
	int	mode = 2;
	int speed_ratio = 20;
}SETTING;

int load_setting(SETTING &setting);
int write_setting(SETTING &setting);

int write_save(SAVE *save);
int load_save(SAVE &save);

void TcharToChar(const TCHAR * tchar, char * _char);
void CharToTchar(const char * _char, TCHAR * tchar);