#pragma once
#include "Scene.h"
class BaseController
{

public:
	void keyboardReader();
	virtual void onPressKey(int iKey) {};
	virtual void onLeft() {};
	virtual void onRight() {};
	virtual void onUp() {};
	virtual void onDown() {};
	virtual void onEnter() {};
	virtual void onKeyX() {};
	virtual void onSpace() {};
protected:
	bool working = false;
	Scene scene;
	void updateScene();
};

