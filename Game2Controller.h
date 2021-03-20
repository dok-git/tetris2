#pragma once
#include "BaseController.h"
#include "Backgroung.h"
#include "Game2InfoLayer.h"
#include "Game2Data.h"
#include "Game2Background.h"
#include "Game2Layer.h"
#include "Snake.h"
#include "Msg2Layer.h"

class Game2Controller : public BaseController
{
public:
	void onPressKey(int iKey);
	void show();

	void startGame();
	void gameOver();

	void update();
	void updateGameData();

	//void Spawn();

	void moveSnake();
	void drawSnake();

	void checkApple();
	void appleSpawn();

	void onDown();
	void onLeft();
	void onRight();
	void onUp();

	bool checkRightCol(DataVO& staticDataVO);
	bool checkLeftCol(DataVO& staticDataVO);
	bool checkUpCol(DataVO& staticDataVO);
	bool checkDownCol(DataVO& staticDataVO);

	bool isStart = false;

private:

	DataVO snakeDataVO;
	DataVO appleDataVO;

	Snake snake;
	Game2Data gameData;
	Backgroung backgroung;
	Game2Layer game2Layer;
	Game2Background game2Background;
	Msg2Layer msg2Layer;
	Game2InfoLayer game2InfoLayer;
};

