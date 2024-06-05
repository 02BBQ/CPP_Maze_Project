#pragma once
#include "Logic_bbq.h"

class Player
{
public:
	FLOAT2 tPos;
	FLOAT2 tNewPos;
public:
	void Move(FLOAT2 Dir);
};

