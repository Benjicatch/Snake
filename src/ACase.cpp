/*
** CCU, 2024
** ACase.cpp
** File description:
** ACase
*/

#include "ACase.hpp"

Snake::ACase::~ACase()
{
}

void Snake::ACase::setPosition(std::pair<int, int> position)
{
    _position = position;
}

const std::pair<int, int> Snake::ACase::getPosition() const
{
    return _position;
}

void Snake::ACase::displayObject(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_object.width, (float)_object.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_object, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::ACase::display(Rectangle _window_map, std::pair<int, int> sizeMap)
{
    float square_width = _window_map.width / sizeMap.first;
    float square_height = _window_map.height / sizeMap.second;

    displayObject({_window_map.x + _position.first * square_width,
                    _window_map.y + _position.second * square_height,
                    square_width,
                    square_height});
}
