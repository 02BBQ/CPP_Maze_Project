#include "Core.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	return false;
}

void Core::Run()
{
	while (true)
	{
		Update();
		//Gotoxy(0,0);
		Render();
		//시간동기화
		//FrameSync(60);
	}
}

void Core::Update()
{
}

void Core::Render()
{
}
