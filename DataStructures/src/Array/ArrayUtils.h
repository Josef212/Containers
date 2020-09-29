#pragma once

namespace GiGud::DataStructures
{
	template<class T, size_t _size>
	class ArrayIterator
	{
	public:
		using ValueType = T;
		using SizeType = size_t;
		using TypePtr = T*;
		using ConstTypePtr = const T*;
		using TypeRef = T&;
		using ConstTypeRef = const T&;

	public:
		ArrayIterator() : _ptr(nullptr), _index(0) { }
		explicit ArrayIterator(TypePtr ptr, size_t offset) : _ptr(ptr), _index(offset) { }

		constexpr TypeRef operator*() const { return *operator->(); }

		constexpr TypePtr operator->() const
		{
			GG_ASSERT(_ptr != nullptr, "Cannot dereference not initialized array iterator");
			GG_ASSERT(_index < _size, "Cannot dereference out of range index");

			return _ptr + _index;
		}

		constexpr ArrayIterator& operator++()
		{
			GG_ASSERT(_ptr != nullptr, "Cannot dereference not initialized array iterator");
			GG_ASSERT(_index < _size, "Cannot dereference out of range index");

			++_index;
			return *this;
		}

		constexpr ArrayIterator& operator++(int)
		{
			auto tmp = *this;
			++* this;
			return tmp;
		}

		constexpr ArrayIterator& operator--()
		{
			GG_ASSERT(_ptr != nullptr, "Cannot dereference not initialized array iterator");
			GG_ASSERT(_index < _size, "Cannot dereference out of range index");

			--_index;
			return *this;
		}

		constexpr ArrayIterator& operator--(int)
		{
			auto tmp = *this;
			--* this;
			return tmp;
		}

		constexpr bool operator==(const ArrayIterator& other) const
		{
			GG_ASSERT(_ptr == other._ptr, "Cannot compare array iterators of different arrays");

			return _index == other._index;
		}

		constexpr bool operator!=(const ArrayIterator& other) const
		{
			GG_ASSERT(_ptr == other._ptr, "Cannot compare array iterators of different arrays");

			return !(*this == other);
		}

		constexpr bool operator<(const ArrayIterator& other) const
		{
			GG_ASSERT(_ptr == other._ptr, "Cannot compare array iterators of different arrays");

			return _index < other._index;
		}

		constexpr bool operator>(const ArrayIterator& other) const
		{
			GG_ASSERT(_ptr == other._ptr, "Cannot compare array iterators of different arrays");

			return other._index < *this;
		}

		constexpr bool operator<=(const ArrayIterator& other) const
		{
			return !(other < *this);
		}

		constexpr bool operator>=(const ArrayIterator& other) const
		{
			return !(*this < other);
		}

	private:
		TypePtr _ptr;
		size_t _index;
	};
}