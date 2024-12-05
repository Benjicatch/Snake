/*
** CCU, 2024
** Pause.hpp
** File description:
** Pause
*/

#include "Pause.hpp"

Snake::Pause::Pause(AViewDisplay &view) : AObjectDisplay(view)
{
    _object = LoadTexture("assets/pause.png");
}

Snake::Pause::~Pause()
{
    UnloadTexture(_object);
}

void Snake::Pause::display()
{
    float squareSize = std::min(_window->first, _window->second) / 5;
    Rectangle destRect = {_window->first - (_window->first/ 9),
                          0,
                          squareSize,
                          squareSize};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Pause::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked())
        setStatus(Snake::Status::PAUSE);
}
