#pragma once
#include "Layer.h"
#include "GameConfig.h"
#include "GameData.h"
class GameLayer : public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;
    GameData* gameData{};
};