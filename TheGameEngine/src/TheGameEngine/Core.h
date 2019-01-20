#pragma once
#include "Core.h"

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define	ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#else
	#error TheGameEngine does not support this operating system
#endif