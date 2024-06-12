#pragma once
#include "define.h"
#include "Core.h"

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

enum class OBJ_TYPE
{
	ROAD = '0', WALL, START, COIN, DANGER = '9'
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
	char arrMap[MAP_WIDTH][MAP_HEIGHT] = {};

public:
	void Init(std::string const MAP_FILE);
	void Render();
};

