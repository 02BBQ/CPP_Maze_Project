//#include "Core.h"
#include "define.h"
#include "console.h"
//#include "MK_GameLogic.h"
#include "TitleScene.h"
int main() {                                                      
	if (!Core::GetInst()->Init()) {
		cout << "Game Init Error" << endl;
		Core::DestroyInst();
		return 0;
	}
	if (!TitleScene()) {
		return 0;
	}

	GET_SINGLE(Core)->Run();
	return 0;
}