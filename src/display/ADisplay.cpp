/*
** CCU, 2024
** ADisplay.cpp
** File description:
** ADisplay
*/

#include "ADisplay.hpp"

Snake::ADisplay::ADisplay(float &screen_width, float &screen_height, Status &statue) : _window(screen_width, screen_height), _status(statue)
{
}

void Snake::ADisplay::displayObject(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_object.width, (float)_object.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_object, srcRect, destRect, origin, 0.0f, WHITE);
}

bool Snake::ADisplay::isMouseOverButtonClicked()
{
    _mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(_mousePoint, _btnBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        std::cout << "Button clicked" << std::endl;
        return true;
    }
    return false;
}
