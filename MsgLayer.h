#pragma once
#include "Layer.h"
#include <string>

class MsgLayer :
    public Layer
{
public:
    std::vector<CellVO> render() override;
    void showStartMsg();
    void hideMsg();
    void gameOverMsg();
    //void gameOver();
private:
    std::string msg = "";
    int lit = 0;
};

