#pragma once
#include<fcntl.h>
#include<corecrt_io.h>
#include"define.h"

void GameOverRender();
bool GameOverScene();
void GOInfoRender();
enum class GOMENU {
	START, QUIT
};
GOMENU MenuRender();
enum class GOKEY {
	_, UP, DOWN, SPACE
};

GOKEY KeyController();;