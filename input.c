#include "input.h"

void ProcessInput(const MSG *msg, Character *character) {
    switch (msg->message) {
        case WM_KEYDOWN:
            switch (msg->wParam) {
                case 'W': MoveCharacter(character, 0, -1);
                    break;
                case 'S': MoveCharacter(character, 0, 1);
                    break;
                case 'A': MoveCharacter(character, -1, 0);
                    break;
                case 'D': MoveCharacter(character, 1, 0);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
