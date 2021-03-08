#include "Layer.h"
#include "GameConfig.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

COORD Layer::getLayerPos()
{
	return layerPos;
}

CellVO Layer::getCellVO(WCHAR Char, WORD color, int x, int y)
{
	CellVO cell{};
	cell.charInfo.Char.UnicodeChar = Char;
	cell.charInfo.Attributes = color;
	cell.pos = getPosition(x, y);
	return cell;
}

CellVO Layer::getCellVO(WCHAR Char, WORD color, COORD pos)
{
	return getCellVO(Char, color, pos.X, pos.Y);
}

int Layer::getPosition(int x, int y)
{
	return GameConfig::WIDTH * (y+ getLayerPos().Y) + (x + getLayerPos().X);
}

int Layer::getPosition(COORD pos)
{
	return getPosition(pos.X, pos.Y);
}

void Layer::line(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, int x0, int y0, int x1, int y1)
{
	if (x0 == x1) {
		for (int i = y0; i < y1; i++) {
			layerBufer.push_back(getCellVO(Char, color, x0, i));
		}
	}
	else {
		for (int i = x0; i < x1; i++) {
			layerBufer.push_back(getCellVO(Char, color, i, y0));
		}
	}
}

void Layer::border(std::vector<CellVO>& layerBufer, WCHAR CharH, WCHAR CharV, WCHAR CharA1, WCHAR CharA2, WCHAR CharA3, WCHAR CharA4, WORD color, int x0, int y0, int width, int height)
{	
	line(layerBufer, CharH, color, x0, y0, width + x0, y0);
	line(layerBufer, CharH, color, x0, height + y0 - 1, width + x0, height + y0 - 1);
	line(layerBufer, CharV, color, x0, y0, x0, height + y0);
	line(layerBufer, CharV, color, width + x0 - 1, y0, width + x0 - 1, height + y0);
	layerBufer.push_back(getCellVO(CharA1, color, x0, y0));
	layerBufer.push_back(getCellVO(CharA2, color, width + x0 - 1, y0));
	layerBufer.push_back(getCellVO(CharA3, color, width + x0 - 1, height + y0 - 1));
	layerBufer.push_back(getCellVO(CharA4, color, x0, height + y0 - 1));
}

void Layer::box(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, int x0, int y0, int width, int height)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			layerBufer.push_back(getCellVO(Char, color, x0+i, y0+j));
		}
	}
}

void Layer::drawArrayPoints(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, std::vector<COORD> points )
{
	for (int i = 0; i < points.size(); i++) {
		layerBufer.push_back(getCellVO(Char, color, points[i].X, points[i].Y));
	}
}

void Layer::drawString(std::vector<CellVO>& layerBufer, std::string str, WORD color, COORD pos)
{
	for (int i = 0; i < str.size(); i++) {
		layerBufer.push_back(getCellVO(str[i], color, pos.X + i, pos.Y));
	}
}