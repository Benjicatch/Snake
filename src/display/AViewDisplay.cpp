/*
** CCU, 2024
** AViewDisplay.cpp
** File description:
** AViewDisplay
*/

#include "AViewDisplay.hpp"

Snake::AViewDisplay::AViewDisplay(Status status)
{
    _window = std::make_shared<std::pair<float, float>>(std::pair<float, float>(800, 450));
    _status = std::make_shared<Status>(status);
    _key = std::make_shared<int>(0);
}

Snake::AViewDisplay::AViewDisplay(Snake::AViewDisplay &view) : _window(view._window), _status(view._status), _window_map(view._window_map), _map(view._map), _backg(view._backg), _key(view._key)
{
}

const std::shared_ptr<Snake::Status> &Snake::AViewDisplay::getStatus() const
{
    return _status;
}

void Snake::AViewDisplay::setStatus(const Status &status)
{
    *_status = status;
}

void Snake::AViewDisplay::drawText(const std::string &text, int offsetX, int offsetY, Color color)
{
    // Use default font size if not provided
    int fontSize = _window->second / 20;

    // Measure text width and adjust positioning
    float textWidth = MeasureText(text.c_str(), fontSize); // Use library function to get actual text width
    int textX = (_window->first - textWidth) * (offsetX / 100.0f);

    // Calculate Y position based on the font size
    int textHeight = fontSize; // Font height is approximately equal to the font size
    int textY = (_window->second - textHeight) * (offsetY / 100.0f);

    // Draw the text
    DrawText(text.c_str(), textX, textY, fontSize, color);
}
