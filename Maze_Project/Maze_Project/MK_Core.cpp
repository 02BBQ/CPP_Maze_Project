#include "MK_Core.h"
MK_Core* MK_Core::m_pInst = nullptr;

MK_Core::MK_Core()
{
	player = new Player();
	camera = new Camera();
	score = 0;
}

bool MK_Core::Init()
{
	if (player == nullptr) player = new Player();
	if (camera == nullptr) camera = new Camera();

	GET_SINGLE(MK_GameLogic)->Init();

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
	this->player->Move();
	//MoveMap();
	this->gameTime->Update();
	score += gameTime->GetDeltaTime();
}	

void MK_Core::Render()
{
	// 이거 수정 해야함
	// 맵 80이면 
	// 2 나누기 안돼
	// 40, 60 나온다.
	// 이거 다른 방법 써야 함
	// Start 문자는 제거 예정
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	int half_map_height = (MAP_HEIGHT / 2);

	for (int i = camera->topCam + half_map_height; i < camera->bottomCam + half_map_height; ++i)
	{
		for (int _ = 0; _ < (GetConsoleResolution().X) / 2 - MAP_WIDTH; ++_) {
			cout << " ";
		}
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player->tPos.x == j && player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "◈";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
			{
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::YELLOW);
				cout << "  ";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "★";
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

	Gotoxy(GetConsoleResolution().X / 2 - MAP_WIDTH, half_map_height);
	GET_SINGLE(MapManager)->ObstacleRender();

	Gotoxy(GetConsoleResolution().X / 2 - MAP_WIDTH, half_map_height + 4);
	cout << "PlayerPos: " << player->tPos.x << ", " << player->tPos.y << "\t\t";
	cout << "Score: " << gameTime->GetGameTime();

	// Clean Up ObstacleRender
	// DestoryObstacle();

	// GameOver
	if (player->tPos.y >= camera->bottomCam + half_map_height) GameOver();
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
		//camera->topCam--;
		camera->bottomCam--;
		lastTime = this->gameTime->GetGameTime() + speed;
	}
}