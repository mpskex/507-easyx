#pragma once
#define	RELEASE


#ifdef DEBUG
	#define DEV				"BETA"
	#define VERSION			"1.0.1"
	#define DEBUG
#endif

#ifdef RELEASE
	#define DEV				"RELEASE"
	#define VERSION			"1.0.0"
	#define DEBUG
	#define ALPHA
#endif