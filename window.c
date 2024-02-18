#include "window.h"

#include "character.h"
#include "gamestate.h"

const char g_szClassName[] = "test";
const int windowWidth = 1280;
const int windowHeight = 768;
const int gridWidth = 1200;
const int gridHeight = 720;
const int tileWidth = 48;
const int tileHeight = 48;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND g_hwnd = NULL;

BOOL InitializeWindow(const HINSTANCE hInstance, const int nCmdShow) {
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        return FALSE;
    }

    g_hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "tdd-client 0.0.1",
        (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX),
        CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight,
        NULL, NULL, hInstance, NULL);

    if (g_hwnd == NULL) {
        return FALSE;
    }

    ShowWindow(g_hwnd, nCmdShow);
    UpdateWindow(g_hwnd);

    return TRUE;
}


void DrawGrid(const HDC hdc) {
    const COLORREF gridColor = RGB(100, 0, 0);
    const HPEN hPen = CreatePen(PS_SOLID, 1, gridColor);
    const HPEN hOldPen = SelectObject(hdc, hPen);

    for (int x = 0; x <= gridWidth; x += tileWidth) {
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, gridHeight);
    }
    for (int y = 0; y <= gridHeight; y += tileHeight) {
        MoveToEx(hdc, 0, y, NULL);
        LineTo(hdc, gridWidth, y);
    }

    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
}

LRESULT CALLBACK WndProc(const HWND hwnd, const UINT msg, const WPARAM wParam, const LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT: {
            if (g_currentState == STATE_GAME) {
                PAINTSTRUCT ps;
                const HDC hdc = BeginPaint(hwnd, &ps);

                DrawGrid(hdc);

                RenderCharacter(hdc, &g_player, tileWidth, tileHeight);

                EndPaint(hwnd, &ps);
            } else {

            }
        }
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
