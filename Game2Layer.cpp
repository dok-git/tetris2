#include "Game2Layer.h"
#include "GameConfig.h"

COORD Game2Layer::getLayerPos()
{
	return { 5,5 };
}

std::vector <CellVO> Game2Layer::render()
{
	std::vector<CellVO> cells;

	box(cells, ' ', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, 0, 0, GameConfig::GAME2_WIDTH, GameConfig::GAME2_HEIGHT);
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
			if (gameData->dataVO.data[i][j] == 1) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
			if (gameData->dataVO.data[i][j] == 2) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
			if (gameData->dataVO.data[i][j] == 3) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
		}
	}
	return cells;
}