#include <main.h>
#pragma comment( lib, "MSIMG32.LIB")


// Home work of Liu Fangrui @ 2017 02


int main(void)
{
	SETTING setting;
	load_setting(setting);
	// Define the Screen's Width and Height
	int SCREEN_W = setting.SCREEN_W, SCREEN_H = setting.SCREEN_H;
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
		PlaySound((LPCTSTR)IDR_WAVE_MENU, NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP);
		menu.select = menu_loop(menu, SCREEN_W, SCREEN_H);
		// Switch the cases with the return value
		switch (menu.select)
		{
		// New game
		case MENU_NEWGAME:
		{
			load_setting(setting);
			PlaySound((LPCTSTR)IDR_WAVE_NAME, NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP);
			GAME game;
			game.mode = setting.mode;
			game.speed_ratio = setting.speed_ratio;
			int _return = name_loop(game, SCREEN_W, SCREEN_H);
			// Initiate the object resources
			clearcliprgn();
			PlaySound((LPCTSTR)IDR_WAVE_GAME, NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP);
			game_main(game, _return, SCREEN_W, SCREEN_H);
			clearcliprgn();
			break;
		}
		case MENU_RESUME:
		{
			load_setting(setting);
			GAME game;
			game.mode = setting.mode;
			game.speed_ratio = setting.speed_ratio;
			int _return = load_game(game);
			if (_return == 0)
			{
				// Initiate the object resources
				clearcliprgn();
				PlaySound((LPCTSTR)IDR_WAVE_GAME, NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP);
				game_main(game, 0, SCREEN_W, SCREEN_H);
				clearcliprgn();
			}
			else
			{
				clearcliprgn();
				RECT title_rect = { 0, 0, SCREEN_W, 3 * SCREEN_H / 4 };
				settextcolor(BLACK);
				settextstyle(72, 0, _T("SYSTEM"));
				drawtext(_T("LOAD FILE FAILED!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				Sleep(1000);
			}
			break;
		}
		case MENU_OPTION:
		{
			OPTION option;
			option.setting = setting;
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
