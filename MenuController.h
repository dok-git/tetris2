#pragma once
#include "BaseController.h"
#include "MenuLayer.h"

class MenuController : public BaseController
{
public:
	int show();
	virtual void onUp();
	virtual void onDown();
	virtual void onEnter();
private:
	MenuLayer menuLayer;
	int itemSelected = 1;
};

