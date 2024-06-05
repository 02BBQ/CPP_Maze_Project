#pragma once
//GameManager
//Singleton Dynamic
//늦은 초기화
//객체 생성을 지연시켜 내가 필요한 시점에 초기화할 수 있게 하는 것
#include "define.h"

class Core
{
private:
	Core();
public:
	Player player;
public:
	bool Init();
	void Run();
	void Update();
	void Render();
public:
	static Core* GetInst() {
		if (m_pInst == nullptr)
			m_pInst = new Core;
		return m_pInst;
	}
	static void DestroyInst() {
		DESTROYER(m_pInst);
	}
private:
	static Core* m_pInst;
};

