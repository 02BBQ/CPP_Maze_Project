#include "Core.h"
#include "define.h"
#include "console.h"

void Update();
void Render();

int main() {
	if (!Core::GetInst()->Init()) {
		cout << "Game Init Error" << endl;
		Core::DestroyInst();
		return 0;
	}
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
	GET_SINGLE(Core)->player->Move();
}
void Render() {
	GET_SINGLE(MapManager)->Render();
}