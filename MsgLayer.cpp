#include "MsgLayer.h"

using namespace std;

std::vector<CellVO> MsgLayer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, "Lucky games!", FOREGROUND_GREEN | FOREGROUND_RED, { 5, 1 });
	//drawString(cells, "Click on the button to start the game!", FOREGROUND_GREEN | FOREGROUND_RED, { 1, 27 });
	drawString(cells, msg, FOREGROUND_GREEN | FOREGROUND_RED, { 1, 27 });
	return cells;
}

void MsgLayer::showStartMsg() {
	msg = "Click on the button to start the game!";
}

void MsgLayer::hideMsg() {
	msg = "";
}

void MsgLayer::gameOver() {
	msg = "Game Over";
}