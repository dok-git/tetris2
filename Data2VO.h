#pragma once
#include "GameConfig.h"
#include <vcruntime_string.h>

class Data2VO
{
public:
	int data[GameConfig::GAME2_WIDTH][GameConfig::GAME2_HEIGHT] = {};
	void clear() {
		memset(data, 0, sizeof(data));
	}
};

