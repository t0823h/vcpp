#include "yuhanCG.h"

#include <windows.h>
#include <vector>

// �Լ� ����
void DrawBonobono(HWND hWnd, HDC hdc, int centerX, int centerY, int blink) {
    // �Ķ��� �� �׸���
    HBRUSH hBlueBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBlueBrush);
    int radius = 100; // ���� ������
    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
    DeleteObject(hBlueBrush);

    // ���� �� �׸���
    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush);
    int blackRadius = 6; // ������ ���� ������ (���� ��)
    int blackX = centerX - 50; // ������ ���� �߽� X ��ǥ
    int blackY = centerY - 30; // ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
    DeleteObject(hBlackBrush);

    // ������ �� �׸���
    HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush2);
    int blackRadius2 = 6; // ������ ���� ������ (���� ��)
    int blackX2 = centerX + 50; // �� ��° ������ ���� �߽� X ��ǥ
    int blackY2 = centerY - 30; // �� ��° ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
    DeleteObject(hBlackBrush2);

    // ����(�Ͼ��) �� �׸���
    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush);
    int whiteRadius = 3; // �Ͼ�� ���� ������ (���� ��)
    int whiteX = centerX - 50; // �� ��° ������ ���� �߽� X ��ǥ
    int whiteY = centerY - 30; // �� ��° ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteX - whiteRadius, whiteY - whiteRadius, whiteX + whiteRadius, whiteY + whiteRadius);
    DeleteObject(hWhiteBrush);

    // ������(�Ͼ��) �� �׸���
    HBRUSH hWhiteBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush2);
    int whiteRadius2 = 3; // �Ͼ�� ���� ������ (���� ��)
    int whiteX2 = centerX + 50; // �� ��° ������ ���� �߽� X ��ǥ
    int whiteY2 = centerY - 30; // �� ��° ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteX2 - whiteRadius2, whiteY2 - whiteRadius2, whiteX2 + whiteRadius2, whiteY2 + whiteRadius2);
    DeleteObject(hWhiteBrush2);

    // ��ȫ�� �� �׸���
    HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hPinkMouthBrush);
    int pinkMouthRadius = 17; // ��ȫ�� ���� ������
    int pinkMouthX = centerX; // ��ȫ�� ���� �߽� X ��ǥ
    int pinkMouthY = centerY + 40; // ��ȫ�� ���� �߽� Y ��ǥ
    Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
    DeleteObject(hPinkMouthBrush);

    // ��� �� �׸���
    HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush);
    int whiteNoseRadius = 17; // ��� ���� ������
    int whiteNoseX = centerX; // ��� ���� �߽� X ��ǥ
    int whiteNoseY = centerY + 20; // ��� ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
    DeleteObject(hWhiteNoseBrush);

    // ��� ��2 �׸���
    HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush2);
    int whiteNoseRadius2 = 17; // ��� ���� ������
    int whiteNoseX2 = centerX + 30; // ��� ���� �߽� X ��ǥ
    int whiteNoseY2 = centerY + 20; // ��� ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
    DeleteObject(hWhiteNoseBrush2);

    // �� �׸���
    HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush3);
    int noseRadius = 13; // ���� ������
    Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
    DeleteObject(hBlackBrush3);

    // ù��° ����
    int startX1 = centerX; // ��� ���� �߽� X ��ǥ
    int startY1 = centerY + 10; // ��� ���� �߽� Y ��ǥ
    int endX1 = centerX - 20; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
    int endY1 = centerY + 20; // ���Ͻô� Y ��ǥ�� ����
    MoveToEx(hdc, startX1, startY1, NULL);
    LineTo(hdc, endX1, endY1);

    // �� ��° ����
    int startX2 = 373; // ������ X ��ǥ
    int startY2 = 228; // ������ Y ��ǥ
    int endX2 = 350;   // ���� X ��ǥ
    int endY2 = 220;   // ���� Y ��ǥ
    MoveToEx(hdc, startX2, startY2, NULL);
    LineTo(hdc, endX2, endY2);

    // �� ��° ����
    int startX3 = 407; // ������ X ��ǥ
    int startY3 = 234; // ������ Y ��ǥ
    int endX3 = 430;   // ���� X ��ǥ
    int endY3 = 243;   // ���� Y ��ǥ
    MoveToEx(hdc, startX3, startY3, NULL);
    LineTo(hdc, endX3, endY3);

    // �� ��° ���� �׸���
    int startX4 = 407; // ������ X ��ǥ
    int startY4 = 228; // ������ Y ��ǥ
    int endX4 = 430;   // ���� X ��ǥ
    int endY4 = 220;   // ���� Y ��ǥ
    MoveToEx(hdc, startX4, startY4, NULL);
    LineTo(hdc, endX4, endY4);

    // ���÷� �� ������(blink)�̶�� ���� Ȱ��
    if (blink) {
        // �� ���� ���¸� �׸� �� �ִ� �۾� �߰�

        // ���� �� ���� ���� �׸���
        HBRUSH hClosedEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hClosedEyeBrush);
        int closedEyeRadius = 6; // ���� ���� ������ (���� ��)
        int closedEyeX = centerX - 50; // ���� ���� �߽� X ��ǥ
        int closedEyeY = centerY - 30; // ���� ���� �߽� Y ��ǥ
        Ellipse(hdc, closedEyeX - closedEyeRadius, closedEyeY - closedEyeRadius, closedEyeX + closedEyeRadius, closedEyeY + closedEyeRadius);
        DeleteObject(hClosedEyeBrush);

        // ������ �� ���� ���� �׸���
        HBRUSH hClosedEyeBrush2 = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hClosedEyeBrush2);
        int closedEyeRadius2 = 6; // ���� ���� ������ (���� ��)
        int closedEyeX2 = centerX + 50; // ���� ���� �߽� X ��ǥ
        int closedEyeY2 = centerY - 30; // ���� ���� �߽� Y ��ǥ
        Ellipse(hdc, closedEyeX2 - closedEyeRadius2, closedEyeY2 - closedEyeRadius2, closedEyeX2 + closedEyeRadius2, closedEyeY2 + closedEyeRadius2);
        DeleteObject(hClosedEyeBrush2);
    }
}

int centerX;
int centerY;

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {



    // ����� �� �׸���
    HBRUSH hyellowBrush = CreateSolidBrush(RGB(255, 200, 0));
    SelectObject(hdc, hyellowBrush);
    int yellowRadius = 37;
    int yellowCenterX = 330;
    int yellowCenterY = 130;
    Ellipse(hdc, yellowCenterX - yellowRadius, yellowCenterY - yellowRadius, yellowCenterX + yellowRadius, yellowCenterY + yellowRadius);
    DeleteObject(hyellowBrush);

    // ����� �� �׸���
    HBRUSH hYellowBrush2 = CreateSolidBrush(RGB(255, 200, 0));
    SelectObject(hdc, hYellowBrush2);
    int yellowRadius2 = 37;
    int yellowCenterX2 = 460;
    int yellowCenterY2 = 130;
    Ellipse(hdc, yellowCenterX2 - yellowRadius2, yellowCenterY2 - yellowRadius2, yellowCenterX2 + yellowRadius2, yellowCenterY2 + yellowRadius2);
    DeleteObject(hYellowBrush2);



    

    HBRUSH hBlueBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBlueBrush);
    int radius = 100; // ���� ������
    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
    DeleteObject(hBlueBrush);


    HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush);
    int whiteNoseRadius = 13; // ��� ���� ������
    int whiteNoseX = 381; // ��� ���� �߽� X ��ǥ
    int whiteNoseY = 230; // ��� ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
    DeleteObject(hWhiteNoseBrush);


    HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteNoseBrush2);
    int whiteNoseRadius2 = 13; // ��� ���� ������
    int whiteNoseX2 = 404; // ��� ���� �߽� X ��ǥ
    int whiteNoseY2 = 230; // ��� ���� �߽� Y ��ǥ
    Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
    DeleteObject(hWhiteNoseBrush2);


    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush);
    int blackRadius = 6; // ������ ���� ������ (���� ��)
    int blackX = 343; // ������ ���� �߽� X ��ǥ
    int blackY = 204; // ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
    DeleteObject(hBlackBrush);


    HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBlackBrush2);
    int blackRadius2 = 6; // ������ ���� ������ (���� ��)
    int blackX2 = 440; // �� ��° ������ ���� �߽� X ��ǥ
    int blackY2 = 204; // �� ��° ������ ���� �߽� Y ��ǥ
    Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
    DeleteObject(hBlackBrush2);

    // ����
    int startX4 = 427; // ������ X ��ǥ
    int startY4 = 185; // ������ Y ��ǥ
    int endX4 = 450;   // ���� X ��ǥ
    int endY4 = 185;   // ���� Y ��ǥ
    MoveToEx(hdc, startX4, startY4, NULL);
    LineTo(hdc, endX4, endY4);

    // ����2
    int startX3 = 327; // ������ X ��ǥ
    int startY3 = 185; // ������ Y ��ǥ
    int endX3 = 350;   // ���� X ��ǥ
    int endY3 = 185;   // ���� Y ��ǥ
    MoveToEx(hdc, startX3, startY3, NULL);
    LineTo(hdc, endX3, endY3);





}