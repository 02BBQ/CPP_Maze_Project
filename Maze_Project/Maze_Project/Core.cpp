#include "Core.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{
	player = new Player();
	camera = new Camera();
	score = 0;
	startTime = 0;
}
bool Core::Init()
{
	if (player == nullptr) player = new Player();
	if (camera == nullptr) camera = new Camera();
	timer = new GameTimer();
	score = 0;
	startTime = clock();
	
	return true;
}

void Core::Run()
{
	while (true)
	{
		
		Update();
		Gotoxy(0,0);
		Render();
		//프레임 조정
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
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	for (int i = camera->topCam; i < camera->bottomCam; ++i)
	{
		for (int _ = 0; _ < (GetConsoleResolution().X) / 2 - MAP_WIDTH; ++_) {
			cout << " ";
		}
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player->tPos.x == j && player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "��";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "��";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "��";
			SetColor((int)COLOR::WHITE);
		}
		cout << "\n";
	}
	Gotoxy(MAP_WIDTH/1.5, MAP_HEIGHT + 2);
	cout << "PlayerPos: " << player->tPos.x << ", " << player->tPos.y << "\t\t";
}
