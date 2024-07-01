#include "Core.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{
    player = new Player();
    camera = new Camera();
    score = 0;
    time = 0;
    delete_cam_count = 0;
    obstacle_render = true;
}

bool Core::Init()
{
    system("title Maze | mode con cols=140 lines=40");
    SetCursorVis(false, 1);
    LockResize();

    if (player != nullptr)
    {
        delete player;
        player = nullptr;
    }
    if (camera != nullptr)
    {
        delete camera;
        camera = nullptr;
    }

    if (player == nullptr) player = new Player();
    if (camera == nullptr) camera = new Camera();
    if (timer == nullptr)
        timer = new GameTimer();
    else
        timer->Init();

    score = 0;
    GET_SINGLE(MapManager)->obstacle_pos = 26;

    GET_SINGLE(MapManager)->Init("TestMap.txt");

    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_HEIGHT; ++j)
        {
            if (GET_SINGLE(MapManager)->arrMap[i][j] == (char)OBJ_TYPE::START)
                player->tPos = { j,i };
        }
    }

    return true;
}

void Core::Run()
{
    PlayBgm(TEXT("gamebgm.mp3"), 100);
    system("mode con cols=80 lines=40");
    while (!player->isDead)
    {
        Update();
        Gotoxy(0, 0);
        Render();
    }
}

void Core::Update()
{
    this->player->Move();
    this->timer->Update();
    this->camera->CameraUpdate();
    score += timer->GetDeltaTime();
    ObsTime();
}

void Core::Render()
{
    auto arrMap = GET_SINGLE(MapManager)->arrMap;
    Gotoxy(0, 6);

    for (int i = camera->topCam; i < camera->bottomCam - delete_cam_count; ++i)
    {
        for (int _ = 0; _ < (GetConsoleResolution().X) / 2 - MAP_WIDTH; ++_)
        {
            std::cout << " ";
        }
        /*SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::LIGHT_VIOLET);
        std::cout << "  ";*/
        SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            if (player->tPos.x == j && player->tPos.y == i)
            {
                SetColor((int)COLOR::LIGHT_YELLOW);
                std::cout << "※";
            }
            else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
            {
                SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLUE);
                std::cout << "  ";
            }
            else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
                std::cout << "  ";
            else if (arrMap[i][j] == (char)OBJ_TYPE::TRAIL)
            {
                SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::LIGHT_YELLOW);
                std::cout << "  ";
            }
            else if (arrMap[i][j] == (char)OBJ_TYPE::TRAIL2)
            {
                SetColor((int)COLOR::MINT, (int)COLOR::MINT);
                std::cout << "  ";
            }
            SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
        }

        SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
        std::cout << "\n";
    }
    
    if (obstacle_render)
    {
        GET_SINGLE(MapManager)->ObstacleRender();
    }
    
    /*Gotoxy(70, 22);
    std::cout << "Score: " << timer->GetGameTime() << "pos: " << player->tPos.y << endl
        << "b: " << camera->bottomCam;*/

}

void Core::ObsTime()
{
    // 이거 한번만 해야돼 ㅇㅋ 넌 알거야 자고 일어난 나
    if (abs(camera->bottomCam - player->tPos.y) >= 10)
    {
        obstacle_render = false;
        GET_SINGLE(MapManager)->obstacle_pos = 26;
        GET_SINGLE(MapManager)->DestoryObstacle(26);
    }
    else
    {
        obstacle_render = true;
        time += timer->GetDeltaTime();
        if (time >= 2.3)
        {
            delete_cam_count++;
            int* tpos = &GET_SINGLE(MapManager)->obstacle_pos;
            (*tpos)--;
            GET_SINGLE(MapManager)->DestoryObstacle(*tpos);
            time = 0;
        }
    }
}
