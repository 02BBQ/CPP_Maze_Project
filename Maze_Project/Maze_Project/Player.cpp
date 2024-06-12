#include "Player.h"

void Player::Move()
{
	//this->tNewPos = this->tNewPos + Dir
	tNewPos = tPos;
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		--tNewPos.y;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		++tNewPos.y;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		--tNewPos.x;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		++tNewPos.x;
	}

	tNewPos.x = std::clamp(tNewPos.x, 0, MAP_WIDTH - 2);
	tNewPos.y = std::clamp(tNewPos.y, 0, MAP_HEIGHT - 2);

	tPos =tNewPos;
	cout << tPos.x << "\n";
	cout << tPos.y;

	tPos = tNewPos;
	Sleep(100);
}
