#ifndef __GLOBALS__
#define __GLOBALS__

#include <Windows.h>
#include <stdio.h>

typedef unsigned int uint;

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__)

void log(const char file[], int line, const char* format, ...)
{
	static char tmpString[4096];
	static char tmpString2[4096];
	static va_list ap;

	va_start(ap, format);
	vsprintf_s(tmpString, 4096, format, ap);
	va_end(ap);
	sprintf_s(tmpString2, 4096, "%s(%d): %s\n", file, line, tmpString);
	OutputDebugString(tmpString2);

#ifdef _DEBUG
	printf(tmpString2);
#endif // _DEBUG
}

#define RELEASE( x )\
    {\
       if( x != nullptr )\
       {\
         delete x;\
	     x = nullptr;\
       }\
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x )\
	{\
       if( x != nullptr )\
       {\
           delete[] x;\
	       x = nullptr;\
		 }\
	 }

template<class TYPE>
void swap(TYPE& a, TYPE& b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

#define MIN(a, b) (a<b ? a:b)
#define MAX(a, b) (a>b ? a:b)

//uint factorial(uint n) { return (n > 0) ? (n*factorial(n - 1)) : 1; }

#endif // !__GLOBALS__