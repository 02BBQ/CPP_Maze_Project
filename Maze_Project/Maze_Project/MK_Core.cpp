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
		if (gameOver == false)
		{
			Render();
		}
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

	if (player->tPos.y >= camera->bottomCam + half_map_height)
		GameOver();
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
		camera->topCam--;
		camera->bottomCam--;
		lastTime = this->gameTime->GetGameTime() + speed;
	}
}