#pragma once
#include <graphics.h>
#include <tchar.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 25

typedef struct game
{
	wchar_t *player = NULL;
	IMAGE player_fish;
}GAME;

//	Player input name;
int name_loop(GAME game, int SCREEN_W, int SCREEN_H);
//	Game loop
int game_loop(GAME game, int SCREEN_W, int SCREEN_H);
//	single small module 
int game_status_single(GAME game, int SCREEN_W, int SCREEN_H);
int game_content_single(GAME game, int SCREEN_W, int SCRREN_H);

int game_player_single(GAME game, int x, int y, int SCREEN_W, int SCREEN_H);
