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
