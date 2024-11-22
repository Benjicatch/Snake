/*
** CCU, 2024
** Back.hpp
** File description:
** Back
*/

#include "Back.hpp"

Snake::Back::Back(std::pair<float&, float&> &window, Status &statue) : ADisplay(window.first, window.second, statue)
{
    _object = LoadTexture("assets/back.png");
}

Snake::Back::~Back()
{
    UnloadTexture(_object);
}

void Snake::Back::display()
{
    float width = _window.first / 9;
    float height = _window.second / 9;
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
        _status = Status::MENU;
}
