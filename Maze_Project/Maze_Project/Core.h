#pragma once
#include "define.h"
class Player;
class Core
{
private:
    Core();
public:
    Player* player;
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
