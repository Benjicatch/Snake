/*
** CCU, 2024
** Settings.hpp
** File description:
** Settings
*/

#include "Settings.hpp"

Snake::Settings::Settings(AViewDisplay &view) : AObjectDisplay(view)
{
    _object = LoadTexture("assets/settings.png");
}

Snake::Settings::~Settings()
{
    UnloadTexture(_object);
}

void Snake::Settings::display()
{
    float squareSize = std::min(_window->first, _window->second) / 5;
    Rectangle destRect = {_window->first - (_window->first / 9),
                          0.0f,
                          squareSize,
                          squareSize};
    _btnBounds = destRect;

    displayObject(destRect);
}

void Snake::Settings::displayAndCheckButton()
{
    display();
    if (isMouseOverButtonClicked())
        setStatus(Snake::Status::SETTINGS);
}
