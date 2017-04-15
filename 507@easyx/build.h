#pragma once
#define	DEBUG


#ifdef DEBUG
	#define DEV				"DEBUG"
	#define VERSION			"1.0.0"
	#define DEBUG
	#define SHOW_VER
	#define SHOW_INTRO
#endif

#ifdef RELEASE
	#define DEV				"RELEASE"
	#define VERSION			"1.0.0"
	#define SHOW_VER
	#define SHOW_INTRO
#endif