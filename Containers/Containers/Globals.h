#ifndef __GLOBALS__
#define __GLOBALS__

#include <Windows.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__)

void log(const char file[], int line, const char* format)
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

#define RELEASE(x) (x != nullptr) ? delete x; x = nullptr : 0
#define RELEASE_ARRAY(x) (x != nullptr) ? delete[] x; x = nullptr : 0

typedef unsigned int uint;

#endif // !__GLOBALS__