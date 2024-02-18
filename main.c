#include <stdio.h>
#include <windows.h>

#include "character.h"
#include "window.h"
#include "game.h"
#include "input.h"

int WINAPI WinMain(const HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, const int nShowCmd) {
    if (!InitializeWindow(hInstance, nShowCmd)) {
        MessageBox(NULL, "Window Initialization Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    InitializeCharacter(&g_player, 12, 8);

    MSG Msg;
    while (TRUE) {
        if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)) {
            if (Msg.message == WM_QUIT) {
                printf("WM_QUIT\n");
                break;
            }
            printf("Message received\n");
            ProcessInput(&Msg, &g_player);

            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        } else {
            GameLoop();
        }
    }

    return Msg.wParam;
}
