#pragma once
#include "GameLayer.h"
class Game3GameLayer :
    public GameLayer
{
public:
    std::vector<CellVO> render() override;
};

