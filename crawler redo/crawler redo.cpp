#include "pch.h"
#include <iostream>

void genMap(char* outNum);

int main()
{
	char myArray[31 * 10];
	genMap(myArray);

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 31; x++)
		{
			std::cout << myArray[x + y * 31];
		}
		std::cout << std::endl;
	}

	std::cout << "Both grids should look the same";
}

void genMap(char* outNum)
{
	char array[31 * 10];
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 31; x++)
		{
			array[x + y * 31] = 'x';
			std::cout << array[x + y * 31];
			outNum[x + y * 31] = array[x + y * 31];
		}

		std::cout << std::endl;
	}
	std::cout << "--------------------------------------" << std::endl;
	
}