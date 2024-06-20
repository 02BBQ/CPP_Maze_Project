#pragma once
#include "define.h"

class WorldTime
{
private:

public:
	int currentTime = 0;
	int deltaTime = 0;
	WorldTime();
	void StartWorldTime();
};

