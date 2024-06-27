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
	system("title Maze | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();
	if (player == nullptr) player = new Player();
	if (camera == nullptr) camera = new Camera();
	timer = new GameTimer();
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
	while (true)
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
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << "\n";
	}
	Gotoxy(MAP_WIDTH / 1.5, 21);
	cout << "PlayerPos: " << player->tPos.x << ", " << player->tPos.y << "\t\t";
	Gotoxy(MAP_WIDTH / 1.5, 20);
	cout << "Score: " << timer->GetGameTime();
}
