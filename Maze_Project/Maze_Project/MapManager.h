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
public:
	char arrMap[MAP_WIDTH][MAP_HEIGHT] = {};

public:
	MapManager();
	void Init(std::string const MAP_FILE);
};

