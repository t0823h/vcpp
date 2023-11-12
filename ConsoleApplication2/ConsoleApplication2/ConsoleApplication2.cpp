﻿//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:windows")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif
//
//#include <windows.h>
//#include<stdio.h>
//
//POINT startPoint = { 0 };
//POINT endPoint = { 0 };
//int isMouseLButtonPressed = 0;
//int isMouseRButtonPressed = 0;
//RECT rect = { 0 };
//
//
//// 윈도우의 이벤트를 처리하는 콜백(Callback) 함수.
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_LBUTTONDOWN:
//	{
//		startPoint.x = LOWORD(lParam);
//		startPoint.y = HIWORD(lParam);
//		isMouseLButtonPressed = 1;
//		rect = { 0 };
//		InvalidateRect(hwnd, NULL, TRUE);
//	}
//	break;
//
//	//강의에 안나왔지만 마우스가 움직일때의 이벤트를 뜻합니다.
//	case WM_MOUSEMOVE:
//	{
//		// 마우스 이동 중
//		if (isMouseLButtonPressed)
//		{
//			endPoint.x = LOWORD(lParam);
//			endPoint.y = HIWORD(lParam);
//			rect.left = min(startPoint.x, endPoint.x);
//			rect.top = min(startPoint.y, endPoint.y);
//			rect.right = max(startPoint.x, endPoint.x);
//			rect.bottom = max(startPoint.y, endPoint.y);
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//
//		if (isMouseRButtonPressed && !IsRectEmpty(&rect)) {
//			rect.left += LOWORD(lParam) - startPoint.x;
//			rect.top += HIWORD(lParam) - startPoint.y;
//			rect.right += LOWORD(lParam) - startPoint.x;
//			rect.bottom += HIWORD(lParam) - startPoint.y;
//			startPoint.x = LOWORD(lParam);
//			startPoint.y = HIWORD(lParam);
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//	}
//	break;
//	case WM_LBUTTONUP:
//	{
//		endPoint.x = LOWORD(lParam);
//		endPoint.y = HIWORD(lParam);
//		isMouseLButtonPressed = 0;
//		InvalidateRect(hwnd, NULL, TRUE);
//	}
//	break;
//
//	case WM_RBUTTONDOWN:
//	{
//		POINT mousePos;
//		mousePos.x = LOWORD(lParam);
//		mousePos.y = HIWORD(lParam);
//
//		if (PtInRect(&rect, mousePos)) {
//			startPoint.x = LOWORD(lParam);
//			startPoint.y = HIWORD(lParam);
//			isMouseRButtonPressed = 1;
//		}
//		InvalidateRect(hwnd, NULL, TRUE);
//	}
//	break;
//
//	case WM_RBUTTONUP:
//	{
//		endPoint.x = LOWORD(lParam);
//		endPoint.y = HIWORD(lParam);
//		isMouseRButtonPressed = 0;
//		InvalidateRect(hwnd, NULL, TRUE);
//	}
//	break;
//
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hwnd, &ps);
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//
//		if (!IsRectEmpty(&rect))
//		{
//			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
//			FillRect(hdc, &rect, hBrush);
//			DeleteObject(hBrush);
//		}
//
//		EndPaint(hwnd, &ps);
//
//	}
//	break;
//
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//
//	return S_OK;
//}
//
//#ifdef UNICODE
//int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
//#else
//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
//#endif
//{
//	/* 윈도우 클래스 선언.*/
//	WNDCLASS wc;
//	ZeroMemory(&wc, sizeof(wc));	// 모두 0으로 초기화.
//
//	// 윈도우 클래스 값 설정
//	wc.hInstance = hInstance;
//	wc.lpszClassName = TEXT("Computer Software");
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WindowProc;
//
//	// 윈도우 클래스 등록.
//	if (RegisterClass(&wc) == 0)
//	{
//		MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
//		exit(-1);	//예외
//	}
//
//	// Window viewport 영역 조정
//	RECT rect = { 0, 0, 800, 600 };
//	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
//	int width = rect.right - rect.left;
//	int height = rect.bottom - rect.top;
//
//	// 윈도우 생성
//	HWND hwnd = CreateWindow(
//		wc.lpszClassName,
//		TEXT("202007061 백종빈"),
//		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,	// 창의 크기를 변경할 수 있는 테두리 삭제
//		0, 0,
//		width, height,
//		NULL, NULL,
//		hInstance,
//		NULL
//	);
//
//	// 오류 검사.
//	if (hwnd == NULL)
//	{
//		MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
//		exit(-1);
//	}
//
//	// 창 보이기.
//	ShowWindow(hwnd, SW_SHOW); // 창 띄우고
//	UpdateWindow(hwnd); // 업데이트해야 보임. 한 쌍으로 쓴다고 보면 됨.
//
//
//
//	// 메시지 처리 루프.
//	MSG msg;
//	ZeroMemory(&msg, sizeof(msg));
//
//	while (msg.message != WM_QUIT)
//	{
//		// 메시지 처리.
//		if (GetMessage(&msg, NULL, 0, 0))
//			//if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) // PM_REMOVE의 자리는 이 메세지를 쓰고 어떡할거냐.의 의미인데 지운다는 것임.
//		{
//
//			// 메시지 해석해줘.
//			TranslateMessage(&msg);
//			// 메시지를 처리해야할 곳에 전달해줘.
//			DispatchMessage(&msg);
//
//		}
//		/*else
//		{
//
//		}*/
//	}
//
//	//종료 메시지 보내기
//	return (int)msg.wParam;
//
//
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

POINT startPoint = { 0 };
POINT endPoint = { 0 };
int isMouseLButtonPressed = 0;
int isMouseRButtonPressed = 0;
RECT dragRect = { 0 };
RECT selectedRect = { 0 }; // 이동할 상자를 나타내는 변수

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    {
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
        isMouseLButtonPressed = 1;
        dragRect = { 0 };
        selectedRect = { 0 }; // 새로운 클릭으로 선택한 상자 초기화
        InvalidateRect(hwnd, NULL, TRUE);
    }
    break;

    case WM_RBUTTONDOWN:
    {
        POINT mousePos;
        mousePos.x = LOWORD(lParam);
        mousePos.y = HIWORD(lParam);

        // 클릭한 위치가 기존에 그린 상자 내부에 있는지 확인
        if (PtInRect(&dragRect, mousePos))
        {
            selectedRect = dragRect; // 선택된 상자를 설정
            isMouseRButtonPressed = 1;
        }
        InvalidateRect(hwnd, NULL, TRUE);
    }
    break;

    case WM_RBUTTONUP:
    {
        isMouseRButtonPressed = 0;
    }
    break;

    case WM_MOUSEMOVE:
    {
        if (isMouseLButtonPressed)
        {
            endPoint.x = LOWORD(lParam);
            endPoint.y = HIWORD(lParam);
            dragRect.left = min(startPoint.x, endPoint.x);
            dragRect.top = min(startPoint.y, endPoint.y);
            dragRect.right = max(startPoint.x, endPoint.x);
            dragRect.bottom = max(startPoint.y, endPoint.y);
            InvalidateRect(hwnd, NULL, TRUE);
        }

        if (isMouseRButtonPressed && !IsRectEmpty(&selectedRect))
        {
            selectedRect.left += LOWORD(lParam) - startPoint.x;
            selectedRect.top += HIWORD(lParam) - startPoint.y;
            selectedRect.right += LOWORD(lParam) - startPoint.x;
            selectedRect.bottom += HIWORD(lParam) - startPoint.y;
            startPoint.x = LOWORD(lParam);
            startPoint.y = HIWORD(lParam);
            InvalidateRect(hwnd, NULL, TRUE);
        }
    }
    break;

    case WM_LBUTTONUP:
    {
        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);
        isMouseLButtonPressed = 0;
        InvalidateRect(hwnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        if (!IsRectEmpty(&dragRect))
        {
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
            FillRect(hdc, &dragRect, hBrush);
            DeleteObject(hBrush);
        }
        if (!IsRectEmpty(&selectedRect))
        {
            HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255)); // 선택된 상자는 파란색으로 표시
            FillRect(hdc, &selectedRect, hBrush);
            DeleteObject(hBrush);
        }
        EndPaint(hwnd, &ps);
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

#ifdef UNICODE
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
#endif
{
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("Computer Software");
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;

    if (RegisterClass(&wc) == 0)
    {
        MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    int width = 600;
    int height = 800;

    HWND hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("202007044 조상훈"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        0, 0,
        width, height,
        NULL, NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (GetMessage(&msg, hwnd, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}