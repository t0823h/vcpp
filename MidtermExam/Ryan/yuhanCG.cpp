#include "yuhanCG.h"

void DrawBonobono(HWND hWnd, HDC hdc, int blink) {
    
	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;

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
	int blackX = 313; // 검은색 원의 중심 X 좌표
	int blackY = 204; // 검은색 원의 중심 Y 좌표
	Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
	DeleteObject(hBlackBrush);

	// 오른쪽 눈  그리기
	HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush2);
	int blackRadius2 = 6; // 검은색 원의 반지름 (작은 원)
	int blackX2 = 470; // 두 번째 검은색 원의 중심 X 좌표
	int blackY2 = 204; // 두 번째 검은색 원의 중심 Y 좌표
	Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
	DeleteObject(hBlackBrush2);

	// 왼쪽(하얀색)  눈  그리기
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteBrush);
	int whiteRadius = 3; // 검은색 원의 반지름 (작은 원)
	int whiteX = 313; // 두 번째 검은색 원의 중심 X 좌표
	int whiteY = 204; // 두 번째 검은색 원의 중심 Y 좌표
	Ellipse(hdc, whiteX - whiteRadius, whiteY - whiteRadius, whiteX + whiteRadius, whiteY + whiteRadius);
	DeleteObject(hWhiteBrush);

	// 오른쪽(하얀색)  눈  그리기
	HBRUSH hWhiteBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteBrush2);
	int whiteRadius2 = 3; // 검은색 원의 반지름 (작은 원)
	int whiteX2 = 470; // 두 번째 검은색 원의 중심 X 좌표
	int whiteY2 = 204; // 두 번째 검은색 원의 중심 Y 좌표
	Ellipse(hdc, whiteX2 - whiteRadius2, whiteY2 - whiteRadius2, whiteX2 + whiteRadius2, whiteY2 + whiteRadius2);
	DeleteObject(hWhiteBrush2);

	// 분홍색 입 그리기
	HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
	SelectObject(hdc, hPinkMouthBrush);
	int pinkMouthRadius = 17; // 분홍색 입의 반지름
	int pinkMouthX = 392; // 분홍색 입의 중심 X 좌표
	int pinkMouthY = 240; // 분홍색 입의 중심 Y 좌표
	Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
	DeleteObject(hPinkMouthBrush);

	// 흰색 코 그리기
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 17; // 흰색 코의 반지름
	int whiteNoseX = 378; // 흰색 코의 중심 X 좌표
	int whiteNoseY = 230; // 흰색 코의 중심 Y 좌표
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// 흰색 코2 그리기
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 17; // 흰색 코의 반지름
	int whiteNoseX2 = 407; // 흰색 코의 중심 X 좌표
	int whiteNoseY2 = 230; // 흰색 코의 중심 Y 좌표
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);


	// 코 그리기
	HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush3);
	int noseRadius = 13; // 코의 반지름
	Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
	DeleteObject(hBlackBrush3);

	// 첫번쨰 수염
	int startX1 = 373; // 흰색 코의 중심 X 좌표
	int startY1 = 234; // 흰색 코의 중심 Y 좌표
	int endX1 = 350; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY1 = 243; // 원하시는 Y 좌표로 설정
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

	// 네 번째 수염
	int startX4 = 407; // 시작점 X 좌표
	int startY4 = 228; // 시작점 Y 좌표
	int endX4 = 430;   // 끝점 X 좌표
	int endY4 = 220;   // 끝점 Y 좌표
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);

	ReleaseDC(hWnd, hdc);

}

void DrawBonobonoother(HWND hWnd, HDC hdc, int blink) {

	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;

	// 파란색 원 그리기
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(127, 200, 255));
	SelectObject(hdc, hBlueBrush);
	int radius = 100; // 원의 반지름
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	DeleteObject(hBlueBrush);

	// 왼쪽 눈1(직선)
	int startX5 = 323; // 흰색 코의 중심 X 좌표
	int startY5 = 204; // 흰색 코의 중심 Y 좌표
	int endX5 = 312; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY5 = 193; // 원하시는 Y 좌표로 설정
	MoveToEx(hdc, startX5, startY5, NULL);
	LineTo(hdc, endX5, endY5);

	// 왼쪽 눈2(직선)
	int startX6 = 323; // 흰색 코의 중심 X 좌표
	int startY6 = 204; // 흰색 코의 중심 Y 좌표
	int endX6 = 312; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY6 = 215; // 원하시는 Y 좌표로 설정
	MoveToEx(hdc, startX6, startY6, NULL);
	LineTo(hdc, endX6, endY6);

	// 오른쪽 눈1(직선)
	int startX7 = 460; // 흰색 코의 중심 X 좌표
	int startY7 = 204; // 흰색 코의 중심 Y 좌표
	int endX7 = 474; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY7 = 193; // 원하시는 Y 좌표로 설정
	MoveToEx(hdc, startX7, startY7, NULL);
	LineTo(hdc, endX7, endY7);

	// 오른쪽 눈2(직선)
	int startX8 = 460; // 흰색 코의 중심 X 좌표
	int startY8 = 204; // 흰색 코의 중심 Y 좌표
	int endX8 = 474; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY8 = 215; // 원하시는 Y 좌표로 설정
	MoveToEx(hdc, startX8, startY8, NULL);
	LineTo(hdc, endX8, endY8);

	// 분홍색 입 그리기
	HBRUSH hPinkMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
	SelectObject(hdc, hPinkMouthBrush);
	int pinkMouthRadius = 17; // 분홍색 입의 반지름
	int pinkMouthX = 392; // 분홍색 입의 중심 X 좌표
	int pinkMouthY = 240; // 분홍색 입의 중심 Y 좌표
	Ellipse(hdc, pinkMouthX - pinkMouthRadius, pinkMouthY - pinkMouthRadius * 2, pinkMouthX + pinkMouthRadius, pinkMouthY + pinkMouthRadius * 2);
	DeleteObject(hPinkMouthBrush);

	// 흰색 코 그리기
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 17; // 흰색 코의 반지름
	int whiteNoseX = 378; // 흰색 코의 중심 X 좌표
	int whiteNoseY = 230; // 흰색 코의 중심 Y 좌표
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// 흰색 코2 그리기
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 17; // 흰색 코의 반지름
	int whiteNoseX2 = 407; // 흰색 코의 중심 X 좌표
	int whiteNoseY2 = 230; // 흰색 코의 중심 Y 좌표
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);


	// 코 그리기
	HBRUSH hBlackBrush3 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush3);
	int noseRadius = 13; // 코의 반지름
	Ellipse(hdc, centerX - noseRadius, centerY - noseRadius, centerX + noseRadius, centerY + noseRadius);
	DeleteObject(hBlackBrush3);

	// 첫번쨰 수염
	int startX1 = 373; // 흰색 코의 중심 X 좌표
	int startY1 = 234; // 흰색 코의 중심 Y 좌표
	int endX1 = 350; // 흰색 코의 중심 X 좌표 (직선이 수직이므로 X 좌표는 같습니다)
	int endY1 = 243; // 원하시는 Y 좌표로 설정
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

	// 네 번째 수염
	int startX4 = 407; // 시작점 X 좌표
	int startY4 = 228; // 시작점 Y 좌표
	int endX4 = 430;   // 끝점 X 좌표
	int endY4 = 220;   // 끝점 Y 좌표
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);


	ReleaseDC(hWnd, hdc);

}


void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {

	RECT viewRect;
	GetClientRect(hWnd, &viewRect);
	int centerX = (viewRect.left + viewRect.right) / 2;
	int centerY = (viewRect.top + viewRect.bottom) / 2;
	

	// 노란색 원 그리기
	HBRUSH hyellowBrush = CreateSolidBrush(RGB(255, 200, 0));
	SelectObject(hdc, hyellowBrush);
	int yellowRadius = 37;
	int yellowCenterX = 330;
	int yellowCenterY = 130 + 20;  // y좌표를 20 올림
	Ellipse(hdc, yellowCenterX - yellowRadius, yellowCenterY - yellowRadius, yellowCenterX + yellowRadius, yellowCenterY + yellowRadius);
	DeleteObject(hyellowBrush);

	// 노란색 원 그리기
	HBRUSH hYellowBrush2 = CreateSolidBrush(RGB(255, 200, 0));
	SelectObject(hdc, hYellowBrush2);
	int yellowRadius2 = 37;
	int yellowCenterX2 = 460;
	int yellowCenterY2 = 130 + 20;  // y좌표를 20 올림
	Ellipse(hdc, yellowCenterX2 - yellowRadius2, yellowCenterY2 - yellowRadius2, yellowCenterX2 + yellowRadius2, yellowCenterY2 + yellowRadius2);
	DeleteObject(hYellowBrush2);

	// 얼굴 그리기
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(255, 200, 15));
	SelectObject(hdc, hBlueBrush);
	int radius = 100; // 원의 반지름
	Ellipse(hdc, centerX - radius, centerY - radius + 20, centerX + radius, centerY + radius + 20);  // y좌표를 20 올림
	DeleteObject(hBlueBrush);

	// 흰색 코 그리기
	HBRUSH hWhiteNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush);
	int whiteNoseRadius = 13; // 흰색 코의 반지름
	int whiteNoseX = 381;
	int whiteNoseY = 230 + 20;  // y좌표를 20 올림
	Ellipse(hdc, whiteNoseX - whiteNoseRadius, whiteNoseY - whiteNoseRadius, whiteNoseX + whiteNoseRadius, whiteNoseY + whiteNoseRadius);
	DeleteObject(hWhiteNoseBrush);

	// 흰색 코2 그리기
	HBRUSH hWhiteNoseBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hWhiteNoseBrush2);
	int whiteNoseRadius2 = 13; // 흰색 코의 반지름
	int whiteNoseX2 = 404;
	int whiteNoseY2 = 230 + 20;  // y좌표를 20 올림
	Ellipse(hdc, whiteNoseX2 - whiteNoseRadius2, whiteNoseY2 - whiteNoseRadius2, whiteNoseX2 + whiteNoseRadius2, whiteNoseY2 + whiteNoseRadius2);
	DeleteObject(hWhiteNoseBrush2);

	// 왼쪽 눈 그리기
	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush);
	int blackRadius = 6; // 검은색 원의 반지름 (작은 원)
	int blackX = 343;
	int blackY = 204 + 20;  // y좌표를 20 올림
	Ellipse(hdc, blackX - blackRadius, blackY - blackRadius, blackX + blackRadius, blackY + blackRadius);
	DeleteObject(hBlackBrush);

	// 오른쪽 눈 그리기
	HBRUSH hBlackBrush2 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush2);
	int blackRadius2 = 6; // 검은색 원의 반지름 (작은 원)
	int blackX2 = 440;
	int blackY2 = 204 + 20;  // y좌표를 20 올림
	Ellipse(hdc, blackX2 - blackRadius2, blackY2 - blackRadius2, blackX2 + blackRadius2, blackY2 + blackRadius2);
	DeleteObject(hBlackBrush2);

	// 눈썹
	int startX4 = 427;
	int startY4 = 185 + 20;  // y좌표를 20 올림
	int endX4 = 450;
	int endY4 = 185 + 20;  // y좌표를 20 올림
	MoveToEx(hdc, startX4, startY4, NULL);
	LineTo(hdc, endX4, endY4);

	// 눈썹
	int startX3 = 327;
	int startY3 = 185 + 20;  // y좌표를 20 올림
	int endX3 = 350;
	int endY3 = 185 + 20;  // y좌표를 20 올림
	MoveToEx(hdc, startX3, startY3, NULL);
	LineTo(hdc, endX3, endY3);



	ReleaseDC(hWnd, hdc);


}