#pragma once
#include "define.h"

class Camera
{
public:
	Camera()
	{
		topCam = 0;
		bottomCam = 22;
	}
	int topCam;
	int bottomCam;
};