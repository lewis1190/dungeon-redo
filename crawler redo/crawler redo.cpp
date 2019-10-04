#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

void genMap(char* outNum);

int main()
{
	char myArray[31 * 10]; // +11 To take into account the Null terminator, plus 10 lots of \n when getting the characters
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
	//for (int y = 0; y < 10; y++)
	//{
	//	for (int x = 0; x < 31; x++)
	//	{
	//		array[x + y * 31] = 'x';
	//		std::cout << array[x + y * 31];
	//		outNum[x + y * 31] = array[x + y * 31];
	//	}

	//	std::cout << std::endl;
	//}
	//std::cout << "--------------------------------------" << std::endl;
	
	char theChar;
	std::ifstream inFile;

	inFile.open("./map.txt");
	if (inFile.bad())
	{
		std::cerr << "Unable to open the map!";
		exit(1);
	}
	else
	{
		int charNo = 0;
		//while (inFile.get(theChar), !inFile.eof())
		while (inFile >> theChar, !inFile.eof())
		{
			std::cout << theChar;
			array[charNo] = theChar;
			outNum[charNo] = array[charNo];
			charNo++;

			if (!(charNo % 31)) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << std::endl;
		inFile.close();
	}
}