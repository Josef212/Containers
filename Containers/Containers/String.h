#ifndef __STRING__
#define __STRING__

#define SMALL_STRING 16
#define MID_STRING 32
#define BIG_STRING 64

#include "Globals.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

class String
{
public:
	/** Empty constructor. */
	String()
	{
		alloc(SMALL_STRING);
		str[0] = '\0';
		length = 0;
	}

	/** Alloc size constructor. */
	String(uint allocSize)
	{
		alloc(allocSize);
		str[0] = '\0';
		length = 0;
	}

	/** Format constructor. */
	String(const char* format, ...)
	{
		size = 0;
		if (format != nullptr)
		{
			char tmp[4096];
			va_list ap;
			va_start(ap, format);
			int len = vsprintf_s(tmp, 4096, format, ap);
			va_end(ap);

			if (len > 0)
			{
				length = len;
				alloc(length + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			alloc(SMALL_STRING);
			str[0] = '\0';
			length = 0;
		}
	}

	/** Copy constructor. */
	String(const String& tmp)
	{
		alloc(tmp.size);
		strcpy_s(str, size, tmp.str);
	}

//------------------------------------------------------------

	/** Destructor. */
	~String()
	{
		clear();
		RELEASE_ARRAY(str);
	}

	/** Clear the string, don't release the buffer. */
	void clear()
	{
		str[0] = '\0';
		length = 0;
	}

//------------------------------------------------------------

	/** Length getter. */
	uint getLength()const { return length; }

	/** Size getter. */
	uint getCapacity()const { return size; }

	/** String getter. */
	const char* getString()const { return str; }

//------------------------------------------------------------
	/** Basic overload operators. */

	/** Returns true if string is equal to given char*. */
	bool operator== (const char* tmp)
	{
		return (strcmp(str, tmp) == 0);
	}

	/** Returns true if string is equal to given string. */
	bool operator== (String tmp)
	{
		return (strcmp(str, tmp.str) == 0);
	}

	//------------

	/** Returns true if string is diferent to given char*. */
	bool operator!= (const char* tmp)
	{
		return (strcmp(str, tmp) != 0);
	}

	/** Returns true if string is diferent to given string. */
	bool operator!= (String tmp)
	{
		return (strcmp(str, tmp.str) != 0);
	}

	//------------

	/** Asign given char to string and returns it. */
	String operator= (const char* tmp)
	{
		if (tmp != nullptr)
		{
			length = strlen(tmp);
			if (length >= size)
			{
				alloc(length + SMALL_STRING);
			}

			clear();
			strcpy_s(str, size, tmp);
		}
		else
			clear();

		return (*this);
	}

	/** Asign given string to string and returns it. */
	String operator= (const String& tmp)
	{
		length = tmp.length;
		if (length >= size)
		{
			alloc(length + SMALL_STRING);
		}
		clear();
		strcpy_s(str, size, tmp.str);
		return (*this);
	}

	//------------

	/** Add givent char* at the end of the string and return the string. */
	String operator+=(const char* tmp)
	{
		if (tmp != nullptr)
		{
			length += strlen(tmp);
			if (length >= size)
				alloc(length + SMALL_STRING);

			strcat_s(str, size, tmp);
		}

		return (*this);
	}

	/** Add givent string at the end of the string and return the string. */
	String operator+= (const String& tmp)
	{
		length += tmp.length;
		if (length >= size)
			alloc(length + SMALL_STRING);

		strcat_s(str, size, tmp.str);

		return (*this);
	}

//------------------------------------------------------------

	/** Add givent char* at the begining of the string and return the string. */
	String prefix(const char* tmp)
	{
		if (tmp != nullptr)
		{
			assert((length + strlen(tmp) + 1) < 4096);

			char sz[4096];
			strcpy_s(sz, 4096, tmp);
			strcat_s(sz, 4096, str);

			length += strlen(tmp);
			if (length >= size)
				alloc(length + SMALL_STRING);

			clear();

			strcpy_s(str, size, sz);
		}

		return (*this);
	}

	/** Add givent string at the begining of the string and return the string. */
	String prefix(const String& tmp)
	{
		assert((length + tmp.length + 1) < 4096);

		char sz[4096];
		strcpy_s(sz, 4096, tmp.str);
		strcat_s(sz, 4096, str);

		length += tmp.length;
		if (length >= size)
			alloc(length + SMALL_STRING);

		clear();

		strcpy_s(str, size, sz);

		return (*this);
	}

//------------------------------------------------------------

	/** Cut the string from "start" to "end" and returns the string. 
	If start is greater than string length or en is 0 clears the string. */
	String cut(uint start, uint end = 0)
	{
		if (start < length && end > 0 && end < size)
		{
			char* p = str + start;
			char* q = str + end + 1;

			while (*p++ = *q++);

			length = strlen(str);
		}

		if (end == 0 || start > length)
			clear();

		return (*this);
	}

//------------------------------------------------------------

private:
	/** Redimension de char buffer and copy old data. */
	void alloc(uint newSize)
	{
		if (newSize < 1)
		{
			LOG("String: Trying to alloc 0 mem size.");
			return;
		}

		size = newSize;
		char* tmp = new char[size];
		if (str != nullptr)
			strcpy_s(tmp, size, str);
		RELEASE_ARRAY(str);
		str = tmp;
	}

private:
	/** Char pointer of the string. */
	char* str = nullptr;
	/** Length of the string, ammount of characters(\0 not included). */
	uint length = 0;
	/** Size of the char buffer. */
	uint size = 0;

};


#endif // !__STRING__
