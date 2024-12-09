/*
** CCU, 2024
** Back.hpp
** File description:
** Back
*/

#include "Back.hpp"

Snake::Back::Back(AViewDisplay &view) : AObjectDisplay(view)
{
    _object = LoadTexture("assets/back.png");
}

Snake::Back::~Back()
{
    UnloadTexture(_object);
}

void Snake::Back::display()
{
    float squareSize = std::min(_window->first, _window->second) / 5;
    Rectangle destRect = {0,
                          0,
                          squareSize,
                          squareSize};
    _btnBounds = destRect;

    displayObject(destRect);
}

bool Snake::Back::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked() == MOUSE_HOVER_PRESSED) {
        setStatus(Status::MENU);
        return true;
    }
    return false;
}
