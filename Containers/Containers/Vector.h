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
			_capacity = SMALL_MEM_BLOCK_SIZE;
			_length = 0;
			data = new TYPE[_capacity];
		}
	}

	/** Constructor that allocate demanded ammount. */
	Vector(int allocateSize)
	{
		assert(allocateSize > 0);
		if (data == nullptr)
		{
			_capacity = allocateSize;
			_length = 0;
			data = new TYPE[_capacity];
		}
	}

	/** Copy constructor. */
	Vector(Vector& vec)
	{
		if (data == nullptr)
		{
			_capacity = vec._capacity;
			if (_capacity > 0)
			{
				data = new TYPE[_capacity];
				
				if (vec.data != nullptr)
				{
					_length = vec._length;
					memcpy(data, vec.data, sizeof(data));
				}
			}
			else
			{
				_capacity = 0;
				_length = 0;
			}
		}
	}

	/** Destructor. */
	~Vector()
	{
		RELEASE_ARRAY(data);
		_length = 0;
		_capacity = 0;
	}

	//======================================================================================

	const TYPE& operator[](int index)const
	{
		assert(index >= 0 && index < capacity);
		return  data[index];
	}

	TYPE& operator[](int index)
	{
		assert(index >= 0 && index < capacity);
		return  data[index];
	}

	void operator+=(const Vector<TYPE>& vec)
	{
		uint size = _length + vec._length;

		if (size > _capacity)
			alloc(size + SMALL_MEM_BLOCK_SIZE);

		for (uint i = 0; i < _vec._legth; ++i)
		{
			data[i + _length] = vec.data[i];
			++_length;
		}
	}

	//======================================================================================

	void pushBack(TYPE& value)
	{
		if (_length + 1 > _capacity)
			alloc(_length + SMALL_MEM_BLOCK_SIZE);

		data[_length++] = value;
	}

	//======================================================================================



	/** Reduce the vector length to 0 and sets the buffer to 0. */
	void clear()
	{
		_length = 0;
		memset(data, 0, sizeof(data));
	}

	//---------------------------
	//--------		-------------
	//---------------------------

	int length()const
	{
		return _length;
	}

	int capacity()const
	{
		return _capacity;
	}

	TYPE* ptr()
	{
		return data;
	}

private:
	/** Redimension the array and copy the current data. */
	void alloc(int size)
	{
		assert(size > 0);

		_capacity = size;

		TYPE* tmp = new TYPE[_capacity];

		if (data != nullptr)
			memcpy(tmp, data, sizeof(data));

		RELEASE_ARRAY(data);
		data = tmp;
	}

private:
	/** The actual array of data type. */
	TYPE* data = nullptr;

	/** Current ammount of data. May not be the array capacity but never more. */
	int _length = 0;

	/** Current array capacity. May not be same as the array length but never less. */
	int _capacity = 0;

};

#endif // !__VECTOR_H__
