#include "Core.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{
	
}
bool Core::Init()
{
	player = new Player();
	camera = new Camera();
	timer = new WorldTime();
	
	return true;
}

void Core::Run()
{
	while (true)
	{
		
		Update();
		Gotoxy(0,0);
		Render();
		//시간동기화
		//FrameSync(60);
	}
}

void Core::Update()
{
	this->player->Move();
	this->timer->StartWorldTime();
	
}

void Core::Render()
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
	cout << timer->deltaTime << endl;
}
