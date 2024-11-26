/*
** CCU, 2024
** Restart.hpp
** File description:
** Restart
*/

#include "Restart.hpp"

Snake::Restart::Restart(std::pair<float&, float&> &window, Status &statue) : ADisplay(window.first, window.second, statue)
{
    _object = LoadTexture("assets/restart.png");
}

Snake::Restart::~Restart()
{
    UnloadTexture(_object);
}

void Snake::Restart::display()
{
    float width = _window.first / 9;
    float height = _window.second / 9;
    Rectangle destRect = {_window.first / 2 - (width / 2),
                          _window.second / 2 - (height / 2),
                          width,
                          height};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Restart::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked()) {
        _status = Status::RESTART;
    }
}
