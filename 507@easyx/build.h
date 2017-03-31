#pragma once
#define	RELEASE


#ifdef DEBUG
	#define DEV				"BETA"
	#define VERSION			"0.9.1"
	#define DEBUG
#endif

#ifdef RELEASE
	#define DEV				"ALPHA"
	#define VERSION			"0.9.1"
	#define DEBUG
	#define ALPHA
#endif