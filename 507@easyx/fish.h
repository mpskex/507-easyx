#pragma once
typedef struct fish
{
	float x;				//	Node fish's position in X
	float y;				//	Node fish's position in Y
	float s_x;				//	Node fish's speed in X
	float s_y;				//	Node fish's speed in Y
	float level;			//	Node fish's level(judge score or hurt)

	int res_num;			//	Alternate texture amount
	int flag;				//	From Left or Right
	fish *next;				//	Pointer to next
}FISH;
