//#include "Core.h"
#include "define.h"
#include "console.h"
//#include "MK_GameLogic.h"
#include "TitleScene.h"

void Init() {
	system("title 21Bombman | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();
}

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

	GET_SINGLE(Core)->Run();
	return 0;
}