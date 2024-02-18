#include "character.h"

Character g_player;

void InitializeCharacter(Character *character, const int startX, const int startY) {
    character->x = startX;
    character->y = startY;
}

void RenderCharacter(const HDC hdc, const Character *character, const int tileWidth, const int tileHeight) {
    RECT rect;
    rect.left = character->x * tileWidth;
    rect.top = character->y * tileHeight;
    rect.right = rect.left + tileWidth;
    rect.bottom = rect.top + tileHeight;

    const HBRUSH brush = GetStockObject(WHITE_BRUSH);
    FillRect(hdc, &rect, brush);
}

void MoveCharacter(Character *character, const int deltaX, const int deltaY) {
    character->x += deltaX;
    character->y += deltaY;
}
