#include "Player.h"

Player::Player()
{
	tPos = { 0,0 };
	tNewPos = tPos;
	lastMoveTime = 0;
}

void restoreTile(MapManager* mapManager, int x, int y, char originalType, int delayMilliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
	mapManager->arrMap[y][x] = (char)OBJ_TYPE::TRAIL2;
	std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
	mapManager->arrMap[y][x] = originalType;
}

void Player::Move()
{
	//this->tNewPos = this->tNewPos + Dirif ()
	if ((clock() - lastMoveTime) < .1f) return;

	lastMoveTime = clock();

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

	if (tPos == tNewPos) return;

	std::vector<FLOAT2> pathTiles = getLinePoints(tPos, tNewPos);
	for (const auto& index : pathTiles) {
		char* tile = &MapManager::GetInst()->arrMap[index.y][index.x];
		if (*tile == (char)OBJ_TYPE::TRAIL || *tile == (char)OBJ_TYPE::TRAIL2) continue;
		*tile = (char)OBJ_TYPE::TRAIL;
		// 여기서 tile.x, tile.y를 사용하여 각 타일을 검사하거나 처리합니다.

		std::thread restoreThread(restoreTile, MapManager::GetInst(), index.x, index.y, (char)OBJ_TYPE::ROAD, 100);
		restoreThread.detach(); // 메인 스레드와 독립적으로 실행
	}

	tPos = tNewPos;
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
		/*else if (MapManager::GetInst()->arrMap[newPos.y][newPos.x] == (char)OBJ_TYPE::DANGER) {
			newPos = { newPos.x - dir.x, newPos.y - dir.y };
			return newPos;
		}*/
		if (newPos.x == MAP_WIDTH || newPos.y == MAP_HEIGHT 
			|| newPos.x == -1
			|| newPos.y == -1) {
			//newPos = { std::clamp(newPos.x,0,MAP_WIDTH), std::clamp(newPos.y,0,MAP_HEIGHT) };
			return newPos;
		}
		++tries;
	}
	return origin;
}


std::vector<FLOAT2> Player::getLinePoints(FLOAT2 start, FLOAT2 end) {
	std::vector<FLOAT2> points;
	int dx = std::abs(end.x - start.x);
	int sx = start.x < end.x ? 1 : -1;
	int dy = -std::abs(end.y - start.y);
	int sy = start.y < end.y ? 1 : -1;
	int err = dx + dy;

	while (true) {
		points.push_back(start);
		if (start.x == end.x && start.y == end.y) break;
		int e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			start.x += sx;
		}
		if (e2 <= dx) {
			err += dx;
			start.y += sy;
		}
	}

	return points;
}