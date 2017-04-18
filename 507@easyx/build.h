#pragma once
#define	RELEASE


#ifdef DEBUG
	#define DEV				"DEBUG"
	#define VERSION			"1.0.1"
	#define BUILD			"build_1704190028"
	#define DEBUG
	#define SHOW_VER
	#define SHOW_INTRO
#endif

#ifdef RELEASE
	#define DEV				"RELEASE"
	#define VERSION			"1.0.1"
	#define BUILD			"build_1704190031_WinXP"
	#define SHOW_VER
	#define SHOW_INTRO
#endif