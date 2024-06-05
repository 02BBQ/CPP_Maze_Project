#pragma once
#include <Windows.h>

#include "mci.h"
#include "console.h"

class MK_GameLogic
{
	void Init(char _arrMap[MAP_HEIGHT][MAP_WIDTH], PPLAYER _pPlayer, PPOS _pStartPos, PPOS _pEndPos)
	{
		system("title 21Bombman | mode con cols=80 lines=40");
		SetCursorVis(false, 1);
		LockResize();
		SetFontSize(FW_BOLD, 20, 20);
		// 100 - 10% / 1000 - 100%
		PlayBgm(TEXT("Sound\\dreams.mp3"), 100);
		//// 내부 세팅
		//strcpy_s(_arrMap[0],  "21111100000000000000");
		//strcpy_s(_arrMap[1],  "00000111111110000000");
		//strcpy_s(_arrMap[2],  "00111100000000000000");
		//strcpy_s(_arrMap[3],  "00000100000000000000");
		//strcpy_s(_arrMap[4],  "00000111111111100000");
		//strcpy_s(_arrMap[5],  "00000100000000100000");
		//strcpy_s(_arrMap[6],  "00000100000000100000");
		//strcpy_s(_arrMap[7],  "00000100000000100000");
		//strcpy_s(_arrMap[8],  "00000100000000100000");
		//strcpy_s(_arrMap[9],  "00000100000000100000");
		//strcpy_s(_arrMap[10], "00000100000000111100");
		//strcpy_s(_arrMap[11], "00000100000000000000");
		//strcpy_s(_arrMap[12], "00000111111111111100");
		//strcpy_s(_arrMap[13], "00000100000000001103");
		//strcpy_s(_arrMap[14], "00000100000000001001");
		//strcpy_s(_arrMap[15], "00000100000000001111");
		//strcpy_s(_arrMap[16], "00000100000000000000");
		//strcpy_s(_arrMap[17], "00000100000000000100");
		//strcpy_s(_arrMap[18], "00000111111111111100");
		//strcpy_s(_arrMap[19], "00000000000000000000");

		// 외부 파일에서 맵끌어오기
		std::fstream readMap("stage.txt");
		if (readMap.is_open())
		{
			for (int i = 0; i < MAP_HEIGHT; ++i)
			{
				readMap.getline(_arrMap[i], MAP_WIDTH);
				if (readMap.fail())
					std::cout << "파일 에러";
			}
		}
		// RAII
		readMap.close();

		// 시작점과 끝점
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			for (int j = 0; j < MAP_WIDTH; ++j)
			{
				if (_arrMap[i][j] == (char)OBJ_TYPE::START)
					*_pStartPos = { j,i };
				//_pStartPos->x = j;
				//(*_pStartPos).x
				else if (_arrMap[i][j] == (char)OBJ_TYPE::GOAL)
					*_pEndPos = { j,i };
			}
		}
		*_pPlayer = { *_pStartPos,{}, 1,1,false, false,false };

	}
};

