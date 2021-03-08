#include "InfoLayer.h"
#include <string>
using namespace std;

COORD InfoLayer::getLayerPos()
{
	return {20,1};
}

std::vector<CellVO> InfoLayer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, "Next Figure", FOREGROUND_RED, {3, 18});
	drawString(cells, "Points ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 3 });
	drawString(cells, "Level ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 4 });
	drawString(cells, "Destroyed rows ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 5 });
	drawString(cells, "Time ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 6 });
	drawString(cells, to_string(gameData->score), FOREGROUND_GREEN , { 8, 3 });
	drawString(cells, to_string(gameData->level), FOREGROUND_GREEN, { 8, 4 });

	vector < COORD > figure = gameData->nextFigure->getInitState();
	for (int i = 0; i < figure.size(); i++) {
		cells.push_back(getCellVO(L'\u00A4', FOREGROUND_RED | FOREGROUND_INTENSITY , figure[i].X+7, figure[i].Y+20));
	}
	return cells;
}