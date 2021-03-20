#pragma once
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"
#include "Game3Data.h"
#include "Backgroung.h"
#include "InfoLayer.h"
#include "MsgLayer.h"
#include "Msg3Layer.h"
#include "BaseController.h"
#include "Plane.h"
#include "Game3GameLayer.h"

class Game3Controller :
    public BaseController
{
public:
    void show();
	void gameOver();
	void moving();
	void meteoriteSpawn();
	void meteoriteMoving();

private:

	virtual void onLeft();
	virtual void onRight();
	virtual void onUp();
	virtual void onDown();
	virtual void onSpace();

	void meteorite();
	void meteoriteMove();
	void bulletMove();

	bool checkRightCol(DataVO& moveData);
	bool checkLeftCol(DataVO& moveData);
	bool checkUpCol(DataVO& staticDataVO);
	bool checkDownCol(DataVO& staticDataVO);

	bool isStart = false;
	void startGame();
	void update();
	void chackDel();
	void clearGameZone();
	void buhhhDel();
	void updateGameData();
	void drawPlane();

	Plane plane;
	Game3Data gameData;
	Backgroung backgroung;
	Game3GameLayer gameLayer;
	MsgLayer msgLayer;
	Msg3Layer msg3Layer;

	virtual void onPressKey(int iKey);

	DataVO moveDataVO;
	DataVO staticDataVO;
	DataVO bullet;
	DataVO buhhh;
};

