#include "MapManager.h"

MapManager* MapManager::m_pInst = nullptr;

MapManager::MapManager()
{
}

void MapManager::Init(std::string const MAP_FILE)
{
	// Loading Map
	std::fstream readMap(MAP_FILE);
	if (readMap.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			readMap.getline(arrMap[i], MAP_WIDTH);
			if (readMap.fail())
				std::cout << "File Error";
		}
	}
	// RAII
	readMap.close();
}

void MapManager::Render()
{
	Player* p_player = GET_SINGLE(Core)->player;
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (p_player->tPos.x == j && p_player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "¢Â";
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "¡á";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << " ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "¡Ú";
			else if (arrMap[i][j] == (char)OBJ_TYPE::DANGER)
			{
				SetColor((int)COLOR::RED);
				cout << "¡ã";
			}
			SetColor((int)COLOR::WHITE);
		}
		cout << "\n";
	}
}

void MapManager::ObstacleRender()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			/*if (p_player->tPos.x == j && p_player->tPos.y == i)
			{
				SetColor((int)COLOR::LIGHT_YELLOW);
				cout << "¢Â";
			}*/
		}
	}
}
