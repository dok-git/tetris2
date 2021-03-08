#include "BaseFigure.h"

BaseFigure::BaseFigure()
{
	
}

void BaseFigure::clearState()
{
	stateId = 0;
}

void BaseFigure::rotate()
{
	if (stateId == states.size()-1) {
		stateId = 0;
	}
	else{
		stateId++;
	}
}

vector<COORD> BaseFigure::getState()
{
	return states[stateId];
}

vector<COORD> BaseFigure::getInitState()
{
	return states[0];
}
	
