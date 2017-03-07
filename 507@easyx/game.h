#pragma once
#include <graphics.h>
#include <tchar.h>
#include <conio.h>
#include <Windows.h>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//	DEBUG SWITCH
//------MOVE-----
//#define POS_RAND
#define SPD_RAND
//---------------
//------VER------
#define SHOW_VER
//---------------

#ifdef SPD_RAND
	#define SPD_MAX			5
	#define SPD_MAX_X		5
	#define SPD_MAX_Y		5
	#define SPD_DEC			0.05
	#define SPD_MIN			0.3
	#define SPD_RATIO		3
	#define SPD_INIT_RAND_Y	
#endif

#define BUFFSIZE 		25
#define RES_FISHES 		4
#define TIME			3
#define GAME_TIME		99
#define GOD_TIME		50
#define FISH_FREQ		50		// Bigger is less
#define FISH_QUAT		2

typedef struct fish
{
	//IMAGE img[300];
	float x;
	float y;
	float s_x;
	float s_y;
	float level;

	int res_num;
	int flag;
	fish *next;
}FISH;

typedef struct game
{
	wchar_t		*player;
	int			time_begin, time_sec;
	int			score = 0;
	bool		god;
	float			level;

	MOUSEMSG	mouse;

	IMAGE		npc_fish;
	IMAGE		npc_fishes[RES_FISHES];
	IMAGE		player_fish;
	IMAGE		background;
	FISH		*fish = NULL;
}GAME;

//	Game main
int game_main(GAME &game, int SCREEN_W, int SCREEN_H);


//	Player input name;
int name_loop(GAME &game, int SCREEN_W, int SCREEN_H);
//	Game loop
int game_loop(GAME &game, int SCREEN_W, int SCREEN_H);
//	single small module 
int game_status_single(GAME &game, int SCREEN_W, int SCREEN_H);
int game_background_single(GAME &game, int SCREEN_W, int SCRREN_H);
int game_player_single(GAME &game, int SCREEN_W, int SCREEN_H);
int game_score(GAME &game, int SCREEN_W, int SCREEN_H);

DWORD WINAPI game_lock_frame();

int fish_init(GAME &game, int SCREEN_W, int SCREEN_H);
int fish_add(GAME &game, int num, int SCREEN_W, int SCREEN_H);
int fish_judge(GAME &game, int SCREEN_W, int SCREEN_H);
FISH *fish_rm(GAME &game, FISH *fish);
int fish_single(GAME &game, int SCREEN_W, int SCREEN_H);
int fish_clear(GAME &game);

int res_fishes_load(GAME &game);
int res_fishes_clear(GAME &game);