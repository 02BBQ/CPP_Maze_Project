#pragma once
#include <fstream>
#include <iostream>

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 21;

enum class OBJ_TYPE
{
	ROAD = '0', WALL, START, COIN, DANGER = '9'
};

class MapManager
{
private:
	MapManager();
public:
	static MapManager* GetInst() {
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
private:
	static MapManager* m_pInst;

public:
	char arrMap[MAP_WIDTH][MAP_HEIGHT] = {};

public:
	void Init(std::string const MAP_FILE);
};

