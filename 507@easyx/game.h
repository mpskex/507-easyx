#pragma once
#include <graphics.h>
#include <tchar.h>
#include <conio.h>
#include <Windows.h>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 25

typedef struct fishes
{
	IMAGE img;
	fishes *next_fish = NULL;
}FISHES;

typedef struct game
{
	wchar_t *player;
	MOUSEMSG mouse;
	IMAGE player_fish;
	FISHES *other_fish;
}GAME;

//	Player input name;
int name_loop(GAME game, int SCREEN_W, int SCREEN_H);
//	Game loop
int game_loop(GAME game, int SCREEN_W, int SCREEN_H);
//	Game main
int game_main(GAME game, int SCREEN_W, int SCREEN_H);
//	single small module 
int game_status_single(GAME game, int SCREEN_W, int SCREEN_H);
int game_background_single(GAME game, int SCREEN_W, int SCRREN_H);
int game_npc_single(GAME game, int SCREEN_W, int SCREEN_H);

int game_player_single(GAME game, int x, int y, float level, int SCREEN_W, int SCREEN_H);
int game_fish_single(GAME game, int x, int y, int level, int SCREEN_W, int SCREEN_H);