#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

typedef struct fish
{
	IMAGE img;
	int x;
	int y;
	fish *next;
}FISH;

int fish_init(FISH &(*fish));
int fish_add(FISH *head, int num, int SCREEN_W, int SCREEN_H);
int fish_rm(FISH *head, FISH *fish);
int fish_single(FISH *head, int SCREEN_W, int SCREEN_H);