#include "Core.h"
#include "define.h"
#include "console.h"
#include "MK_GameLogic.h";

void Update();
void Render();
void Init();

int main() 
{
	if (!Core::GetInst()->Init()) 
	{
		cout << "Game Init Error" << endl;
		Core::DestroyInst();
		return 0;
	}

	Init();
	while (true)
	{
		Update();
		Gotoxy(0, 0);
		Render();
		//시간동기화
		//FrameSync(60);
	}
	return 0;
}

void Init()
{
	GET_SINGLE(MK_GameLogic)->Init();
}

void Update() 
{
	GET_SINGLE(Core)->player->Move();
}
void Render() 
{
	GET_SINGLE(Core)->Render();
}