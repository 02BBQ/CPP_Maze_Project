#include "Core.h"
#include "define.h"
#include "console.h"
#include "MK_GameLogic.h"
#include "TitleScene.h"

void Update();
void Render();
void Init();

int main() {                                                      
	if (!Core::GetInst()->Init()) {
		cout << "Game Init Error" << endl;
		Core::DestroyInst();
		return 0;
	}

	Init();

	if (!TitleScene()) {
		return 0;
	}

	GET_SINGLE(MK_GameLogic)->Init();
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

void Update() {
	Core::GetInst()->player->Move();
}
void Render() 
{
	Player* plr = GET_SINGLE(Core)->player;
	auto arrMap = GET_SINGLE(MapManager)->arrMap;
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (plr->tPos.x == j && plr->tPos.y == i)
				cout << "♡";
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "■";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "ㅗ";
			SetColor((int)COLOR::WHITE);
		}
		cout << "\n";
	}
}
void Init() {
	system("title 21Bombman | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();
}