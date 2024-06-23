#pragma once
#include "define.h"
class Player;
class Camera;
class GameTimer;

class MK_Core
{
private:
    MK_Core();
public:
    Player* player;
    Camera* camera;
    GameTimer* gameTime;
public:
    bool Init();
    void Run();
    void Update();
    void Render();
    void MoveMap();
public:
    static MK_Core* GetInst() {
        if (m_pInst == nullptr)
            m_pInst = new MK_Core;
        return m_pInst;
    }
    static void DestroyInst() {
        DESTROYER(m_pInst);
    }
private:
    static MK_Core* m_pInst;
};

