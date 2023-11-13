#include <windows.h>
#include <vector>
#include "yuhanCG.h"


struct Shape {
	RECT rect;
	COLORREF color;
	bool isCircle;

	Shape() : isCircle(false) {}
};

bool isBoxVisible = false;
bool isCircleMode = false;
std::vector<Shape> shapes;
POINT startPoint = { 0 };
POINT endPoint = { 0 };
int isMouseLButtonPressed = 0;
Shape* selectedShape = nullptr;
POINT prevMousePos = { 0 };
bool isDragging = false;

HDC hdc;

void DrawButtons(HWND hWnd) {
	HBRUSH hBoxBrush = CreateSolidBrush(RGB(192, 192, 192));
	RECT boxRect = { 20, 20, 180, 84 }; // 버튼 사이즈 조정
	FillRect(GetDC(hWnd), &boxRect, hBoxBrush);
	DeleteObject(hBoxBrush);
	SetTextColor(GetDC(hWnd), RGB(0, 0, 0));
	SetBkColor(GetDC(hWnd), RGB(192, 192, 192));
	TextOut(GetDC(hWnd), 30, 35, L"□", 2);

	HBRUSH hCircleBrush = CreateSolidBrush(RGB(192, 192, 192));
	RECT circleRect = { 220, 20, 380, 84 }; // 버튼 위치와 사이즈 조정
	FillRect(GetDC(hWnd), &circleRect, hCircleBrush);
	DeleteObject(hCircleBrush);
	SetTextColor(GetDC(hWnd), RGB(0, 0, 0));
	SetBkColor(GetDC(hWnd), RGB(192, 192, 192));
	TextOut(GetDC(hWnd), 230, 35, L"○", 2);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));

	switch (message) {
	case WM_CREATE:
		DrawButtons(hWnd);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == 1) {
			isBoxVisible = true;
			isCircleMode = false;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		else if (LOWORD(wParam) == 2) {
			isBoxVisible = true;
			isCircleMode = true;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		else if (LOWORD(wParam) == 3) {
			// 스페이스바를 눌렀을 때 타이머를 시작하여 주기적으로 화면을 갱신
			SetTimer(hWnd, 1, 100, NULL);  // 100ms 간격으로 타이머를 설정

			// 스페이스바가 눌려 있는지 확인
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				// 스페이스바가 눌려 있다면, 윙크하는 보노보노 도형을 표시
				RECT viewRect;
				GetClientRect(hWnd, &viewRect);
				int centerX = (viewRect.left + viewRect.right) / 2;
				int centerY = (viewRect.top + viewRect.bottom) / 2;

				// 파란색 원 그리기
				HDC hdc = GetDC(hWnd);
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
			else {

				RECT viewRect;
				GetClientRect(hWnd, &viewRect);
				int centerX = (viewRect.left + viewRect.right) / 2;
				int centerY = (viewRect.top + viewRect.bottom) / 2;

				// 파란색 원 그리기
				HDC hdc = GetDC(hWnd);
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
		}
		else if (LOWORD(wParam) == 4) {
			RECT viewRect;
			GetClientRect(hWnd, &viewRect);
			int centerX = (viewRect.left + viewRect.right) / 2;
			int centerY = (viewRect.top + viewRect.bottom) / 2;
			HDC hdc = GetDC(hWnd);

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

			// 얼굴
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
		break;
	case WM_TIMER:
		// 타이머가 발생하면 스페이스바를 누르고 있을 때 빨간색 도형을 그림
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {

			RECT viewRect;
			GetClientRect(hWnd, &viewRect);
			int centerX = (viewRect.left + viewRect.right) / 2;
			int centerY = (viewRect.top + viewRect.bottom) / 2;

			// 빨간색 원 그리기
			HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 원
			SelectObject(hdc, hRedBrush);
			int redRadius = 50; // 빨간색 원의 반지름
			int redCenterX = 400; // 빨간색 원의 중심 X 좌표
			int redCenterY = 300; // 빨간색 원의 중심 Y 좌표
			Ellipse(hdc, redCenterX - redRadius, redCenterY - redRadius, redCenterX + redRadius, redCenterY + redRadius);
			DeleteObject(hRedBrush);

			// 파란색 원 그리기
			HDC hdc = GetDC(hWnd);
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
		break;
	case WM_LBUTTONDOWN:
		if (isBoxVisible) {
			startPoint.x = LOWORD(lParam);
			startPoint.y = HIWORD(lParam);
			endPoint = startPoint;
			isMouseLButtonPressed = 1;
		}
		break;
	case WM_MOUSEMOVE:
		if (isMouseLButtonPressed) {
			endPoint.x = LOWORD(lParam);
			endPoint.y = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, TRUE);
		}

		if (isDragging && selectedShape) {
			int dx = LOWORD(lParam) - prevMousePos.x;
			int dy = HIWORD(lParam) - prevMousePos.y;
			selectedShape->rect.left += dx;
			selectedShape->rect.right += dx;
			selectedShape->rect.top += dy;
			selectedShape->rect.bottom += dy;
			prevMousePos.x = LOWORD(lParam);
			prevMousePos.y = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_LBUTTONUP:
		if (isMouseLButtonPressed) {
			endPoint.x = LOWORD(lParam);
			endPoint.y = HIWORD(lParam);
			isMouseLButtonPressed = 0;

			Shape shape;
			shape.rect.left = startPoint.x;
			shape.rect.top = startPoint.y;
			shape.rect.right = endPoint.x;
			shape.rect.bottom = endPoint.y;
			shape.color = RGB(255, 0, 0);
			shape.isCircle = isCircleMode;

			shapes.push_back(shape);
			InvalidateRect(hWnd, NULL, TRUE);
		}

		isDragging = false;
		break;
	case WM_RBUTTONDOWN:
		if (isBoxVisible) {
			int mouseX = LOWORD(lParam);
			int mouseY = HIWORD(lParam);
			selectedShape = nullptr;

			for (int i = shapes.size() - 1; i >= 0; --i) {
				if (PtInRect(&shapes[i].rect, POINT{ mouseX, mouseY })) {
					selectedShape = &shapes[i];
					prevMousePos.x = mouseX;
					prevMousePos.y = mouseY;
					isDragging = true;
					break;
				}
			}
		}
		break;
	case WM_RBUTTONUP:
		isDragging = false;
		break;
	case WM_KEYDOWN:
		if (wParam == VK_SPACE) {
			// 스페이스바가 눌렸을 때, 빨간색 도형을 표시
			RECT viewRect;
			GetClientRect(hWnd, &viewRect);
			int centerX = (viewRect.left + viewRect.right) / 2;
			int centerY = (viewRect.top + viewRect.bottom) / 2;

			// 파란색 원 그리기
			HDC hdc = GetDC(hWnd);
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
		break;
	case WM_KEYUP:
		if (wParam == VK_SPACE) {
			// 스페이스바가 떨어진 경우, 다른 도형을 표시하도록 코드를 추가

			RECT viewRect;
			GetClientRect(hWnd, &viewRect);
			int centerX = (viewRect.left + viewRect.right) / 2;
			int centerY = (viewRect.top + viewRect.bottom) / 2;

			// 파란색 원 그리기
			HDC hdc = GetDC(hWnd);
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
		break;
	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT) { // 커서가 클라이언트 영역에 있을 때
			SetCursor(LoadCursor(NULL, IDC_CROSS)); // CROSS 커서 모양으로 변경
			return TRUE; // 처리되었음을 알림
		}
		break;
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// 배경 색상 설정
		HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));
		FillRect(hdc, &ps.rcPaint, hBackgroundBrush);
		DeleteObject(hBackgroundBrush);

		// Margin 및 Padding 계산
		RECT viewRect;
		GetClientRect(hWnd, &viewRect);
		int margin = 8;
		int padding = 8;
		int additionalMargin = 0; // 추가 테두리 마진
		int additionalPadding = 0; // 추가 테두리 페딩

		// 원래의 테두리 설정
		RECT originalRect = viewRect;
		originalRect.left += margin;
		originalRect.top += margin;
		originalRect.right -= margin;
		originalRect.bottom -= margin;
		originalRect.left += padding;
		originalRect.top += padding;
		originalRect.right -= padding;
		originalRect.bottom -= padding;

		// 추가 테두리 설정 (가로 600, 세로 300, 가운데 위치)
		RECT additionalRect = viewRect;
		additionalRect.left = (viewRect.right - viewRect.left - 650) / 2;
		additionalRect.top = (viewRect.bottom - viewRect.top - 280) / 2 + 30;
		additionalRect.right = additionalRect.left + 650; // 가로 600
		additionalRect.bottom = additionalRect.top + 280; // 세로 300

		// 원래의 테두리 그리기
		HBRUSH hBorderBrush = CreateSolidBrush(RGB(0, 0, 0));
		FrameRect(hdc, &originalRect, hBorderBrush);
		DeleteObject(hBorderBrush);

		// 추가 테두리 그리기
		HBRUSH hAdditionalBackgroundBrush = CreateSolidBrush(RGB(255, 255, 255)); // 배경색 설정
		FillRect(hdc, &additionalRect, hAdditionalBackgroundBrush); // 배경색으로 채우기
		DeleteObject(hAdditionalBackgroundBrush);

		HBRUSH hAdditionalBorderBrush = CreateSolidBrush(RGB(0, 0, 0));
		FrameRect(hdc, &additionalRect, hAdditionalBorderBrush);
		DeleteObject(hAdditionalBorderBrush);

		if (isBoxVisible) {
			for (const Shape& shape : shapes) {
				HBRUSH hBrush = CreateSolidBrush(shape.color);
				SelectObject(hdc, hBrush);
				if (shape.isCircle) {
					Ellipse(hdc, shape.rect.left, shape.rect.top, shape.rect.right, shape.rect.bottom);
				}
				else {
					Rectangle(hdc, shape.rect.left, shape.rect.top, shape.rect.right, shape.rect.bottom);
				}
				DeleteObject(hBrush);
			}
		}

		if (isMouseLButtonPressed) {
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			if (isCircleMode) {
				Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			}
			else {
				Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			}
			DeleteObject(hBrush);
		}

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		DeleteObject(hBackgroundBrush);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
	HWND hWnd;
	HMENU hMenu = CreateMenu();
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"ButtonWindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);


	if (!RegisterClassEx(&wcex)) {
		return 1;
	}

	// 윈도우 사이즈 변경
	hWnd = CreateWindow(
		L"ButtonWindowClass", L"Win32 Button Example", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 800, 480, NULL, hMenu, hInstance, NULL);

	if (!hWnd) {
		return FALSE;
	}

	HWND hButton1 = CreateWindow(
		L"BUTTON", L"□", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		30, 20, 120, 64, hWnd, (HMENU)1, hInstance, NULL);

	HWND hButton2 = CreateWindow(
		L"BUTTON", L"○", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		180, 20, 120, 64, hWnd, (HMENU)2, hInstance, NULL);

	HWND hButton3 = CreateWindow(
		L"BUTTON", L"bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		330, 20, 120, 64, hWnd, (HMENU)3, hInstance, NULL);

	HWND hButton4 = CreateWindow(
		L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		480, 20, 120, 64, hWnd, (HMENU)4, hInstance, NULL);

	HWND hButton5 = CreateWindow(
		L"BUTTON", L"버튼5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		630, 20, 120, 64, hWnd, (HMENU)5, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}