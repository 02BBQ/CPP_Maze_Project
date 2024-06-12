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
		//�ð�����ȭ
		//FrameSync(60);
	}
	return 0;
}

void Update() {
	Core::GetInst()->player->Move();
}
void Render() {

}