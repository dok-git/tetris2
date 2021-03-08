#pragma once
#include <vector>
#include "Layer.h"

class Scene
{
public:
	Scene();
	void addLayer(Layer *layer);
	void draw();

private:
	std::vector <Layer*> layers;
	HANDLE hConsole;
};

