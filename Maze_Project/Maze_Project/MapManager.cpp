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
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (GET_SINGLE(Core)->player->tPos.x == j &&
				GET_SINGLE(Core)->player->tPos.y == i)
				cout << "¡×";
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "¡á";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "¡Ú";
			SetColor((int)COLOR::WHITE);
		}
		cout << endl;
	}
}
