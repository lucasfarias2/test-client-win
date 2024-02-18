#ifndef CHARACTER_H
#define CHARACTER_H

#include <windows.h>

typedef struct {
    int x, y;
} Character;

extern Character g_player;

void InitializeCharacter(Character* character, int startX, int startY);
void RenderCharacter(HDC hdc, const Character* character, int tileWidth, int tileHeight);
void MoveCharacter(Character* character, int deltaX, int deltaY);

#endif
