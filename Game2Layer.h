#pragma once
#include "Layer.h"
#include "Game2Data.h"
class Game2Layer :
    public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;
    Game2Data* gameData{};
};

