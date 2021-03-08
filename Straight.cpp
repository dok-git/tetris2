#include "Straight.h"

Straight::Straight()
{
	states.push_back({ {1,0},{1,1},{1,2},{1,3} });
	states.push_back({ {0,1},{1,1},{2,1},{3,1} });
	states.push_back({ {2,0},{2,1},{2,2},{2,3} });
	states.push_back({ {0,2},{1,2},{2,2},{3,2} });
}
