#pragma once
#include <vector>
#include <windows.h>
#include <wincontypes.h>
#include "GameConfig.h"

class Plane
{
public:
	COORD pos{ GameConfig::GAME_WIDTH / 2 , GameConfig::GAME_HEIGHT - 2};
	std::vector <COORD> body { {0,0},{-1,1},{0,1},{1,1} };

};

