#pragma once
#include "Layer.h"
#include <string>

class MenuLayer :
    public Layer
{
public:
    virtual std::vector<CellVO> render() override;
    virtual COORD getLayerPos() override;
    int itemSelected = 1;
    std::vector <std::string> gamesName{ "EXIT" };
    void prevItem();
    void nextItem();

private:
    int widthMsg = 34;
    int heightMsg = 13;
    WORD getTextColor(int i);
};

