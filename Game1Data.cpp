#include "Game1Data.h"
#include "Zoro.h"
#include "Triangle.h"
#include "Sqeare.h"
#include "AngleD.h"
#include "Angle.h"
#include "Straight.h"
#include "ZoroD.h"


int random(int max) {
	int min = 0;
	return min + rand() % (max - min + 1);
}

Game1Data::Game1Data()
{
	Zoro zoro;
	ZoroD zoroD;
	Triangle triangle;
	Straight straight;
	Angle angle;
	AngleD angleD;
	Sqeare sqeare;

	figures.push_back(zoro);
	figures.push_back(zoroD);
	figures.push_back(triangle);
	figures.push_back(straight);
	figures.push_back(angle);
	figures.push_back(angleD);
	figures.push_back(sqeare);

	setNewFigure();
}


void Game1Data::setNewFigure()
{
	posFigure = { 5,0 };
	figureId = nextfigureId;
	nextfigureId = random(figures.size() - 1);
	nextFigure = &figures[nextfigureId];
	nextFigure->clearState();

	currentFigure = &figures[figureId];
	currentFigure->clearState();
}

void Game1Data::rotateFigure() {
	currentFigure->rotate();
}

int Game1Data::getSpeed() {
	if (level > 4) {
		return levelSpeed[4];
	}
	return levelSpeed[level];
}
