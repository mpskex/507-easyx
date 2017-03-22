#pragma once
#include <stdio.h>
//	Setting :
//	SCREEN_W	SCREEN_H	mode	speed_ratio
typedef struct Save
{
	FILE *file;
	int level;
	int score;
	int time;
} SAVE;

typedef struct Setting
{
	int SCREEN_W = 1024;		// Option only
	int SCREEN_H = 576;			// Option only
	int	mode = 2;
	int speed_ratio = 20;
}SETTING;

int load_setting(SETTING &setting);
int write_setting(SETTING setting);
int init_setting(SETTING &setting);