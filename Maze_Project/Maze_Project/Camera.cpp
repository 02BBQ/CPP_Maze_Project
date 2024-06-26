#include "Camera.h"
#include "define.h"

void Camera::MoveCamera()
{
	
}

void Camera::CameraUpdate()
{
    Player* player = GET_SINGLE(Core)->player;
    static int cameraY = (topCam + bottomCam) / 2;

    int diff = player->tPos.y - cameraY;
    const int threshold = 4;

    if (abs(diff) >= threshold) {
        cameraY = Lerp(cameraY, player->tPos.y, 0.1f); // 보간 계수 0.1 사용
    }

    topCam = max(0, cameraY - 10);
    bottomCam = min(MAP_HEIGHT, cameraY + 10);
    if (cameraY - 10 < 0) {
        bottomCam = cameraY + 10 - (cameraY - 10);
    }

    Gotoxy(0, MAP_HEIGHT + 5);
    cout << "CameraY: " << cameraY;
}

int Camera::Lerp(int start, int end, float t) {
	return (int)(start + .16 * (end - start));
}