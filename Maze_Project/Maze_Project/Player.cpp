#include "Player.h"

void Player::Move()
{
	//this->tNewPos = this->tNewPos + Dir
	tNewPos = tPos;
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		tNewPos = Raycast(tPos, {0, -1});
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		tNewPos = Raycast(tPos, {0, 1});
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		tNewPos = Raycast(tPos, {-1, 0});
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		tNewPos = Raycast(tPos, {1, 0});
	}

	tNewPos.x = std::clamp(tNewPos.x, 0, MAP_WIDTH - 2);
	tNewPos.y = std::clamp(tNewPos.y, 0, MAP_HEIGHT - 2);

	/*tPos =tNewPos;
	cout << tPos.x << "\n";
	cout << tPos.y;*/

	tPos = tNewPos;
	Sleep(33);
}

FLOAT2 Player::Raycast(FLOAT2 origin, FLOAT2 dir)
{
	FLOAT2 newPos = origin;
	int maxTries = 100;
	int tries = 0;
	while (tries < maxTries) {
		newPos = { newPos.x + dir.x , newPos.y + dir.y };
		if (MapManager::GetInst()->arrMap[newPos.y][newPos.x] == (char)OBJ_TYPE::WALL) {
			newPos = { newPos.x - dir.x, newPos.y - dir.y };
			return newPos;
		}
		if (newPos.x == MAP_WIDTH || newPos.y == MAP_HEIGHT
			|| newPos.x == -1
			|| newPos.y == -1) {
			newPos = { newPos.x, newPos.y };
			return newPos;
		}
		++tries;
	}
	return origin;
}


