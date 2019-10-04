#include "pch.h"
#include <iostream>

void genMap(char* outNum);

int main()
{
	char myArray[5 * 3];
	genMap(myArray);

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			std::cout << myArray[x + y * 5];
		}
		std::cout << std::endl;
	}

	std::cout << "Both grids should look the same";
}

void genMap(char* outNum)
{
	char array[5 * 3];
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array[x + y * 5] = 'x';
			std::cout << array[x + y * 5];
			outNum[x + y * 5] = array[x + y * 5];
		}

		std::cout << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	
}