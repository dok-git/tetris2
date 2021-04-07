#include "Game2InfoLayer.h"
#include "GameConfig.h"

std::vector <CellVO> Game2InfoLayer::render()
{
	std::vector <CellVO> cells;
	drawString(cells, std::to_string(gameData->eat), FOREGROUND_GREEN, { 1, 1 });
	//border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT);
	return cells;
}