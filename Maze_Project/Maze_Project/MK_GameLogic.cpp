#include "MK_GameLogic.h"


MK_GameLogic* MK_GameLogic::m_pInst = nullptr;

MK_GameLogic::MK_GameLogic()
{

}

void MK_GameLogic::Init()
{
	system("title 21Maze | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);
	// 100 - 10% / 1000 - 100%
	 

	//Loding Map
	GET_SINGLE(MapManager)->Init("TestMap.txt");
	
	// Player Start Pos Settings
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (GET_SINGLE(MapManager)->arrMap[i][j] == (char)OBJ_TYPE::START)
				GET_SINGLE(Core)->player->tPos = {j,i};
		}
	}
}
