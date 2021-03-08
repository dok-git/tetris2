#pragma once
#include "Layer.h"
#include <string>

class Backgroung :
	public Layer
{
public:
	std::vector<CellVO> render() override;
};