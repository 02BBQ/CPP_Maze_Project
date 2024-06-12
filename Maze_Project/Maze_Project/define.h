#pragma once
#include<iostream>
#include<algorithm>
#include<fstream>
#include"Player.h";
#include"console.h"
#include"MapManager.h"
using std::cout;
using std::wcout;
using std::endl;
#include<Windows.h>
#define GET_SINGLE(c) c::GetInst()
#define DESTROYER(p) if (p != nullptr) {delete p;p = nullptr;}
//#include"Core.h";