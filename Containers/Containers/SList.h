#ifndef __SLIST__
#define __SLIST__

#include "Globals.h"
#include <assert.h>

template<class TYPE>
struct s_node
{
	TYPE data;
	s_node<TYPE>* next = nullptr;

	inline s_node(TYPE& _data)
	{
		data = _data;
	}

	~s_node()
	{}
};

template<class TYPE>
class SList
{
public:
	SList()
	{}
	~SList()
	{

	}

	uint cout()
	{
		return size;
	}

	void pushBack(const TYPE& data)
	{
		s_node<TYPE>* tmp = new s_node(data);
		pushBack(tmp);
	}

	void pushBack(s_node<TYPE>* iterator)
	{
		if (start == nullptr)
		{
			start = last = iterator;
		}
		else
		{
			last->next = iterator;
			last = iterantor;
		}

		++size;
	}

	void pushFront(const TYPE& data)
	{
		s_node<TYPE>* tmp = new s_node(data);
		pushFront(tmp);
	}

	void pushFront(s_node<TYPE>* iterator)
	{
		if (start == nullptr)
		{
			start = last = iterator;
		}
		else
		{
			iterator->next = start;
			start = iterator;
		}

		++size;
	}

private:
	s_node<TYPE>* start = nullptr;
	s_node<TYPE>* last = nullptr;
	uint size = 0;
};

#endif // !__SLIST__