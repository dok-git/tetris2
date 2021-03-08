#pragma once
#include "BaseController.h"
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"
#include "Game1Data.h"
#include "Backgroung.h"
#include "GameLayer.h"
#include "InfoLayer.h"
#include "MsgLayer.h"

enum class Direction { RIGHT, LEFT, UP, DOWN };

class Game1Controller : public BaseController
{

public:
	void show();

private:

	virtual void onPressKey(int iKey);
	virtual void onLeft();
	virtual void onRight();
	virtual void onUp();
	virtual void onDown();

	void drop();

	bool isStart = false;

	void update();

	Game1Data gameData;
	Backgroung backgroung;
	GameLayer gameLayer;
	InfoLayer infoLayer;
	MsgLayer msgLayer;


	void startGame();
	void move(Direction dir);


	DataVO moveDataVO;
	DataVO staticDataVO;
	int litchGoal=0;
	bool moveLeft();
	bool moveRight();
	bool moveDown();
	void checkdraw();
	void updateGameData();
	void copyData(DataVO& dataTo, DataVO& dataFrom);
	bool checkCollision(DataVO& moveData, DataVO& staticData);
	void drawFigure();
	bool checkLastRow(DataVO& moveData);
	bool checkCollisionL(DataVO& moveData, DataVO& staticData);
	bool checkCollisionR(DataVO& moveData, DataVO& staticData);
	bool checkRightCol(DataVO& moveData);
	bool checkLeftCol(DataVO& moveData);
	void checkWidth();
	void clearRow(int row);
	void moveDownStatic(int row);
};


