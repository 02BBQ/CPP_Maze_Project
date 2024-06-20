#pragma once
#include "Logic_bbq.h"
#include "define.h"

class Player
{
private:
	float lastMoveTime;
public:
	FLOAT2 tPos;
	FLOAT2 tNewPos;
public:
	Player();
	void Move();
	FLOAT2 Raycast(FLOAT2 origin, FLOAT2 dir);
};

