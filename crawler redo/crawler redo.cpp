#include "pch.h"
#include <conio.h> // Used for detecting user input
#include <iostream> // Input Output streams
#include <fstream> // String streams
#include <sstream> // Reading in files
#include <iomanip>
#include <string>
#include <cctype> // For making lowercase
#include <array>
#include <vector>

struct Player
{
	int position;
	char standingOn;
	int goldCount;
};

void genMap(char* mapArray);
void findPlayer(char* mapArray, Player &thePlayer);
void redrawMap(char* mapArray, int playerPos, std::vector<std::string> &sysLog);
void movePlayer(char* mapArray, Player &thePlayer, char ch);
void tileCheck(Player &thePlayer, std::vector <std::string> &sysLog, bool &gameEnded);
void addLogMessage(std::vector<std::string> &sysLog, std::string message);

int main()
{
	bool gameEnded = false;
	char myArray[31 * 10];
	genMap(myArray);
	//redrawMap(myArray);

	std::vector <std::string> sysLog;

	Player thePlayer = {};
	findPlayer(myArray, thePlayer);
	redrawMap(myArray, thePlayer.position, sysLog);

	while (!gameEnded)
	{
		char ch = _getch();
		movePlayer(myArray, thePlayer, ch);
		tileCheck(thePlayer, sysLog, gameEnded);
		redrawMap(myArray, thePlayer.position, sysLog);
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
		}
	}
}

void redrawMap(char* mapArray, int playerPos, std::vector<std::string> &sysLog)
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

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "              LOG              " << std::endl;
	std::cout << "===============================" << std::endl;
	for (size_t i = 0; i < sysLog.size(); ++i)
	{
		std::cout << sysLog[i] << std::endl;
	}
	
}

void movePlayer(char* mapArray, Player &thePlayer, char theChar)
{
	theChar = tolower(theChar);
	switch (theChar)
	{
	case 'w':
		if (mapArray[thePlayer.position - 31] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = thePlayer.standingOn;
			thePlayer.position = thePlayer.position - 31;
			thePlayer.standingOn = mapArray[thePlayer.position];
		}
		break;
	case 'a':
		if (mapArray[thePlayer.position - 1] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = thePlayer.standingOn;
			thePlayer.position = thePlayer.position - 1;
			thePlayer.standingOn = mapArray[thePlayer.position];
		}
		break;
	case 's':
		if (mapArray[thePlayer.position + 31] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = thePlayer.standingOn;
			thePlayer.position = thePlayer.position + 31;
			thePlayer.standingOn = mapArray[thePlayer.position];
		}
		break;
	case 'd':
		if (mapArray[thePlayer.position + 1] == '#') {

		}
		else
		{
			mapArray[thePlayer.position] = thePlayer.standingOn;
			thePlayer.position = thePlayer.position + 1;
			thePlayer.standingOn = mapArray[thePlayer.position];
		}
		break;
	}
}

void tileCheck(Player& thePlayer, std::vector<std::string>& sysLog, bool &gameEnded)
{
	switch (thePlayer.standingOn)
	{
	case 'G':
		thePlayer.standingOn = '.';
		thePlayer.goldCount++;
		addLogMessage(sysLog, "Picked up gold!");
		break;
	case 'E':
		addLogMessage(sysLog, "You've escaped! Congratulations!");
		gameEnded = true;
		break;
	}
}

void addLogMessage(std::vector<std::string> &sysLog, std::string message)
{
	sysLog.push_back(message);
}