#pragma once
#include "define.h"

class Camera
{
public:
	Camera()
	{
		topCam = 0;
		bottomCam = 20;
	}
	int topCam;
	int bottomCam;
};