#include "Game3Controller.h"
#include <future>
#include <thread>
#include <ctime>
#include <conio.h>

void Game3Controller::onPressKey(int iKey)
{
	if (!isStart) {
		isStart = true;
		msgLayer.hideMsg();
		startGame();
	}
}

void Game3Controller::show()
{
	scene.addLayer(&backgroung);
	scene.addLayer(&gameLayer);
	scene.addLayer(&msgLayer);
	scene.addLayer(&msg3Layer);

	gameLayer.gameData = &gameData;
	msg3Layer.game3Data = &gameData;
	msgLayer.showStartMsg();
	updateScene();
	working = true;
	auto asyncDefault = std::async(std::launch::async, &Game3Controller::moving, this);
	auto asyncDefault2 = std::async(std::launch::async, &Game3Controller::meteoriteMoving, this);
	auto asyncDefault3 = std::async(std::launch::async, &Game3Controller::meteoriteSpawn, this);
	keyboardReader();
	gameOver();
}

void Game3Controller::gameOver() {
	bool exit = false;

	while (!exit)
	{
		if (_kbhit())
		{
			exit = true;
		}
	}
}

void Game3Controller::moving() {
	while (working) {
		Sleep(500);
		bulletMove();
		update();
	}
}

void Game3Controller::meteoriteSpawn() {
	while (working) {
		Sleep(2500);
		meteorite();
		update();
	}
}

void Game3Controller::meteoriteMoving() {
	while (working) {
		Sleep(650);
		meteoriteMove();
		update();
		buhhhDel();
	}
}

void Game3Controller::startGame() {
	update();
}

void Game3Controller::onLeft() {
	if (!checkLeftCol(staticDataVO)) {
		plane.pos.X--;
		update();
	}
}

void Game3Controller::onRight() {
	if (!checkRightCol(staticDataVO)) {
		plane.pos.X++;
		update();
	}
}

void Game3Controller::onUp() {
	if (!checkUpCol(staticDataVO)) {
		plane.pos.Y--;
		update();
	}
}

void Game3Controller::onDown() {
	if (!checkDownCol(staticDataVO)) {
		plane.pos.Y++;
		update();
	}
}

void Game3Controller::onSpace() {
	bullet.data[plane.pos.X][plane.pos.Y-1] = 2;
	update();
}

void Game3Controller::meteorite() {
	srand(time(0));
	int a;
	a = rand()%8+1;
	moveDataVO.data[a][0] = 3;
}

void Game3Controller::meteoriteMove() {
	for (int j = GameConfig::GAME_HEIGHT - 2; j >= 0; j--) {
		for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
			moveDataVO.data[i][j] = moveDataVO.data[i][j - 1];
		}
	}
	update();
}

void Game3Controller::bulletMove() {
	for (int j = 0; j < GameConfig::GAME_HEIGHT - 1; j++) {
		for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
			bullet.data[i][j] = bullet.data[i][j+1];
		}
	}
	update();
}
//
bool Game3Controller::checkRightCol(DataVO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (staticDataVO.data[GameConfig::GAME_WIDTH - 1][j] == 1) {
			return true;
		}
	} 
	return false;
}

bool Game3Controller::checkLeftCol(DataVO& staticDataVO) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (staticDataVO.data[0][j] == 1) {
			return true;
		}
	}
	return false;
}

bool Game3Controller::checkUpCol(DataVO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		if (staticDataVO.data[i][2] == 1) {
			return true;
		}
	}
	return false;
}

bool Game3Controller::checkDownCol(DataVO& staticDataVO) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		if (staticDataVO.data[i][GameConfig::GAME_HEIGHT-1] == 1) {
			return true;
		}
	}
	return false;
}
//
void Game3Controller::update() {
	drawPlane();
	chackDel();
	updateGameData();
	updateScene();
}

void Game3Controller::chackDel() {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (bullet.data[i][j] == 2 && moveDataVO.data[i][j] == 3 || bullet.data[i][j] == 2 && moveDataVO.data[i][j + 1] == 3) {
				bullet.data[i][j] = 0;
				moveDataVO.data[i][j] = 0;
				buhhh.data[i][j] = 4; 
				gameData.Destroyed++;
			}
			if (staticDataVO.data[i][j] != 0 && moveDataVO.data[i][j] == 3) {	
				moveDataVO.data[i][j] = 0;
				plane.pos.X = GameConfig::GAME_WIDTH / 2;
				plane.pos.Y = GameConfig::GAME_HEIGHT - 2;
				gameData.HP = gameData.HP - 20;
				if (gameData.HP == 0) {
					working = false;
				}
				clearGameZone();
			}
		}
	}
}

void Game3Controller::clearGameZone() {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = GameConfig::GAME_HEIGHT / 2; j < GameConfig::GAME_HEIGHT; j++) {
			moveDataVO.data[i][j] = 0;
		}
	}
}

void Game3Controller::buhhhDel() {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			buhhh.data[i][j] = 0;
		}
	}
}

void Game3Controller::updateGameData() {
	gameData.dataVO.clear();
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (moveDataVO.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = moveDataVO.data[i][j];
			}
			if (bullet.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = bullet.data[i][j];
			}
			if (staticDataVO.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = staticDataVO.data[i][j];
			}
			if (buhhh.data[i][j] != 0) {
				gameData.dataVO.data[i][j] = buhhh.data[i][j];
			}
		}
	}
}

void Game3Controller::drawPlane()
{
	staticDataVO.clear();
	for (int i = 0; i < plane.body.size(); i++) {
		staticDataVO.data[plane.body[i].X + plane.pos.X][plane.body[i].Y + plane.pos.Y] = 1;
	}
}