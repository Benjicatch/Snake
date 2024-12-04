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
    float width = _window->first / 9;
    float height = _window->second / 9;
    Rectangle destRect = {0,
                          0,
                          width,
                          height};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Back::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked())
        setStatus(Status::MENU);
}
