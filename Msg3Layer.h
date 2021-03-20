#pragma once
#include "Layer.h"
#include <xkeycheck.h>
#include "Game3Data.h"

class Msg3Layer :
    public Layer
{
public:
    Game3Data* game3Data{};
    std::vector<CellVO> render() override;
    COORD getLayerPos() override;
};