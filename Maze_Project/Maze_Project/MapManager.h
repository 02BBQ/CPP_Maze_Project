#pragma once
#include "define.h"
#include "Core.h"
#include "Camera.h"
#include <thread>
#include <chrono>

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 23;

enum class OBJ_TYPE
{
	ROAD = '0', WALL, START, COIN, TRAIL = 'a', TRAIL2
};

class MapManager
{
private:
	MapManager();
	static MapManager* m_pInst;

public:
	static MapManager* GetInst() {
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}

public:
	char arrMap[MAP_HEIGHT][MAP_WIDTH] = {};

	void Init(std::string const MAP_FILE);
	void Render();
	void ObstacleRender();
};

