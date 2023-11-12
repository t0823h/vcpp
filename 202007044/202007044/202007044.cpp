#include <windows.h>
#include <vector>

struct Shape {
    RECT rect;
    COLORREF color;
    bool isCircle;

    Shape() : isCircle(false) {}
};

bool isBoxVisible = false;
bool isSecondBoxVisible = false; // 두 번째 박스를 보여줄지 여부
bool isCircleMode = false;
std::vector<Shape> shapes;
POINT startPoint = { 0 };
POINT endPoint = { 0 };
int isMouseLButtonPressed = 0;
Shape* selectedShape = nullptr;
POINT prevMousePos = { 0 };
bool isDragging = false;

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
            isSecondBoxVisible = false; // 첫 번째 박스 버튼 클릭 시, 두 번째 박스는 보이지 않도록 설정
            isCircleMode = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            isBoxVisible = true;
            isSecondBoxVisible = false; // 두 번째 박스 버튼 클릭 시, 두 번째 박스는 보이지 않도록 설정
            isCircleMode = true;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 3) {
            isSecondBoxVisible = true; // 세 번째 버튼 클릭 시, 두 번째 박스를 보이도록 설정
            // 여기서 두 번째 박스의 위치와 크기 설정
            // 예: 가로 700, 세로 300 및 위치는 버튼 아래에
            RECT secondBoxRect;
            secondBoxRect.left = 30; // 시작 x 위치
            secondBoxRect.top = 180; // 시작 y 위치 (버튼 바로 아래)
            secondBoxRect.right = 30 + 700; // 가로 크기 (시작 x 위치 + 가로 크기)
            secondBoxRect.bottom = 180 + 300; // 세로 크기 (시작 y 위치 + 세로 크기)
            HBRUSH hSecondBoxBrush = CreateSolidBrush(RGB(0, 0, 0));
            FrameRect(GetDC(hWnd), &secondBoxRect, hSecondBoxBrush);
            DeleteObject(hSecondBoxBrush);
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
        viewRect.left += margin;
        viewRect.top += margin;
        viewRect.right -= margin;
        viewRect.bottom -= margin;
        viewRect.left += padding;
        viewRect.top += padding;
        viewRect.right -= padding;
        viewRect.bottom -= padding;

        // 테두리 그리기
        HBRUSH hBorderBrush = CreateSolidBrush(RGB(0, 0, 0));
        FrameRect(hdc, &viewRect, hBorderBrush);
        DeleteObject(hBorderBrush);

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

        if (isSecondBoxVisible) {
            // 두 번째 박스를 그리는 부분
            RECT secondBoxRect;
            secondBoxRect.left = 30;
            secondBoxRect.top = 180;
            secondBoxRect.right = 30 + 700;
            secondBoxRect.bottom = 180 + 300;
            HBRUSH hSecondBoxBrush = CreateSolidBrush(RGB(0, 0, 0));
            FrameRect(hdc, &secondBoxRect, hSecondBoxBrush);
            DeleteObject(hSecondBoxBrush);
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
        L"BUTTON", L"버튼3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        330, 20, 120, 64, hWnd, (HMENU)3, hInstance, NULL);

    HWND hButton4 = CreateWindow(
        L"BUTTON", L"버튼4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
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