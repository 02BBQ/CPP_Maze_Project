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
		//Gotoxy(0,0);
		Render();
		//�ð�����ȭ
		//FrameSync(60);
	}
}

void Core::Update()
{
}

void Core::Render()
{
}
