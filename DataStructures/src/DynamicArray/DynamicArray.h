#pragma once

#include "../Utils.h"
#include "DynamicArrayUtils.h"

#define REALLOC_SIZE 16

namespace GitGud::DataStructures
{
	template<class T>
	class DynamicArray
	{
	public:
		using ValueType = T;
		using TypePtr = T*;
		using ConstTypePtr = const T*;
		using TypeRef = T&;
		using ConstTypeRef = const T&;

	public:
		DynamicArray() : _data(nullptr), _size(0), _capacity(0)
		{
			_size = _capacity = REALLOC_SIZE;
			_data = new T[_size];

			// TODO: Should use realloc instead
			//Realloc();
		}

		~DynamicArray()
		{
			_size = _capacity = 0;
			delete[] _data;
		}

		constexpr size_t Size() const { return _size; }
		constexpr size_t MaxSize() const { return _capacity; }

		constexpr TypePtr Data() { return _data };
		constexpr ConstTypePtr Data() const { return _data };

		constexpr TypeRef operator[] (SizeType index) noexcept
		{
			GG_ASSERT(index < _size, "Index out of bounds");
			return _data[index];
		}

		constexpr ConstTypePtr operator[] (SizeType index) const noexcept
		{
			GG_ASSERT(index < _size, "Index out of bounds");
			return _data[index];
		}

		void PushBack(T element)
		{
			if (_size == _capacity)
				Realloc();

			_data[_size++] = element;
		}

	private:
		void Realloc(size_t reallocSize = REALLOC_SIZE)
		{

		}

	private:
		TypePtr _data;
		size_t _size;
		size_t _capacity;
	};
}
