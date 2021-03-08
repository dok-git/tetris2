#include "BaseController.h"
#include <conio.h>

#define KEY_ARROW_UP 72
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75
#define KEY_ENTER 13

void BaseController::keyboardReader() {

	int iKey = 0;
	working = true;

	while (working)
	{
		if (_kbhit())
		{
			iKey = _getch();
			onPressKey(iKey);
			switch (iKey)
			{
			case KEY_ARROW_LEFT:
				onLeft();
				break;
			case KEY_ARROW_RIGHT:
				onRight();
				break;
			case KEY_ARROW_UP:
				onUp();
				break;
			case KEY_ARROW_DOWN:
				onDown();
				break;
			case KEY_ENTER:
				onEnter();
				break;
			case 120: //клавиша x
			case 88: //клавиша X
				onKeyX();
			}
		}
	}
}

void BaseController::updateScene()
{
	scene.draw();
}
