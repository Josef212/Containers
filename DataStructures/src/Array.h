#pragma once

#include "Utils.h"

namespace GiGud::DataStructures
{
	template<class T, size_t _size>
	class Array
	{
	public:
		using ValueType = T;
		using SizeType = size_t;
		using TypePtr = T*;
		using ConstTypePtr = const T*;
		using TypeRef = T&;
		using ConstTypeRef = const T&;

		// TODO: Iterators types

	public:
		constexpr size_t Size() const { return _size; }
		constexpr size_t MaxSize() const { return _size; }

		TypePtr Data() const { return _data; }
		//constexpr T* Data() const { return _data; }

		TypeRef operator[] (SizeType index)
		{
			GG_ASSERT(index < _size, "Index out of bounds");
			return _data[index];
		}

		constexpr ConstTypePtr operator[] (SizeType index) const
		{
			GG_ASSERT(index < _size, "Index out of bounds");
			return _data[index];
		}

		// TODO: Iterators

	private:
		T _data[_size];
	};
}
