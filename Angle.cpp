#include "Angle.h"

Angle::Angle()
{
	states.push_back({ {1,0},{1,1},{1,2},{2,2} });
	states.push_back({ {0,2},{0,1},{1,1},{2,1} });
	states.push_back({ {0,0},{1,0},{1,1},{1,2} });
	states.push_back({ {2,0},{2,1},{1,1},{0,1} });
}
