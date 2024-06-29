#include "GameOver.h"

void GameOverRender() {
	int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << "\n\n\n\n";
	wcout << L"\t        ____  __                __          __    __         " << endl;
	wcout << L"\t       / __ \/ /___ _________  / /_  ____  / /___/ /__  _____" << endl;
	wcout << L"\t      / /_/ / / __ `/ ___/ _ \/ __ \/ __ \/ / __  / _ \/ ___/" << endl;
	wcout << L"\t     / ____/ / /_/ / /__/  __/ / / / /_/ / / /_/ /  __/ /    " << endl;
	wcout << L"\t    /_/   /_/\__,_/\___/\___/_/ /_/\____/_/\__,_/\___/_/     " << endl;



	int curMode = _setmode(_fileno(stdout), beforemode);

}


bool GameOverScene()
{


	while (true)
	{
		  system("cls");
		GameOverRender();
		
	}
	return true;
}

void GOInfoRender()
{
}

GOMENU MenuRender() {

}

GOKEY KeyController() {

}