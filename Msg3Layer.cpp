#include "Msg3Layer.h"

using namespace std;

COORD Msg3Layer::getLayerPos()
{
	return { 20,1 };
}

std::vector<CellVO> Msg3Layer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, "Destroyed ", FOREGROUND_BLUE | FOREGROUND_INTENSITY, { 1, 3 });
	drawString(cells, "HP ", FOREGROUND_BLUE | FOREGROUND_INTENSITY, { 1, 4 });
	drawString(cells, to_string(game3Data->HP), FOREGROUND_GREEN, { 4, 4 });
	drawString(cells, to_string(game3Data->Destroyed), FOREGROUND_GREEN, { 12, 3 });
	if (game3Data->HP < 50) {
		drawString(cells, to_string(game3Data->HP), FOREGROUND_RED, { 4, 4 });
	}
	if (game3Data->HP == 0) {
		drawString(cells, "GameOver Sorry... ", FOREGROUND_RED, { 1, 18 });
	}
	return cells;
}