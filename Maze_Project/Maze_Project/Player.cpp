#include "Player.h"

void Player::Move(FLOAT2 Dir)
{
	this->tNewPos = this->tNewPos + Dir;
	this->tPos = tNewPos;
}
