#include <main.h>

#pragma comment( lib, "MSIMG32.LIB")

//#define DEBUG
//#define ALPHA
// Home work of Liu Fangrui @ 2017 02


int main(void)
{
	// Define the Screen's Width and Height
	int SCREEN_W = 1024, SCREEN_H = 576;
	initgraph(SCREEN_W, SCREEN_H);
	/* This part only be compiled in alpha or released version */
#ifdef ALPHA
	{
		// the Intro
		INTRO intro;
		// Do the Intro code
		intro_loop(intro, SCREEN_W, SCREEN_H);
		// Clear the input buffer
	}
#endif
	// We want a white background
	setbkcolor(WHITE);
	// Clear the whole clip
	clearcliprgn();
	// assign space for the Menu struct
	MENU menu;
	// Into the main loop
	while (1)
	{ 
		clearcliprgn();
		// Get the selected option from the loop return
		menu.select = menu_loop(menu, SCREEN_W, SCREEN_H);
		// Switch the cases with the return value
		switch (menu.select)
		{
		// New game
		case MENU_NEWGAME:
		{
			GAME game;
			// Initiate the object resources
			clearcliprgn();
			game_main(game, SCREEN_W, SCREEN_H);
			clearcliprgn();
			break;
		}
		case MENU_OPTION:
		{
			OPTION option;
			option_loop(option, SCREEN_W, SCREEN_H);
			break;
		}
		// About
		case MENU_ABOUT:
		{
			ABOUT about;
			about_loop(about, SCREEN_W, SCREEN_H);
			break;
		}
		// Exit
		case MENU_QUIT:
		{
			closegraph();
			return 0;
		}
		}
	}

}
