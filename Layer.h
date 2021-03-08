#pragma once
#include <vector>
#include <windows.h>
#include <wincontypes.h>
#include <string>

class CellVO
{
	public:
		int pos;
		CHAR_INFO charInfo;
};

class Layer
{
	public:
		virtual std::vector<CellVO> render() = 0;
		virtual COORD getLayerPos();

	protected:
		COORD layerPos { 0,0 };
		CellVO getCellVO(WCHAR Char, WORD color, int x, int y);
		CellVO getCellVO(WCHAR Char, WORD color, COORD pos);
		int getPosition(int x, int y);
		int getPosition(COORD pos);
		void line(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, int x0, int y0, int x1, int y1);
		void border(std::vector<CellVO>& layerBufer, WCHAR CharH, WCHAR CharV, WCHAR CharA1, WCHAR CharA2, WCHAR CharA3, WCHAR CharA4, WORD color, int x0, int y0, int width, int height);
		void box(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, int x0, int y0, int width, int height);
		void drawArrayPoints(std::vector<CellVO>& layerBufer, WCHAR Char, WORD color, std::vector<COORD> points);
		void drawString(std::vector<CellVO>& layerBufer, std::string str, WORD color, COORD pos);
};



