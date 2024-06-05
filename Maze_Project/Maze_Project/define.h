#pragma once
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;
#include<Windows.h>
#define GET_SINGLE(c) c::GetInst();
#define DESTROYER(p) if (p != nullptr) {delete p;p = nullptr;}