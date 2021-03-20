#include "Game2Background.h"
#include "GameConfig.h"

std::vector <CellVO> Game2Background::render()
{
	std::vector<CellVO> cells;

	WORD ColorFigure = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;

	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, 4, 4, GameConfig::GAME2_WIDTH + 2, GameConfig::GAME2_HEIGHT + 2);
	
	const int x = 1, x2 = 37;

	std::vector<COORD> figures = { {x,4} , {x + 1,4} , {x + 1,5} , {x + 1,6} , {x ,6} , {x ,7} , {x ,8} ,
	{x + 1,8} , { x + 1,9 } , { x + 1,10 } , {x ,10} , {x ,11} , {x ,12} , {x + 1,12} , {x + 1,13} , 
	{x + 1,14} , {x ,14} , {x ,15} , {x ,16} , {x + 1,16} , {x + 1,17} ,
	{x + 1,18} , {x ,18} , {x ,19} , {x ,20} , {x + 1,20} , {x + 1,21} ,
	{x + 1,22} , {x ,22} , {x ,23},
	{x2 + 1,6} , {x2 + 1,7} , {x2,7} , {x2,8} , {x2 ,9} , {x2 + 1,9} , {x2 + 1,10} ,
	{x2 + 1,11} , { x2 ,11 } , { x2,12 } , {x2 ,13} , {x2 + 1,13} , {x2 + 1,14} , {x2 + 1,15} , {x2,15} ,
	{x2,16} , {x2 ,17} , {x2 + 1,17} , {x2 + 1,18} , {x2 + 1,19} , {x2 ,19} ,
	{x2 ,20} , {x2 ,21} , {x2 + 1,21} , {x2 + 1,22} , {x2 + 1,23} , {x2,23} ,
	{x2,24} , {x2 ,25} , {x2 + 1 ,25} };

	cells.push_back(getCellVO('v', FOREGROUND_RED, 38, 4));
	cells.push_back(getCellVO('^', FOREGROUND_RED, 1, 25));
	cells.push_back(getCellVO('"', BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 1, 24));
	cells.push_back(getCellVO('"', BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 38, 5));
	drawArrayPoints(cells, L'\u00A4', ColorFigure, figures);

	return cells;
}