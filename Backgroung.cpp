#include "Backgroung.h"
#include "GameConfig.h"

std::vector <CellVO> Backgroung::render()
{
	std::vector<CellVO> cells;

	WORD ColorFigure = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;

	//cells.push_back(getCellVO('A', FOREGROUND_BLUE, 5, 3));
	//line(cells, '*', FOREGROUND_GREEN, 1, 1, 1, 10);
	//border(cells, '+', '+', '+', '+', '+', '+', FOREGROUND_RED, 5, 5, 5, 5);
	//box(cells, ' ', ColorYellowB, 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT);

	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, 5, 3, 12, 22);
	const int x = 2, x2 = 18;
	std::vector<COORD> figures = { {x + 1,3},{x + 1,4},{x,4},{x,5},{x,7},{x,8},{x,9},{x + 1,8},{x,11},{x,12},
	{x + 1,11},{x + 1,12},{x + 1,14},{x + 1,15},{x,15},{x + 1,16},{x,18},{x + 1,18},{x + 1,19},{x + 1,20},
	{x,22},{x,23},{x,24},{x,25},{x2 + 1,5},{x2 + 1,4},{x2,4},{x2,3},{x2 + 1,7},{x2 + 1,8},{x2 + 1,9},{x2,8},
	{x2 + 1,12},{x2,11},{x2,12},{x2 + 1,11},{x2,14},{x2,15},{x2,16},{x2 + 1,15},{x2 + 1,18},{x2,18},{x2,19},
	{x2,20},{x2 + 1,22},{x2 + 1,23},{x2 + 1,24},{x2 + 1,25} };

	drawArrayPoints(cells, L'\u00A4', ColorFigure, figures);

	return cells;
}