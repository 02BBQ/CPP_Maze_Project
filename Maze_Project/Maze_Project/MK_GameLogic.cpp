#include "MK_GameLogic.h"
#include "MapManager.h"

void MK_GameLogic::Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH])
{
	system("title 21Bombman | mode con cols=80 lines=40");
	SetCursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);
	// 100 - 10% / 1000 - 100%

	//Loding Map
	MapManager mapManager;
	mapManager.Init("stage.txt", MAP_WIDTH, MAP_HEIGHT);
	
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (_arrMap[i][j] == (char)OBJ_TYPE::START)
				*_pStartPos = { j,i };
		}
	}
	*_pPlayer = { *_pStartPos,{}, 1,1,false, false,false };
}
