#include "yuhanCG.h"

void DrawBonobono(HWND hWnd, HDC hdc, int blink) {
    
	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;

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
	int blackX = 313; // ������ ���� �߽� X ��ǥ
	int blackY = 204; // ������ ���� �߽� Y ��ǥ
	Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
	DeleteObject(hBlackBrush);

	// ������ ��  �׸���
	HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush2);
	int blackRadius2 = 6; // ������ ���� ������ (���� ��)
	int blackX2 = 470; // �� ��° ������ ���� �߽� X ��ǥ
	int blackY2 = 204; // �� ��° ������ ���� �߽� Y ��ǥ
	Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
	DeleteObject(hBlackBrush2);

	// ����(�Ͼ��)  ��  �׸���
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteBrush);
	int whiteRadius = 3; // ������ ���� ������ (���� ��)
	int whiteX = 313; // �� ��° ������ ���� �߽� X ��ǥ
	int whiteY = 204; // �� ��° ������ ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteX - whiteRadius, whiteY - whiteRadius, whiteX + whiteRadius, whiteY + whiteRadius);
	DeleteObject(hWhiteBrush);

	// ������(�Ͼ��)  ��  �׸���
	HBRUSH hWhiteBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteBrush2);
	int whiteRadius2 = 3; // ������ ���� ������ (���� ��)
	int whiteX2 = 470; // �� ��° ������ ���� �߽� X ��ǥ
	int whiteY2 = 204; // �� ��° ������ ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteX2 - whiteRadius2, whiteY2 - whiteRadius2, whiteX2 + whiteRadius2, whiteY2 + whiteRadius2);
	DeleteObject(hWhiteBrush2);

	// ��ȫ�� �� �׸���
	HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
	SelectObject(hdc, hPinkMouthBrush);
	int pinkMouthRadius = 17; // ��ȫ�� ���� ������
	int pinkMouthX = 392; // ��ȫ�� ���� �߽� X ��ǥ
	int pinkMouthY = 240; // ��ȫ�� ���� �߽� Y ��ǥ
	Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
	DeleteObject(hPinkMouthBrush);

	// ��� �� �׸���
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 17; // ��� ���� ������
	int whiteNoseX = 378; // ��� ���� �߽� X ��ǥ
	int whiteNoseY = 230; // ��� ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// ��� ��2 �׸���
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 17; // ��� ���� ������
	int whiteNoseX2 = 407; // ��� ���� �߽� X ��ǥ
	int whiteNoseY2 = 230; // ��� ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);


	// �� �׸���
	HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush3);
	int noseRadius = 13; // ���� ������
	Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
	DeleteObject(hBlackBrush3);

	// ù���� ����
	int startX1 = 373; // ��� ���� �߽� X ��ǥ
	int startY1 = 234; // ��� ���� �߽� Y ��ǥ
	int endX1 = 350; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY1 = 243; // ���Ͻô� Y ��ǥ�� ����
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

	// �� ��° ����
	int startX4 = 407; // ������ X ��ǥ
	int startY4 = 228; // ������ Y ��ǥ
	int endX4 = 430;   // ���� X ��ǥ
	int endY4 = 220;   // ���� Y ��ǥ
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);

	ReleaseDC(hWnd, hdc);

}

void DrawBonobonoother(HWND hWnd, HDC hdc, int blink) {

	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;

	// �Ķ��� �� �׸���
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(127, 200, 255));
	SelectObject(hdc, hBlueBrush);
	int radius = 100; // ���� ������
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	DeleteObject(hBlueBrush);

	// ���� ��1(����)
	int startX5 = 323; // ��� ���� �߽� X ��ǥ
	int startY5 = 204; // ��� ���� �߽� Y ��ǥ
	int endX5 = 312; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY5 = 193; // ���Ͻô� Y ��ǥ�� ����
	MoveToEx(hdc, startX5, startY5, NULL);
	LineTo(hdc, endX5, endY5);

	// ���� ��2(����)
	int startX6 = 323; // ��� ���� �߽� X ��ǥ
	int startY6 = 204; // ��� ���� �߽� Y ��ǥ
	int endX6 = 312; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY6 = 215; // ���Ͻô� Y ��ǥ�� ����
	MoveToEx(hdc, startX6, startY6, NULL);
	LineTo(hdc, endX6, endY6);

	// ������ ��1(����)
	int startX7 = 460; // ��� ���� �߽� X ��ǥ
	int startY7 = 204; // ��� ���� �߽� Y ��ǥ
	int endX7 = 474; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY7 = 193; // ���Ͻô� Y ��ǥ�� ����
	MoveToEx(hdc, startX7, startY7, NULL);
	LineTo(hdc, endX7, endY7);

	// ������ ��2(����)
	int startX8 = 460; // ��� ���� �߽� X ��ǥ
	int startY8 = 204; // ��� ���� �߽� Y ��ǥ
	int endX8 = 474; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY8 = 215; // ���Ͻô� Y ��ǥ�� ����
	MoveToEx(hdc, startX8, startY8, NULL);
	LineTo(hdc, endX8, endY8);

	// ��ȫ�� �� �׸���
	HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
	SelectObject(hdc, hPinkMouthBrush);
	int pinkMouthRadius = 17; // ��ȫ�� ���� ������
	int pinkMouthX = 392; // ��ȫ�� ���� �߽� X ��ǥ
	int pinkMouthY = 240; // ��ȫ�� ���� �߽� Y ��ǥ
	Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
	DeleteObject(hPinkMouthBrush);

	// ��� �� �׸���
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 17; // ��� ���� ������
	int whiteNoseX = 378; // ��� ���� �߽� X ��ǥ
	int whiteNoseY = 230; // ��� ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// ��� ��2 �׸���
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 17; // ��� ���� ������
	int whiteNoseX2 = 407; // ��� ���� �߽� X ��ǥ
	int whiteNoseY2 = 230; // ��� ���� �߽� Y ��ǥ
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);


	// �� �׸���
	HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush3);
	int noseRadius = 13; // ���� ������
	Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
	DeleteObject(hBlackBrush3);

	// ù���� ����
	int startX1 = 373; // ��� ���� �߽� X ��ǥ
	int startY1 = 234; // ��� ���� �߽� Y ��ǥ
	int endX1 = 350; // ��� ���� �߽� X ��ǥ (������ �����̹Ƿ� X ��ǥ�� �����ϴ�)
	int endY1 = 243; // ���Ͻô� Y ��ǥ�� ����
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

	// �� ��° ����
	int startX4 = 407; // ������ X ��ǥ
	int startY4 = 228; // ������ Y ��ǥ
	int endX4 = 430;   // ���� X ��ǥ
	int endY4 = 220;   // ���� Y ��ǥ
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);


	ReleaseDC(hWnd, hdc);

}


void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {

	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;
	

	// ����� �� �׸���
	HBRUSH hyellowBrush = CreateSolidBrush(RGB(255, 200, 0));
	SelectObject(hdc, hyellowBrush);
	int yellowRadius = 37;
	int yellowCenterX = 330;
	int yellowCenterY = 130 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, yellowCenterX - yellowRadius, yellowCenterY - yellowRadius, yellowCenterX + yellowRadius, yellowCenterY + yellowRadius);
	DeleteObject(hyellowBrush);

	// ����� �� �׸���
	HBRUSH hYellowBrush2 = CreateSolidBrush(RGB(255, 200, 0));
	SelectObject(hdc, hYellowBrush2);
	int yellowRadius2 = 37;
	int yellowCenterX2 = 460;
	int yellowCenterY2 = 130 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, yellowCenterX2 - yellowRadius2, yellowCenterY2 - yellowRadius2, yellowCenterX2 + yellowRadius2, yellowCenterY2 + yellowRadius2);
	DeleteObject(hYellowBrush2);

	// �� �׸���
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(255, 200, 15));
	SelectObject(hdc, hBlueBrush);
	int radius = 100; // ���� ������
	Ellipse(hdc, centerX - radius, centerY - radius + 20, centerX + radius, centerY + radius + 20);  // y��ǥ�� 20 �ø�
	DeleteObject(hBlueBrush);

	// ��� �� �׸���
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 13; // ��� ���� ������
	int whiteNoseX = 381;
	int whiteNoseY = 230 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// ��� ��2 �׸���
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 13; // ��� ���� ������
	int whiteNoseX2 = 404;
	int whiteNoseY2 = 230 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);

	// ���� �� �׸���
	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush);
	int blackRadius = 6; // ������ ���� ������ (���� ��)
	int blackX = 343;
	int blackY = 204 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
	DeleteObject(hBlackBrush);

	// ������ �� �׸���
	HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush2);
	int blackRadius2 = 6; // ������ ���� ������ (���� ��)
	int blackX2 = 440;
	int blackY2 = 204 + 20;  // y��ǥ�� 20 �ø�
	Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
	DeleteObject(hBlackBrush2);

	// ����
	int startX4 = 427;
	int startY4 = 185 + 20;  // y��ǥ�� 20 �ø�
	int endX4 = 450;
	int endY4 = 185 + 20;  // y��ǥ�� 20 �ø�
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);

	// ����
	int startX3 = 327;
	int startY3 = 185 + 20;  // y��ǥ�� 20 �ø�
	int endX3 = 350;
	int endY3 = 185 + 20;  // y��ǥ�� 20 �ø�
	MoveToEx(hdc, startX3, startY3, NULL);
	LineTo(hdc, endX3, endY3);



	ReleaseDC(hWnd, hdc);


}