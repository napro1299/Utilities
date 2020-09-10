#pragma once

#include <iostream>
#include "utilities.h"

_UTILITY
template<typename T, size_t N>
class Array
{
private:
	T m_Array[N];
	mutable int m_PushOffset = N;
	mutable int m_GetOffset = 0;
public:
	Array() {}
	Array(const Array& array)
	{
		std::cout << "Copied!" << std::endl;
	}

	void PushRef(T& value)
	{
		m_Array[m_PushOffset - 1] = value;
		m_PushOffset--;
	}

	void Push(T value)
	{
		this->PushRef(value);
	}

	const T& Get() const
	{
		const T* const temp = m_Array + m_GetOffset;
		m_GetOffset++;
		return *temp;
	}

	const T& Get(unsigned int index) const
	{
		return m_Array[index];
	}
};
_UTILITY_END
