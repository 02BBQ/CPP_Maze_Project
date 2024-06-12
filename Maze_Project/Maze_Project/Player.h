#pragma once
#include "Logic_bbq.h"
#include "define.h"

class Player
{
public:
	FLOAT2 tPos;
	FLOAT2 tNewPos;
public:
	Player() {
		this->tPos = { 0,0 };
		this->tNewPos = this->tPos;
	}
	void Move();
};

