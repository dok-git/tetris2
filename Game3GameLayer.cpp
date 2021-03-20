#include "Game3GameLayer.h"

std::vector <CellVO> Game3GameLayer::render()
{
	std::vector<CellVO> cells;

	box(cells, ' ', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, 0, 0, 10, 20);
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (gameData->dataVO.data[i][j] == 1) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
			if (gameData->dataVO.data[i][j] == 2) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
			if (gameData->dataVO.data[i][j] == 3) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
			if (gameData->dataVO.data[i][j] == 4) {
				cells.push_back(getCellVO(L'\u00A4', FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, i, j));
			}
		}
	}
	return cells;
}