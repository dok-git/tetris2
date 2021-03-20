#include "Msg2Layer.h"

std::vector<CellVO> Msg2Layer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, "Snake Game Favorite...", FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY, { 10, 2 });
	drawString(cells, msg, FOREGROUND_GREEN | FOREGROUND_RED, { 1, 27 });
	if (lit > 0) {
		drawString(cells, "Game Over Sorry...", FOREGROUND_RED | FOREGROUND_INTENSITY, { 10, 27 });
	}
	return cells;
}

void Msg2Layer::showStartMsg() {
	msg = "Click on the button to start the game!";
}

void Msg2Layer::hideMsg() {
	msg = "";
}
