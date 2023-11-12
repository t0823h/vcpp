#include "yuhanCG.h"

#include <windows.h>
#include <vector>

// 함수 구현
void DrawBonobono(HWND hWnd, HDC hdc, int centerX, int centerY, int blink) {
    // 파란색 원 그리기
    HBRUSH hBlueBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBlueBrush);
    int radius = 100; // 원의 반지름
    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
    DeleteObject(hBlueBrush);

    // 왼쪽 눈 그리기
    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush);
    int blackRadius = 6; // 검은색 원의 반지름 (작은 원)
    int blackX = centerX - 50; // 검은색 원의 중심 X 좌표
    int blackY = centerY - 30; // 검은색 원의 중심 Y 좌표
    Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
    DeleteObject(hBlackBrush);

    // 오른쪽 눈 그리기
    HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush2);
    int blackRadius2 = 6; // 검은색 원의 반지름 (작은 원)
    int blackX2 = centerX + 50; // 두 번째 검은색 원의 중심 X 좌표
    int blackY2 = centerY - 30; // 두 번째 검은색 원의 중심 Y 좌표
    Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
    DeleteObject(hBlackBrush2);

    // 왼쪽(하얀색) 눈 그리기
    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush);
    int whiteRadius = 3; // 하얀색 원의 반지름 (작은 원)
    int whiteX = centerX - 50; // 두 번째 검은색 원의 중심 X 좌표
    int whiteY = centerY - 30; // 두 번째 검은색 원의 중심 Y 좌표
    Ellipse(hdc, whiteX - whiteRadius, whiteY - whiteRadius, whiteX + whiteRadius, whiteY + whiteRadius);
    DeleteObject(hWhiteBrush);

    // 오른쪽(하얀색) 눈 그리기
    HBRUSH hWhiteBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush2);
    int whiteRadius2 = 3; // 하얀색 원의 반지름 (작은 원)
    int whiteX2 = centerX + 50; // 두 번째 검은색 원의 중심 X 좌표
    int whiteY2 = centerY - 30; // 두 번째 검은색 원의 중심 Y 좌표
    Ellipse(hdc, whiteX2 - whiteRadius2, whiteY2 - whiteRadius2, whiteX2 + whiteRadius2, whiteY2 + whiteRadius2);
    DeleteObject(hWhiteBrush2);

    // 분홍색 입 그리기
    HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hPinkMouthBrush);
    int pinkMouthRadius = 17; // 분홍색 입의 반지름
    int pinkMouthX = centerX; // 분홍색 입의 중심 X 좌표
    int pinkMouthY = centerY + 40; // 분홍색 입의 중심 Y 좌표
    Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
    DeleteObject(hPinkMouthBrush);

    // 흰색 코 그리기
    HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush);
    int whiteNoseRadius = 17; // 흰색 코의 반지름
    int whiteNoseX = centerX; // 흰색 코의 중심 X 좌표
    int whiteNoseY = centerY + 20; // 흰색 코의 중심 Y 좌표
    Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
    DeleteObject(hWhiteNoseBrush);

    // 흰색 코2 그리기
    HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush2);
    int whiteNoseRadius2 = 17; // 흰색 코의 반지름
    int whiteNoseX2 = centerX + 30; // 흰색 코의 중심 X 좌표
    int whiteNoseY2 = centerY + 20; // 흰색 코의 중심 Y 좌표
    Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
    DeleteObject(hWhiteNoseBrush2);

    // 코 그리기
    HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush3);
    int noseRadius = 13; // 코의 반지름
    Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
    DeleteObject(hBlackBrush3);

    // 첫번째 수염
    int startX1 = centerX; // 흰색 코의 중심 X 좌표
    int startY1 = centerY + 10; // 흰색 코의 중심 Y 좌표
    int endX1 = centerX - 20; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
    int endY1 = centerY + 20; // 원하시는 Y 좌표로 설정
    MoveToEx(hdc, startX1, startY1, NULL);
    LineTo(hdc, endX1, endY1);

    // 두 번째 수염
    int startX2 = 373; // 시작점 X 좌표
    int startY2 = 228; // 시작점 Y 좌표
    int endX2 = 350;   // 끝점 X 좌표
    int endY2 = 220;   // 끝점 Y 좌표
    MoveToEx(hdc, startX2, startY2, NULL);
    LineTo(hdc, endX2, endY2);

    // 세 번째 수염
    int startX3 = 407; // 시작점 X 좌표
    int startY3 = 234; // 시작점 Y 좌표
    int endX3 = 430;   // 끝점 X 좌표
    int endY3 = 243;   // 끝점 Y 좌표
    MoveToEx(hdc, startX3, startY3, NULL);
    LineTo(hdc, endX3, endY3);

    // 네 번째 수염 그리기
    int startX4 = 407; // 시작점 X 좌표
    int startY4 = 228; // 시작점 Y 좌표
    int endX4 = 430;   // 끝점 X 좌표
    int endY4 = 220;   // 끝점 Y 좌표
    MoveToEx(hdc, startX4, startY4, NULL);
    LineTo(hdc, endX4, endY4);

    // 예시로 눈 깜빡임(blink)이라는 변수 활용
    if (blink) {
        // 눈 감은 상태를 그릴 수 있는 작업 추가

        // 왼쪽 눈 감은 상태 그리기
        HBRUSH hClosedEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hClosedEyeBrush);
        int closedEyeRadius = 6; // 감은 눈의 반지름 (작은 원)
        int closedEyeX = centerX - 50; // 감은 눈의 중심 X 좌표
        int closedEyeY = centerY - 30; // 감은 눈의 중심 Y 좌표
        Ellipse(hdc, closedEyeX - closedEyeRadius, closedEyeY - closedEyeRadius, closedEyeX + closedEyeRadius, closedEyeY + closedEyeRadius);
        DeleteObject(hClosedEyeBrush);

        // 오른쪽 눈 감은 상태 그리기
        HBRUSH hClosedEyeBrush2 = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hClosedEyeBrush2);
        int closedEyeRadius2 = 6; // 감은 눈의 반지름 (작은 원)
        int closedEyeX2 = centerX + 50; // 감은 눈의 중심 X 좌표
        int closedEyeY2 = centerY - 30; // 감은 눈의 중심 Y 좌표
        Ellipse(hdc, closedEyeX2 - closedEyeRadius2, closedEyeY2 - closedEyeRadius2, closedEyeX2 + closedEyeRadius2, closedEyeY2 + closedEyeRadius2);
        DeleteObject(hClosedEyeBrush2);
    }
}

int centerX;
int centerY;

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {



    // 노란색 원 그리기
    HBRUSH hyellowBrush = CreateSolidBrush(RGB(255, 200, 0));
    SelectObject(hdc, hyellowBrush);
    int yellowRadius = 37;
    int yellowCenterX = 330;
    int yellowCenterY = 130;
    Ellipse(hdc, yellowCenterX - yellowRadius, yellowCenterY - yellowRadius, yellowCenterX + yellowRadius, yellowCenterY + yellowRadius);
    DeleteObject(hyellowBrush);

    // 노란색 원 그리기
    HBRUSH hYellowBrush2 = CreateSolidBrush(RGB(255, 200, 0));
    SelectObject(hdc, hYellowBrush2);
    int yellowRadius2 = 37;
    int yellowCenterX2 = 460;
    int yellowCenterY2 = 130;
    Ellipse(hdc, yellowCenterX2 - yellowRadius2, yellowCenterY2 - yellowRadius2, yellowCenterX2 + yellowRadius2, yellowCenterY2 + yellowRadius2);
    DeleteObject(hYellowBrush2);



    

    HBRUSH hBlueBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBlueBrush);
    int radius = 100; // 원의 반지름
    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
    DeleteObject(hBlueBrush);


    HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush);
    int whiteNoseRadius = 13; // 흰색 코의 반지름
    int whiteNoseX = 381; // 흰색 코의 중심 X 좌표
    int whiteNoseY = 230; // 흰색 코의 중심 Y 좌표
    Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
    DeleteObject(hWhiteNoseBrush);


    HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush2);
    int whiteNoseRadius2 = 13; // 흰색 코의 반지름
    int whiteNoseX2 = 404; // 흰색 코의 중심 X 좌표
    int whiteNoseY2 = 230; // 흰색 코의 중심 Y 좌표
    Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
    DeleteObject(hWhiteNoseBrush2);


    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush);
    int blackRadius = 6; // 검은색 원의 반지름 (작은 원)
    int blackX = 343; // 검은색 원의 중심 X 좌표
    int blackY = 204; // 검은색 원의 중심 Y 좌표
    Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
    DeleteObject(hBlackBrush);


    HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush2);
    int blackRadius2 = 6; // 검은색 원의 반지름 (작은 원)
    int blackX2 = 440; // 두 번째 검은색 원의 중심 X 좌표
    int blackY2 = 204; // 두 번째 검은색 원의 중심 Y 좌표
    Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
    DeleteObject(hBlackBrush2);

    // 눈썹
    int startX4 = 427; // 시작점 X 좌표
    int startY4 = 185; // 시작점 Y 좌표
    int endX4 = 450;   // 끝점 X 좌표
    int endY4 = 185;   // 끝점 Y 좌표
    MoveToEx(hdc, startX4, startY4, NULL);
    LineTo(hdc, endX4, endY4);

    // 눈썹2
    int startX3 = 327; // 시작점 X 좌표
    int startY3 = 185; // 시작점 Y 좌표
    int endX3 = 350;   // 끝점 X 좌표
    int endY3 = 185;   // 끝점 Y 좌표
    MoveToEx(hdc, startX3, startY3, NULL);
    LineTo(hdc, endX3, endY3);





}