#include "pch.h"
#include <conio.h> // Used for detecting user input
#include <iostream> // Input Output streams
#include <fstream> // String streams
#include <sstream> // Reading in files
#include <iomanip>
#include <string>
#include <cctype> // For making lowercase
#include <array>

struct Player
{
	int position;
	char standingOn;
	int goldCount;
};

void genMap(char* mapArray);
void findPlayer(char* mapArray, Player &thePlayer);
void redrawMap(char* mapArray, int playerPos);
void movePlayer(char* mapArray, Player &thePlayer, char ch);

int main()
{
	bool gameEnded = false;

	char myArray[31 * 10];
	genMap(myArray);
	//redrawMap(myArray);

	Player thePlayer = {};
	findPlayer(myArray, thePlayer);
	redrawMap(myArray, thePlayer.position);

	while (!gameEnded)
	{
		char ch = _getch();
		movePlayer(myArray, thePlayer, ch);
		redrawMap(myArray, thePlayer.position);
	}
}

void genMap(char* outNum)
{
	char array[31 * 10];
	
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
		while (inFile >> theChar, !inFile.eof())
		{
			array[charNo] = theChar;
			outNum[charNo] = array[charNo]; // copy to array
			charNo++;
		}

		inFile.close();
	}
}

void findPlayer(char* mapArray, Player &thePlayer) 
{
	for (int i = 0; i < (31*10); i++)
	{
		if (mapArray[i] == 'S')
		{
			std::cout << "Found player at index: " << i << std::endl;
			thePlayer.position = i;
			thePlayer.standingOn = '.';
			//mapArray[i] = 'P';
		}
	}
}

void redrawMap(char* mapArray, int playerPos)
{
	//std::cout << "\033[2J\033[0; 0H";
	system("cls");
	mapArray[playerPos] = 'P';
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 31; x++)
		{
			std::cout << mapArray[x + y * 31];
		}
		std::cout << std::endl;
	}
}

void movePlayer(char* mapArray, Player &thePlayer, char theChar)
{
	switch (theChar)
	{
	case 'w':
		if (mapArray[thePlayer.position - 31] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = '.';
			thePlayer.position = thePlayer.position - 31;
		}
		break;
	case 'a':
		if (mapArray[thePlayer.position - 1] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = '.';
			thePlayer.position = thePlayer.position - 1;
		}
		break;
	case 's':
		if (mapArray[thePlayer.position + 31] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = '.';
			thePlayer.position = thePlayer.position + 31;
		}
		break;
	case 'd':
		if (mapArray[thePlayer.position + 1] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = '.';
			thePlayer.position = thePlayer.position + 1;
		}
		break;
	}
}