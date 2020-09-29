#include <iostream>
#include <Windows.h>

#include <array>
#include "Array/Array.h"

using namespace GiGud::DataStructures;

int main()
{
	Array <int, 3> testArray;
	for (int i = 0; i < testArray.Size(); ++i)
	{
		testArray[i] = i + 1;
	}

	std::cout << "Iterate with: Size base []" << std::endl;
	for (int i = 0; i < testArray.Size(); ++i)
	{
		std::cout << testArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Iterate with: Iterators" << std::endl;
	for (auto& itr = testArray.begin(); itr != testArray.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	std::cout << "Iterate with: Foreach" << std::endl;
	for (auto i : testArray)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	system("pause");
}
