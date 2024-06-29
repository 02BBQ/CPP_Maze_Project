#include "Camera.h"
#include "define.h"

void Camera::MoveCamera()
{
    Player* player = GET_SINGLE(Core)->player;
    int cameraY = player->tPos.y;

    topCam = max(0, cameraY - 10);
    bottomCam = min(MAP_HEIGHT, cameraY + 10);
}

void Camera::CameraUpdate()
{
    Player* player = GET_SINGLE(Core)->player;
    static int cameraY = (topCam + bottomCam) / 2;

    int diff = player->tPos.y - cameraY;
    const int threshold = 3;

    if (abs(diff) >= threshold) {
        cameraY = player->tPos.y;//Lerp(cameraY, player->tPos.y, 0.1f); // 보간 계수 0.1 사용
    }

    topCam = max(0, cameraY - 10);
    bottomCam = cameraY + 10;//min(MAP_HEIGHT, cameraY + 10);
    /*if (cameraY - 10 < 0) {
        bottomCam = cameraY + 10 - (cameraY - 10);
    }*/
}

int Camera::Lerp(int start, int end, float t) {
	return (int)(start + t * (end - start));
}