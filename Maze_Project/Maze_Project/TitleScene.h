#pragma once

void TitleRender();
bool TitleScene();
void InfoRender();
enum class MENU {
	START, INFO, QUIT
};
MENU MenuRender();
enum class KEY {
	_, UP, DOWN, SPACE
};
KEY KeyController();;
void EnterAnimation();