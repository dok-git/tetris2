#pragma once
#include <windows.h>
#include <vector>
#include <wincontypes.h>

using namespace std;
class BaseFigure
{
public:
	BaseFigure();
	void clearState();
	void rotate();
	vector<COORD> getState();
	vector<COORD> getInitState();
protected:
	vector<vector<COORD>> states;
	int stateId = 0;

};

