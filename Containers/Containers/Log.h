#ifndef __LOG__
#define __LOG__

#include <Windows.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__)

void log(const char file[], int line, const char* format);

#endif // !__LOG__