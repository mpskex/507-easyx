#pragma once
#define	DEBUG


#ifdef DEBUG
	#define DEV				"DEBUG"
	#define VERSION			"1.0.1"
	#define BUILD			"build_1704190129_DEBUG_WinXP"
	#define DEBUG
	#define SHOW_VER
	#define SHOW_INTRO
#endif

#ifdef RELEASE
	#define DEV				"RELEASE"
	#define VERSION			"1.0.1"
	#define BUILD			"build_1704190129_WinXP"
	#define SHOW_VER
	#define SHOW_INTRO
#endif