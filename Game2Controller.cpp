#include "Game2Controller.h"
#include <future>
#include <thread>
#include <conio.h>

void Game2Controller::onPressKey(int iKey)
{
	if (!isStart) {
		isStart = true;
		msg2Layer.hideMsg();
		startGame();
	}
}

void Game2Controller::show()
{
	scene.addLayer(&game2Background);
	scene.addLayer(&game2Layer);
	scene.addLayer(&msg2Layer);
	game2Layer.gameData = &gameData;
	game2InfoLayer.gameData = &gameData;
	msg2Layer.showStartMsg();
	updateScene();
	update();
	working = true;
	auto asyncDefault = std::async(std::launch::async, &Game2Controller::moveSnake, this);
	//auto asyncDefault2 = std::async(std::launch::async, &Game2Controller::Spawn, this);
	keyboardReader();
	gameOver();
}

void Game2Controller::gameOver() {
	bool exit = false;

	while (!exit)
	{
		if (_kbhit())
		{
			exit = true;
		}
	}
}

void Game2Controller::update() {
	drawSnake();
	checkApple();
	updateGameData();
	updateScene();
}

/*
void Game2Controller::Spawn() {
	while (working) {
		Sleep(2500);
		appleSpawn();
		update();
	}
}
*/

void Game2Controller::checkApple() {
	int lit = 0;
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
			if (appleDataVO.data[i][j] == 2) {
				lit++;
			}
		}
	}
	if (lit == 0) {
		appleSpawn();
	}
}

void Game2Controller::startGame() {
	update();
}

void Game2Controller::appleSpawn() {
	srand(time(0));
	int a,b;
	a = rand() % 30 + 1;
	b = rand() % 20 + 1;
	appleDataVO.data[1][1] = 2;
}

void Game2Controller::onLeft() {
	if (!checkLeftCol(snakeDataVO)) {
		snake.pos.X--;
		update();
	}
}

void Game2Controller::onRight() {
	if (!checkRightCol(snakeDataVO)) {
		snake.pos.X++;
		update();
	}
}

void Game2Controller::onUp() {
	if (!checkUpCol(snakeDataVO)) {
		snake.pos.Y--;
		update();
	}
}

void Game2Controller::onDown() {
	if (!checkDownCol(snakeDataVO)) {
		snake.pos.Y++;
		update();
	}
}


bool Game2Controller::checkRightCol(DataVO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
		if (staticDataVO.data[GameConfig::GAME2_WIDTH - 1][j] == 1) {
			return true;
		}
	}
	return false;
}

bool Game2Controller::checkLeftCol(DataVO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
		if (staticDataVO.data[0][j] == 1) {
			return true;
		}
	}
	return false;
}

bool Game2Controller::checkUpCol(DataVO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		if (staticDataVO.data[i][2] == 1) {
			return true;
		}
	}
	return false;
}

bool Game2Controller::checkDownCol(DataVO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		if (staticDataVO.data[i][GameConfig::GAME2_HEIGHT - 1] == 1) {
			return true;
		}
	}
	return false;
}


void Game2Controller::moveSnake()
{
	
}

void Game2Controller::updateGameData() {
	gameData.dataVO.clear();
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
			if (snakeDataVO.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = snakeDataVO.data[i][j];
			}
			if (appleDataVO.data[i][j] == 2) {
				gameData.dataVO.data[i][j] = appleDataVO.data[i][j];
			}
		}
	}
}

void Game2Controller::drawSnake() {
	snakeDataVO.clear();
	for (int i = 0; i < snake.body.size(); i++) {
		snakeDataVO.data[snake.body[i].X + snake.pos.X][snake.body[i].Y + snake.pos.Y] = 1;
	}
} 
 