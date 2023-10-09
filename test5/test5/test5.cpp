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
        InvalidateRect(hwnd, NULL, TRUE);
    }
    break;

    case WM_RBUTTONDOWN:
    {
        isMouseRButtonPressed = 1;
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

        if (isMouseRButtonPressed && !IsRectEmpty(&dragRect))
        {
            dragRect.left += LOWORD(lParam) - startPoint.x;
            dragRect.top += HIWORD(lParam) - startPoint.y;
            dragRect.right += LOWORD(lParam) - startPoint.x;
            dragRect.bottom += HIWORD(lParam) - startPoint.y;
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