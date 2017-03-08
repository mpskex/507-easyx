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
//#define POS_RAND		//	NPC_Moving mode (position based)
#define SPD_RAND		//	NPC_Moving mode (speed based)
//---------------
//------VER------
#define SHOW_VER		//	Show the Version Information(for Debug)
//---------------

#ifdef SPD_RAND
	#define SPD_MAX			5
	#define SPD_MAX_X		5			//	Maxium Speed in X axis
	#define SPD_MAX_Y		5			//	Maxium Speed in Y axis
	#define SPD_DEC			0.05		//	Step value (Constant accelerate rate in abstract game time)
	#define SPD_MIN			0.3			//	Minimal Speed
	#define SPD_RATIO		1			//	Time Ratio (to enbalance the difficulty)
	#define SPD_INIT_RAND_Y	
#endif

#define BUFFSIZE 		25		//	buffsize for string
#define RES_FISHES 		4		//	Amount of the npc fishes
#define TIME			3
#define GAME_TIME		99		//	sec
#define LOCK_RATE		10		//	ms
#define GOD_TIME		50		//	ms
#define FISH_FREQ		10		//	Triggered every XX ms
#define FISH_QUAT		2		//	Push XX fishes every time

typedef struct fish
{
	//IMAGE img[300];
	float x;				//	Node fish's position in X
	float y;				//	Node fish's position in Y
	float s_x;				//	Node fish's speed in X
	float s_y;				//	Node fish's speed in Y
	float level;			//	Node fish's level(judge score or hurt)

	int res_num;			//	Alternate texture amount
	int flag;				//	From Left or Right
	fish *next;				//	Pointer to next
}FISH;

typedef struct game
{
	//	mode 0 for rand position based
	//	mode 1 for rand speed based
	//	other is for rand speed without y
	int			mode = 2;
	int			speed_ratio = 1;

	wchar_t		*player;					//	Player's name
	int			time_begin, time_sec;		//	Timer for count Game time
	int			score = 0;					//	Score
	bool		god;						//	GOD Flag
	float		level;						//	Player's level

	MOUSEMSG	mouse;						//	Mouse Message
				
	IMAGE		npc_fishes[RES_FISHES];		//	NPC Texture Array
	IMAGE		player_fish;				//	Player's fish texture
	IMAGE		background;					//	Background Texture
	FISH		*fish = NULL;				//	Head of NPC chain list
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

//	Functions control fishes
int fish_init(GAME &game, int SCREEN_W, int SCREEN_H);
int fish_add(GAME &game, int num, int SCREEN_W, int SCREEN_H);
int fish_judge(GAME &game, int SCREEN_W, int SCREEN_H);
FISH *fish_rm(GAME &game, FISH *fish);
int fish_single(GAME &game, int SCREEN_W, int SCREEN_H);
int fish_clear(GAME &game);

int res_fishes_load(GAME &game);
int res_fishes_clear(GAME &game);