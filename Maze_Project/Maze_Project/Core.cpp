#include "Core.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{
	
}
bool Core::Init()
{
	player = new Player();
	/*system("title 21Bombman | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();

	std::fstream readMap("stage.txt");
	if (readMap.is_open()) {
		for (int i = 0; i < MAP_HEIGHT; ++i) {
			readMap.getline(, MAP_WIDTH);
			if (readMap.fail())
				std::cout << "���� ����";
		}
	}

	readMap.close();*/
	
	return true;
}

void Core::Run()
{
	while (true)
	{
		Update();
		Gotoxy(0,0);
		Render();
		//�ð�����ȭ
		//FrameSync(60);
	}
}

void Core::Update()
{
	this->player->Move();
}

void Core::Render()
{
	// ���߿� ����
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (player->tPos.x == j && player->tPos.y == i)
				cout << "��";
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
}
