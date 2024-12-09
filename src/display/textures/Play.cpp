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
    float squareSize = std::min(_window->first, _window->second) / 5;
    Rectangle destRect = {_window->first / 2 - (squareSize / 2),
                          _window->second / 2 - (squareSize / 2),
                          squareSize,
                          squareSize};
    _btnBounds = destRect;

    displayObject(destRect);
}

bool Snake::Play::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked() == MOUSE_HOVER_PRESSED) {
        setStatus(Snake::Status::GAME);
        return true;
    }
    return false;
}
