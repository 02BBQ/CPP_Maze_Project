#pragma once
#include "define.h"

class Camera
{
public:
	Camera()
	{
		topCam = (MAP_HEIGHT / 2);
		bottomCam = 20 + (MAP_HEIGHT / 2);
	}

	int topCam;
	int bottomCam;
};