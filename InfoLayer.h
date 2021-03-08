#pragma once
#include "Layer.h"
#include <string>
#include "Game1Data.h"
class InfoLayer :
    public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;
    Game1Data* gameData{};
};

