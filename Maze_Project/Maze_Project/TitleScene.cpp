#include"TitleScene.h"
#include"define.h"
#include<fcntl.h>
#include<corecrt_io.h>

void TitleRender() {
	int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);


	wcout << L"\t\t\t\t    ____  __                __          __    __         " << endl;
	wcout << L"\t\t\t\t   / __ \/ /___ _________  / /_  ____  / /___/ /__  _____" << endl;
	wcout << L"\t\t\t\t  / /_/ / / __ `/ ___/ _ \/ __ \/ __ \/ / __  / _ \/ ___/" << endl;
	wcout << L"\t\t\t\t / ____/ / /_/ / /__/  __/ / / / /_/ / / /_/ /  __/ /    " << endl;
	wcout << L"\t\t\t\t/_/   /_/\__,_/\___/\___/_/ /_/\____/_/\__,_/\___/_/     " << endl;



	int curMode = _setmode(_fileno(stdout), beforemode);
}

bool TitleScene()
{
	while (true)
	{
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
	cout << "[���۹� ]" << endl;
	//�갡 ��� ���
	//�Ǿ��ִ� ���¿�����.
	//�����̽� ������ ������.
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
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.25;
	int y = Resolution.Y / 3.5;
	int top = y;
	int bottom = y + 2;
	Gotoxy(x, y);
	cout << "���� ����";
	Gotoxy(x, y + 1);
	cout << "���� ����";
	Gotoxy(x, y + 2);
	cout << "���� ����";

	Gotoxy(x - 2, y);
	cout << ">";
	Sleep(100);
	while (true) {
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (!(y - 1 < top)) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (!(y + 1 > bottom)) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
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
	for (int i = 0; i < 6; ++i) {
		system("cls");
		Gotoxy(0, 0);
		SetColor(0, i % 2 == 0 ? (int)COLOR::WHITE : 0);
		system("cls");
		Sleep(anitime);
	}
	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < height; j += 2) {
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < height; j += 2) {
			Gotoxy(width - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");
}