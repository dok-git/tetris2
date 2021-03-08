#pragma once
#include "GameConfig.h"
#include <vcruntime_string.h>

class DataVO
{
public:
	int data[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT] = {};
	void clear() {
		memset(data, 0, sizeof(data));
	}
};

