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
RECT additionalRect = { 0 };
RECT viewRect = { 0 };

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
		shapes.clear(); // 도형 데이터 초기화

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
			shapes.clear();
			
			SetTimer(hWnd, 1, 100, NULL); // 타이머 시작
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				int blink = 1;
				HDC hdc = GetDC(hWnd);
				DrawBonobonoother(hWnd, hdc, blink);
				ReleaseDC(hWnd, hdc);
			}
			else {
				int blink = 1;
				HDC hdc = GetDC(hWnd);
				DrawBonobono(hWnd, hdc, blink);
				ReleaseDC(hWnd, hdc);
			}
			
		}
		else if (LOWORD(wParam) == 4) {
			shapes.clear();
			
			int left = 1;
			int top = 1;
			int right = 1;
			int bottom = 1;

			HDC hdc = GetDC(hWnd);
			DrawRyan(hWnd, hdc, left, top, right, bottom);  // left, top, right, bottom에 적절한 값을 전달
			ReleaseDC(hWnd, hdc);
			
		}
		else if (LOWORD(wParam) == 5) {
			shapes.clear(); // 도형 데이터 초기화
			isBoxVisible = true;
			isCircleMode = false; // 사각형 모드로 변경
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_TIMER:
		// 타이머가 발생하면 스페이스바를 누르고 있을 때 윙크하는 보노보노를 그림
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			int blink = 1;
			HDC hdc = GetDC(hWnd);
			DrawBonobonoother(hWnd, hdc, blink);
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

			int blink = 1;
			HDC hdc = GetDC(hWnd);
			DrawBonobonoother(hWnd, hdc, blink);
			ReleaseDC(hWnd, hdc);
		}
		break;
	case WM_KEYUP:
		if (wParam == VK_SPACE) {
			// 스페이스바가 떨어진 경우, 기본 보노보노 도형을 표시하도록 코드를 추가

			int blink = 1;
			HDC hdc = GetDC(hWnd);
			DrawBonobono(hWnd, hdc, blink);
			ReleaseDC(hWnd, hdc);
		}
		break;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT) {
			// 클라이언트 영역에 있을 때만 처리
			POINT cursorPos;
			GetCursorPos(&cursorPos);
			ScreenToClient(hWnd, &cursorPos);

			// 추가 테두리 설정
			additionalRect.left = (viewRect.right - viewRect.left - 650) / 2;
			additionalRect.top = (viewRect.bottom - viewRect.top - 280) / 2 + 30;
			additionalRect.right = additionalRect.left + 650;
			additionalRect.bottom = additionalRect.top + 280;

			if (PtInRect(&additionalRect, cursorPos)) {
				// 흰색 테두리 안에 있는 경우
				SetCursor(LoadCursor(NULL, IDC_CROSS));
				return TRUE; // 처리되었음을 알림
			}
			else {
				// 흰색 테두리 밖으로 나가면 기본 커서 모양으로 변경
				SetCursor(LoadCursor(NULL, IDC_ARROW));
				return TRUE; // 처리되었음을 알림
			}
		}
		break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// 클라이언트 영역의 크기를 viewRect에 저장
		GetClientRect(hWnd, &viewRect);

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
		L"BUTTON", L"cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
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