#ifndef __VECTOR__
#define __VECTOR__

#define SMALL_MEM_BLOCK_SIZE 16
#define MEDDIUM_MEM_BLOCK_SIZE 32
#define BIG_MEM_BLOCK_SIZE 64
#define HUGE_MEM_BLOCK_SIZE 128

#include "Globals.h"
#include <assert.h>

template<class TYPE>
class Vector
{
public:
	/** Empty constructor. Preallocate small array. */
	Vector()
	{
		if (data == nullptr)
		{
			capacity = SMALL_MEM_BLOCK_SIZE;
			length = 0;
			data = new TYPE[capacity];
		}
	}

	/** Constructor that allocate demanded ammount. */
	Vector(int allocateSize)
	{
		assert(allocateSize > 0);
		if (data == nullptr)
		{
			capacity = allocateSize;
			length = 0;
			data = new TYPE[allocateSize];
		}
	}

private:
	/** Redimension the array and copy the current data. */
	void alloc(int size)
	{
		assert(size > 0);

	}

private:
	/** The actual array of data type. */
	TYPE* data = nullptr;

	/** Current ammount of data. May not be the array capacity but never more. */
	int length = 0;

	/** Current array capacity. May not be same as the array length but never less. */
	int capacity = 0;

};

#endif // !__VECTOR_H__
