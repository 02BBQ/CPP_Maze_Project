#include "MK_Core.h"
MK_Core* MK_Core::m_pInst = nullptr;

MK_Core::MK_Core()
{

}

bool MK_Core::Init()
{
	player = new Player();
	camera = new Camera();

	return true;
}

void MK_Core::Run()
{
	gameTime = new GameTimer();

	while (true)
	{

		Update();
		Gotoxy(0, 0);
		if (gameOver == false)
		{
			Render();
		}
	}
}

void MK_Core::Update()
{
	MoveMap();
	this->player->Move();
	this->gameTime->Update();
}

void MK_Core::Render()
{
	// 이거 수정 해야함
	// 맵 80이면 
	// 2 나누기 안돼
	// 40, 60 나온다.
	// 이거 다른 방법 써야 함
	int half_map_height = (MAP_HEIGHT / 2);
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	for (int i = camera->topCam + half_map_height; i < camera->bottomCam + half_map_height; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player->tPos.x == j && player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "◈";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "■";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "★";
			SetColor((int)COLOR::WHITE);
		}
		cout << "\n";
	}
	GET_SINGLE(MapManager)->ObstacleRender();

	// Clean Up ObstacleRender
	//DestoryObstacle();

	// GameOver
	//if (player->tPos.y >= camera->bottomCam + half_map_height) GameOver();
}

/// <summary>
/// Temporary Method
/// </summary>
void MK_Core::DestoryObstacle()
{
	Gotoxy(0, camera->bottomCam + 2);
	for (int i = 0; i < MAP_WIDTH - 1; ++i)
	{
		cout << "  ";
	}
}

void MK_Core::GameStart()
{
	gameOver = false;
}

void MK_Core::GameOver()
{
	GET_SINGLE(MapManager)->GameOverRender();
	gameOver = true;
}

void MK_Core::MoveMap()
{
	double time = 0;
	time = this->gameTime->GetGameTime();
	if (time > lastTime)
	{
		if (camera->topCam <= -20) return;
		// topcam은 플레이어가 위로 움직일때 실행
		camera->topCam--;
		camera->bottomCam--;
		lastTime = this->gameTime->GetGameTime() + speed;
	}
}