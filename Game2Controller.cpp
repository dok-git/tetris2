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
	scene.addLayer(&game2InfoLayer);
	game2Layer.gameData = &gameData;
	game2InfoLayer.gameData = &gameData;
	msg2Layer.showStartMsg();
	updateScene();
	update();
	working = true;
	auto asyncDefault = std::async(std::launch::async, &Game2Controller::moveSnake, this);
	//auto asyncDefault2 = std::async(std::launch::async, &Game2Controller::Spawn, this);
	keyboardReader();
	msg2Layer.gameOverMsg();
	updateScene();
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

void Game2Controller::updateSnake() {
	snake.body.insert(snake.body.begin() , snake.headPos);
	if (deltail) {
		snake.body.pop_back();
	}
	else {
		deltail = true;
	}
}

void Game2Controller::update() {
	drawSnake();
	checkApple();
	checkAppleAdd();
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
		gameData.eat++;
		appleSpawn();
	}
}

void Game2Controller::startGame() {
	update();
}

void Game2Controller::appleSpawn() {
	srand(time(0));
	int a,b;
	bool ex = false;
	deltail = false;
	while (!ex) {
		a = rand() % 30 + 1;
		b = rand() % 20 + 1;
		if (snakeDataVO.data[a][b] == 0) {
			appleDataVO.data[a][b] = 2;
			ex = true;
		}
	}
}

void Game2Controller::onLeft() {
	onMove(DirectionMove::LEFT);
}

void Game2Controller::onRight() {
	onMove(DirectionMove::RIGHT);
}

void Game2Controller::onUp() {
	onMove(DirectionMove::UP);
}

void Game2Controller::onDown() {
	onMove(DirectionMove::DOWN);
}

void Game2Controller::onMove(DirectionMove direction) {
	if (direction == directionMove || 
		direction == reversDirection(directionMove)) {
		return;
	}
	newDirectionMove = direction;
}

void Game2Controller::onMoveSnake() {
	directionMove = newDirectionMove;
	switch (directionMove)
	{
	case DirectionMove::UP:
		snake.headPos.Y--;
		break;
	case DirectionMove::DOWN:
		snake.headPos.Y++;
		break;
	case DirectionMove::LEFT:
		snake.headPos.X--;
		break;
	case DirectionMove::RIGHT:
		snake.headPos.X++;
		break;
	default:
		break;
	}
	if (snake.headPos.X == -1 || snake.headPos.X == GameConfig::GAME2_WIDTH ||
		snake.headPos.Y == -1 || snake.headPos.Y == GameConfig::GAME2_HEIGHT ||
		snakeDataVO.data[snake.headPos.X][snake.headPos.Y] == 1) {
		working = false;
	}
	else
	{
		updateSnake();
		update();
	}
}

DirectionMove Game2Controller::reversDirection(DirectionMove direction) {
	if (direction == DirectionMove::DOWN) {
		return DirectionMove::UP;
	}
	else if (direction == DirectionMove::UP) {
		return DirectionMove::DOWN;
	}
	else if (direction == DirectionMove::LEFT) {
		return DirectionMove::RIGHT;
	}
	else if (direction == DirectionMove::RIGHT) {
		return DirectionMove::LEFT;
	}
}

/*
bool Game2Controller::checSnakeDCol() {
	if (snakeDataVO.data[snake.body[0].X][snake.body[0].Y + 1] == 1) {
		return true;
	}
	return false;
}
bool Game2Controller::checSnakeLCol() {
	if (snakeDataVO.data[snake.body[0].X - 1][snake.body[0].Y] == 1) {
		return true;
	}
	return false;
}
bool Game2Controller::checSnakeRCol() {
	if (snakeDataVO.data[snake.body[0].X + 1][snake.body[0].Y] == 1) {
		return true;
	}
	return false;
}
bool Game2Controller::checSnakeUCol() {
	if (snakeDataVO.data[snake.body[0].X][snake.body[0].Y - 1] == 1) {
		return true;
	}
	return false;
}
bool Game2Controller::checkRightCol(Data2VO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
		if (staticDataVO.data[GameConfig::GAME2_WIDTH - 1][j] == 1 || staticDataVO.data[GameConfig::GAME2_WIDTH - 1][j] == 3) {
			return true; 
		}
	}
	return false;
}
bool Game2Controller::checkLeftCol(Data2VO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
		if (staticDataVO.data[0][j] == 1 || staticDataVO.data[0][j] == 3) {
			return true;
		}
	}
	return false;
}
bool Game2Controller::checkUpCol(Data2VO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		if (staticDataVO.data[i][0] == 1 || staticDataVO.data[i][0] == 3) {
			return true;
		}
	}
	return false;
}
bool Game2Controller::checkDownCol(Data2VO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		if (staticDataVO.data[i][GameConfig::GAME2_HEIGHT - 1] == 1 || staticDataVO.data[i][GameConfig::GAME2_HEIGHT - 1] == 3) {
			return true;
		}
	}
	return false;
}
*/

void Game2Controller::checkAppleAdd() {
	for (int i = 0; i < GameConfig::GAME2_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME2_HEIGHT; j++) {
			if (snakeDataVO.data[i][j] == 3 && appleDataVO.data[i][j] == 2) {
				appleDataVO.data[i][j] = 0;
				checkApple();
			}
		}
	}
}

void Game2Controller::moveSnake()
{
	while (working) {
		Sleep(500);
		onMoveSnake();
		//onMove(directionMove, false);
	}
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
		if (i == 0) {
			snakeDataVO.data[snake.body[i].X][snake.body[i].Y] = 3;
		}
		else {
			snakeDataVO.data[snake.body[i].X][snake.body[i].Y] = 1;
		}
	}
} 
 