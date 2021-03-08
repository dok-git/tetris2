#include "MenuController.h"
#include "Scene.h"
#include "Backgroung.h"

int MenuController::show()
{
	Backgroung backgroung;

	menuLayer.gamesName.push_back("1. Tetris game");
	menuLayer.gamesName.push_back("2. Snake game");
	menuLayer.gamesName.push_back("3. RocketSrocketsRockets");

	scene.addLayer(&backgroung);
	scene.addLayer(&menuLayer);
	updateScene();

	keyboardReader();

	return menuLayer.itemSelected;
}

void MenuController::onUp()
{
	menuLayer.prevItem();
	updateScene();
}

void MenuController::onDown()
{
	menuLayer.nextItem();
	updateScene();
}

void MenuController::onEnter()
{
	working = false;
}


