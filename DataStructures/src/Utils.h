#pragma once

#include <assert.h>

#define GG_DEBUG_LEVEL 1

#if GG_DEBUG_LEVEL > 0
	// TODO: logging msg
	#define GG_ASSERT(x, msg) assert(x); 
#else
	#define GG_ASSERT(x, msg)
#endif