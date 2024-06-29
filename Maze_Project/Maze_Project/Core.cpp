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
	system("title Maze | mode con cols=140 lines=40");
	SetCursorVis(false, 1);
	LockResize();

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
	if (camera != nullptr)
	{
		delete camera;
		camera = nullptr;
	}

	if (player == nullptr) player = new Player();
	if (camera == nullptr) camera = new Camera();
	if (timer == nullptr)
		timer = new GameTimer();
	else
		timer->Init();

	score = 0;
	startTime = clock();

	GET_SINGLE(MapManager)->Init("TestMap.txt");

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (GET_SINGLE(MapManager)->arrMap[i][j] == (char)OBJ_TYPE::START)
				player->tPos = { j,i };
		}
	}

	return true;
}

void Core::Run()
{
	system("mode con cols=80 lines=40");
	while (!player->isDead)
	{

		Update();
		Gotoxy(0, 0);
		Render();
		//������ ����
		//FrameSync(60);
	}
}

void Core::Update()
{
	this->player->Move();
	this->timer->Update();
	this->camera->CameraUpdate();
	score += timer->GetDeltaTime();
}

void Core::Render()
{
	Gotoxy(60,26);
	cout << "Score: " << timer->GetGameTime();
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	Gotoxy(0, 6);
	
	for (int i = camera->topCam; i < camera->bottomCam; ++i)
	{
		for (int _ = 0; _ < (GetConsoleResolution().X) / 2 - MAP_WIDTH - 1; ++_) {
			cout << " ";
		}
		SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::LIGHT_VIOLET);
		cout << "  ";
		SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player->tPos.x == j && player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "※";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
			{
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLUE);
				cout << "  ";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "○";
			else if (arrMap[i][j] == (char)OBJ_TYPE::TRAIL) {
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::LIGHT_YELLOW);
				cout << "  ";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::TRAIL2) {
				SetColor((int)COLOR::MINT, (int)COLOR::MINT);
				cout << "  ";
			}
			else {
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLUE);
				cout << "  ";
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::LIGHT_VIOLET);
		cout << "  ";
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		cout << "\n";
	}
	
}
 