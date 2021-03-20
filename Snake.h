#pragma once
#include <vector>
#include <windows.h>
#include <wincontypes.h>
#include "GameConfig.h"

class Snake
{
public:
	COORD pos{ GameConfig::GAME2_WIDTH / 2 , GameConfig::GAME2_HEIGHT - 3};
	std::vector <COORD> body{ {0,0},{1,0},{2,0},{3,0} };

};

