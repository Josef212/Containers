#include <iostream>
#include <Windows.h>

#include <array>
#include "Array.h"

using namespace GiGud::DataStructures;

int main()
{

	std::array<int, 2> a;
	Array <int, 3> b;
	for (int i = 0; i < b.Size(); ++i)
	{
		b[i] = i;
	}

	std::cout << "Hello world" << std::endl;

	for (int i = 0; i < b.Size(); ++i)
	{
		std::cout << b[i] << std::endl;
	}

	system("pause");
}
