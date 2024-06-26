#include "MapManager.h"

MapManager* MapManager::m_pInst = nullptr;

MapManager::MapManager()
{
}

void MapManager::Init(std::string const MAP_FILE)
{
	std::ios_base::sync_with_stdio(false);

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

void MapManager::ObstacleRender()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < MAP_WIDTH - 1; ++j)
		{
			SetColor((int)COLOR::RED);
			cout << "бу";
		}
		cout << "\n";
	}
	SetColor((int)COLOR::WHITE);
}

void MapManager::GameOverRender()
{
	cout << "Game Over";
}

void MapManager::DestoryObstacle(int destory_pos_y)
{
	Gotoxy(0, destory_pos_y + 2);
	for (int i = 0; i < MAP_WIDTH - 1; ++i)
	{
		cout << "  ";
	}
}
