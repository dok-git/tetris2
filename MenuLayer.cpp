#include "MenuLayer.h"
#include "GameConfig.h"

COORD MenuLayer::getLayerPos()
{
	return { SHORT(GameConfig::WIDTH - widthMsg) / 2,   SHORT(GameConfig::HEIGHT - heightMsg) / 2 };
}

void MenuLayer::prevItem()
{
	itemSelected--;
	if (itemSelected < 0) {
		itemSelected = gamesName.size() - 1;
	}
}

void MenuLayer::nextItem()
{
	itemSelected++;
	if (itemSelected == gamesName.size()) {
		itemSelected = 0;
	}
}

std::vector<CellVO> MenuLayer::render()
{
	std::vector<CellVO> cells;
	WORD background = BACKGROUND_BLUE | BACKGROUND_RED;
	WORD textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

	heightMsg = SHORT(gamesName.size() * 2) + 5;


	box(cells, ' ', background, 0, 0, widthMsg, heightMsg);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', background | textColor, 0, 0, widthMsg, heightMsg);

	drawString(cells, "MENU", background | textColor, {SHORT(widthMsg/2-2), 2 });
	for (SHORT i = 1; i < gamesName.size(); i++) {
		drawString(cells, gamesName[i], background | getTextColor(i), { 3, 2 + i * 2 });
	}

	drawString(cells, gamesName[0], background | getTextColor(0), {SHORT(widthMsg / 2 - 2), 2 + SHORT(gamesName.size() * 2) });
	
	return cells;
}

WORD MenuLayer::getTextColor(int id) {
	if (id == itemSelected) {
		return  FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
	else {
		return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
}