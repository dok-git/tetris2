#include "MainController.h"
#include "MenuController.h"
#include "Game1Controller.h"

void MainController::start()
{
	showMenu();
}

void MainController::showMenu() {
	MenuController menu;
	int result = menu.show();
	if (result > 0) {
		startGame(result);
	}
}

void MainController::startGame(int gameId) {
	if (gameId == 1) {
		Game1Controller game;
		game.show();
		showMenu();
	}

	if (gameId == 2) {
		//Game2Controller game;
		//game.show();
		//showMenu();
	}

}