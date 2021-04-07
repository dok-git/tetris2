#pragma once
#include "Layer.h"
class Msg2Layer :
    public Layer
{
public:
    std::vector<CellVO> render() override;
    void showStartMsg();
    void hideMsg();
    void gameOverMsg();
private:
    std::string msg = "";
    int lit = 0;
    	
};

