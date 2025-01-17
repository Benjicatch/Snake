/*
** CCU, 2024
** AObjectDisplay.cpp
** File description:
** AObjectDisplay
*/

#include "AObjectDisplay.hpp"

Snake::AObjectDisplay::AObjectDisplay(AViewDisplay &view) : AViewDisplay(view)
{
}

void Snake::AObjectDisplay::displayObject(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_object.width, (float)_object.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_object, srcRect, destRect, origin, 0.0f, WHITE);
}

Snake::MouseState Snake::AObjectDisplay::isMouseOverButtonClicked()
{
    _mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(_mousePoint, _btnBounds)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return MOUSE_HOVER_PRESSED;
        return MOUSE_HOVER;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return MOUSE_IDLE_PRESSED;
    return MOUSE_IDLE;
}
