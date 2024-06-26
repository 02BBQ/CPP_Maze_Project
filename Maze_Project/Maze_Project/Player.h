#pragma once
#include<vector>
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
	std::vector<FLOAT2> getLinePoints(FLOAT2 start, FLOAT2 end);
	FLOAT2 Raycast(FLOAT2 origin, FLOAT2 dir);
};

