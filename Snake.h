#pragma once
#include <vector>
#include <windows.h>
#include <wincontypes.h>
#include "GameConfig.h"

class Snake
{
public:
	COORD headPos{ 10 , 10};
	//COORD pos{ 2 , 1 };
	std::vector <COORD> body{ {10,10},{11,10},{12,10},{13,10} };

};

