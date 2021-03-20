#include "Game1Controller.h"
#include <future>
#include <thread>
#include <conio.h>

void Game1Controller::onPressKey(int iKey)
{
	if (!isStart) {
		isStart = true;
		msgLayer.hideMsg();
		startGame();
	}
}

void Game1Controller::onLeft() {
	move(Direction::LEFT);
}

void Game1Controller::onRight() {
	move(Direction::RIGHT);
}

void Game1Controller::onUp() {
	move(Direction::UP);
}

void Game1Controller::onDown() {
	move(Direction::DOWN);
}

void Game1Controller::show()
{
	scene.addLayer(&backgroung);
	scene.addLayer(&gameLayer);
	scene.addLayer(&infoLayer);
	scene.addLayer(&msgLayer);

	gameLayer.gameData = &gameData;
	infoLayer.gameData = &gameData;
	msgLayer.showStartMsg();
	updateScene();
	working = true;
	auto asyncDefault = std::async(std::launch::async, &Game1Controller::drop, this);
	keyboardReader();
	msgLayer.gameOverMsg();
	gameOver();
}

void Game1Controller::gameOver() {
	bool exit = false;
	
	while (!exit)
	{
		if (_kbhit())
		{
			exit = true;
		}
	}
}

void Game1Controller::drop() {
	while (working) {
		Sleep(gameData.getSpeed());
		move(Direction::DOWN);
		updateScene();
	}
}


void Game1Controller::startGame() {
	gameData.setNewFigure();
	update();
}

void Game1Controller::move(Direction dir)
{
	if (!isStart) return;

	bool needToUpdate = true;
	switch (dir)
	{
	case Direction::RIGHT:
		needToUpdate = moveRight();
		break;
	case Direction::LEFT:
		needToUpdate = moveLeft();
		break;
	case Direction::DOWN:
		needToUpdate = moveDown();
		if (!needToUpdate) {
			if (gameData.posFigure.Y == 0) {
				working = false;
				return;
			}
			else {
				checkWidth();
				gameData.setNewFigure();
				needToUpdate = true;
			}
		}
		break;
	case Direction::UP:
		gameData.rotateFigure();
		checkdraw();
		break;
	default:
		break;
	}
	if (needToUpdate) {
		update();
	}
}

void Game1Controller::update() {
	drawFigure();
	updateGameData();
	updateScene();
}

void Game1Controller::checkWidth() {
	int litch = 0;
	for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) {
		bool needClearRow = true;
		for (int ii = 0; ii < GameConfig::GAME_WIDTH; ii++) {
			if (staticDataVO.data[ii][i] == 0) {
				needClearRow = false;
			}
		}
		if (needClearRow) {
			litch++;
			litchGoal++;
			gameData.score++;
			clearRow(i);
			moveDownStatic(i);
		}
	}
	if (litch > 1) {
		gameData.score = gameData.score + litch - 1;
	}
	if (litchGoal == 2) {
		gameData.level++;
		litchGoal = 0;
	}
}

void Game1Controller::moveDownStatic(int row) {
	for (int j = row; j > 0; j--) {
		for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
			staticDataVO.data[i][j] = staticDataVO.data[i][j - 1];
		}
	}
}

void Game1Controller::clearRow(int row) {
	for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
		staticDataVO.data[j][row] = 0;
	}
}

bool Game1Controller::moveLeft() {
	if (checkCollisionL(moveDataVO, staticDataVO) || checkLeftCol(moveDataVO)) {
		return false;
	}
	gameData.posFigure.X--;
	return true;
}

bool Game1Controller::moveRight() {
	if (checkCollisionR(moveDataVO, staticDataVO) || checkRightCol(moveDataVO)) {
		return false;
	}
	gameData.posFigure.X++;
	return true;
}

bool Game1Controller::moveDown() {

	if (checkCollision(moveDataVO, staticDataVO) || checkLastRow(moveDataVO)) {
		copyData(staticDataVO, moveDataVO);
		return false;
	}
	gameData.posFigure.Y++;
	return true;
}

void Game1Controller::checkdraw() {
	int litch = 0, wid;
	vector<COORD> state = gameData.currentFigure->getState();
	if (gameData.posFigure.X < 0) {
		gameData.posFigure.X = 0;
	}
	for (int i = 0; i < state.size(); i++) {
		wid = state[i].X;
		while (gameData.posFigure.X + wid + 1 > GameConfig::GAME_WIDTH) {
			gameData.posFigure.X--;
		}
	}
}

void Game1Controller::drawFigure()
{
	moveDataVO.clear();
	vector<COORD> state = gameData.currentFigure->getState();
	for (int i = 0; i < state.size(); i++) {
		moveDataVO.data[state[i].X + gameData.posFigure.X][state[i].Y + gameData.posFigure.Y] = 1;
	}
}

void Game1Controller::updateGameData() {
	gameData.dataVO.clear();
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (moveDataVO.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = moveDataVO.data[i][j];
			}

			if (staticDataVO.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = staticDataVO.data[i][j];
			}
		}
	}
}

void Game1Controller::copyData(DataVO& dataTo, DataVO& dataFrom) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (dataFrom.data[i][j] != 0) {
				dataTo.data[i][j] = dataFrom.data[i][j];
			}
		}
	}
}

bool Game1Controller::checkCollision(DataVO& moveData, DataVO& staticData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 1; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i][j - 1] && staticData.data[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool Game1Controller::checkCollisionL(DataVO& moveData, DataVO& staticData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH - 1; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i + 1][j] && staticData.data[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool Game1Controller::checkCollisionR(DataVO& moveData, DataVO& staticData) {
	for (int i = 1; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i - 1][j] && staticData.data[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool Game1Controller::checkLastRow(DataVO& moveData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		if (moveData.data[i][GameConfig::GAME_HEIGHT - 1] == 1) {
			return true;
		}
	}
	return false;
}

bool Game1Controller::checkLeftCol(DataVO& moveData) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[0][j] == 1) {
			return true;
		}
	}
	return false;
}

bool Game1Controller::checkRightCol(DataVO& moveData) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[GameConfig::GAME_WIDTH - 1][j] == 1) {
			return true;
		}
	}
	return false;
}