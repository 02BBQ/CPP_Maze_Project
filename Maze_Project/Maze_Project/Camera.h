#pragma once
#include "define.h"

class Camera
{
public:
	Camera()
	{
		topCam = 1;
		bottomCam = 21;
	}

	int topCam;
	int bottomCam;
};