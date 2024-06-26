#include"TitleScene.h"
#include"define.h"
#include<fcntl.h>
#include<corecrt_io.h>

char halka[4] = { '|', '/', '-', '\\' };
int loop;

void TitleRender() {
	int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << "\n\n\n\n";
	wcout << L"\t        ____  __                __          __    __         " << endl;
	wcout << L"\t       / __ \/ /___ _________  / /_  ____  / /___/ /__  _____" << endl;
	wcout << L"\t      / /_/ / / __ `/ ___/ _ \/ __ \/ __ \/ / __  / _ \/ ___/" << endl;
	wcout << L"\t     / ____/ / /_/ / /__/  __/ / / / /_/ / / /_/ /  __/ /    " << endl;
	wcout << L"\t    /_/   /_/\__,_/\___/\___/_/ /_/\____/_/\__,_/\___/_/     " << endl;



	int curMode = _setmode(_fileno(stdout), beforemode);
}

bool TitleScene()
{


	while (true)
	{
		/*deltaTime = clock() - oldTime;
		double fps = (1.0 / deltaTime) * 1000;
		oldTime = clock();*/


		system("cls");
		TitleRender();
		MENU eMenu = MenuRender();
		system("cls");
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
		}
	}
}

void InfoRender()
{
	cout << "[조작법]" << endl;
	//얘가 계속 출력
	//되어있는 상태여야함.
	//스페이스 눌리면 나가져.
	Sleep(100);
	while (true) {
		if (KeyController() == KEY::SPACE)
		{
			break;
		}
	}

	system("cls");
	TitleRender();
}

MENU MenuRender()
{
	double deltaTime, oldTime = clock();
	loop = 0;

	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.3;
	int y = Resolution.Y / 2.3;
	int top = y;
	int bottom = y + 2;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "게임 종료";

	Gotoxy(x - 2, y);
	cout << halka[loop];
	Sleep(100);
	while (true) {
		if (100 < clock() - oldTime) {
			oldTime = clock();
			++loop;
			if (loop > 3)
				loop = 0;
		}
		Gotoxy(x - 2, y);
		cout << halka[loop];
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (!(y - 1 < top)) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << halka[loop];
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (!(y + 1 > bottom)) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << halka[loop];
				Sleep(100);
			}
			break;
		case KEY::SPACE:
			if (y == top) {
				return MENU::START;
			}
			if (y == top + 1) {
				return MENU::INFO;
			}
			if (y == top + 2) {
				return MENU::QUIT;
			}
			break;
		}
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		return KEY::SPACE;
	}
	return KEY::_;
	//return KEY();
}

void EnterAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int anitime = 25;
	system("cls");
}