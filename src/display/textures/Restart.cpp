/*
** CCU, 2024
** Restart.hpp
** File description:
** Restart
*/

#include "Restart.hpp"

Snake::Restart::Restart(AViewDisplay &view) : AObjectDisplay(view)
{
    _object = LoadTexture("assets/restart.png");
}

Snake::Restart::~Restart()
{
    UnloadTexture(_object);
}

void Snake::Restart::display()
{
    float squareSize = std::min(_window->first, _window->second) / 5;
    Rectangle destRect = {_window->first / 2 - (squareSize / 2),
                          _window->second / 2 - (squareSize / 2),
                          squareSize,
                          squareSize};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Restart::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked()) {
        setStatus(Snake::Status::RESTART);
    }
}
