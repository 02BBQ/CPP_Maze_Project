#include "Core.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{
}
bool Core::Init()
{
	player = new Player();
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
