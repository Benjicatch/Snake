/*
** CCU, 2024
** Play.hpp
** File description:
** Play
*/

#include "Play.hpp"

Snake::Play::Play(AViewDisplay &view) : AObjectDisplay(view)
{
    _object = LoadTexture("assets/play.png");
}

Snake::Play::~Play()
{
    UnloadTexture(_object);
}

void Snake::Play::display()
{
    float width = _window->first / 9;
    float height = _window->second / 9;
    Rectangle destRect = {_window->first / 2 - (width / 2),
                          _window->second / 2 - (height / 2),
                          width,
                          height};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Play::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked())
        setStatus(Snake::Status::GAME);
}
