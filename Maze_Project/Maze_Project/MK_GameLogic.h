#pragma once
#include <Windows.h>

#include "mci.h"
#include "console.h"

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

class MK_GameLogic
{
public:
	void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH]);
};

