#include "MK_Core.h"
MK_Core* MK_Core::m_pInst = nullptr;

MK_Core::MK_Core()
{

}

bool MK_Core::Init()
{
	player = new Player();
	camera = new Camera();
	gameTime = new GameTimer();

	return true;
}

void MK_Core::Run()
{
	while (true)
	{

		Update();
		Gotoxy(0, 0);
		Render();
		//시간동기화
		//FrameSync(60);
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
	// 나중에 수정
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	for (int i = camera->topCam; i < camera->bottomCam; ++i)
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
}

void MK_Core::MoveMap()
{
	if (GetAsyncKeyState(VK_SHIFT))
	{
		camera->topCam--;
		camera->bottomCam--;
	}

	if (GetAsyncKeyState(VK_CONTROL))
	{
		camera->topCam++;
		camera->bottomCam++;
	}
}
