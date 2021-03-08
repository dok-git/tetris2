#pragma once
#include "GameData.h"
#include "GameConfig.h"
#include "BaseFigure.h"
#include <array>

class Game1Data : public GameData
{
	public:
		Game1Data();
		BaseFigure *nextFigure;
		BaseFigure *currentFigure;
		void setNewFigure();
		COORD posFigure{};
		void rotateFigure();
		int getSpeed();

	private:
		int figureId = 0;
		int nextfigureId = 0;
		std::vector <BaseFigure> figures{};
		const std::array < int, 5 > levelSpeed{ 500 , 400 , 300 , 250 , 200 };
};

