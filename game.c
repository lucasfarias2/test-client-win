#include "game.h"
#include "gamestate.h"
#include "character.h"

void GameLoop() {
    if (g_currentState != STATE_GAME) {
        return;
    }

    InvalidateRect(g_hwnd, NULL, FALSE);
}
