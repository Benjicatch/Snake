/*
** CCU, 2024
** Settings.hpp
** File description:
** Settings
*/

#include "Settings.hpp"

Snake::Settings::Settings(std::pair<float&, float&> &window) : ADisplay(window.first, window.second)
{
    _object = LoadTexture("assets/settings.png");
}

Snake::Settings::~Settings()
{
    UnloadTexture(_object);
}

void Snake::Settings::display()
{
    Rectangle destRect = {_window.first - (_window.first/ 9),
                          0.0f,
                          _window.first / 9,
                          _window.second / 9};
    _btnBounds = destRect;

    displayObject(destRect);
}
