#pragma once
#include "define.h"

class Camera
{
public:
	Camera()
	{
		//cout << MAP_HEIGHT;
		//topCam = (MAP_HEIGHT / 2);
		//bottomCam = 20 + (MAP_HEIGHT / 2);

		topCam = 0;
		bottomCam = 20;
	}

	int topCam;
	int bottomCam;
};