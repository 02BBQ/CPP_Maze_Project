#include "WorldTime.h"

WorldTime::WorldTime()
{
}

void WorldTime::StartWorldTime()
{
	deltaTime = 1.0/clock() - currentTime;
	currentTime = clock();
}
