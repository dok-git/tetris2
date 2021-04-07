#pragma once
#include "BaseController.h"
#include "Backgroung.h"
#include "Game2InfoLayer.h"
#include "Game2Data.h"
#include "Game2Background.h"
#include "Game2Layer.h"
#include "Snake.h"
#include "Msg2Layer.h"
#include "Data2VO.h"

enum class DirectionMove {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game2Controller : public BaseController
{
public:
	DirectionMove directionMove;
	DirectionMove newDirectionMove;

	void onPressKey(int iKey);
	void show();

	void startGame();
	void gameOver();

	void updateSnake();
	void update();
	void updateGameData();

	//void Spawn();

	void moveSnake();
	void drawSnake();

	void checkApple();
	void appleSpawn();

	void onDown();
	void onMove(DirectionMove direction);
	void onMoveSnake();
	DirectionMove reversDirection(DirectionMove direction);
	void onLeft();
	void onRight();
	void onUp();

	/*
	bool checkRightCol(Data2VO& staticDataVO);
	bool checkLeftCol(Data2VO& staticDataVO);
	bool checkUpCol(Data2VO& staticDataVO);
	bool checkDownCol(Data2VO& staticDataVO);
	bool checSnakeDCol();
	bool checSnakeLCol();
	bool checSnakeRCol();
	bool checSnakeUCol();
	*/

	void checkAppleAdd();

	bool deltail = true;
	bool isStart = false;

private:

	Data2VO snakeDataVO;
	Data2VO appleDataVO;

	Snake snake;
	Game2Data gameData;
	Backgroung backgroung;
	Game2Layer game2Layer;
	Game2Background game2Background;
	Msg2Layer msg2Layer;
	Game2InfoLayer game2InfoLayer;
};