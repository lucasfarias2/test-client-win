#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "character.h"

typedef enum {
    STATE_UI,
    STATE_GAME
} GameState;

extern GameState g_currentState;
extern HWND g_hwnd;

#endif
