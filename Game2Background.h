#pragma once
#include "Layer.h"
class Game2Background :
    public Layer
{
public:
    std::vector<CellVO> render() override;
};

