/*
** CCU, 2024
** Apple.cpp
** File description:
** Apple
*/
#include "Apple.hpp"

Snake::Apple::Apple()
{
    _apple = LoadTexture("assets/apple.png");
}

Snake::Apple::~Apple()
{
    UnloadTexture(_apple);
}

Snake::Apple &Snake::Apple::operator=(const Snake::Apple &apple)
{
    _apple = apple._apple;
    return *this;
}

void Snake::Apple::displayApple(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_apple.width, (float)_apple.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_apple, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::Apple::display(Rectangle _window_map, std::pair<int, int> sizeMap)
{
    float square_width = _window_map.width / sizeMap.first;
    float square_height = _window_map.height / sizeMap.second;

    displayApple({_window_map.x + _position.first * square_width,
                    _window_map.y + _position.second * square_height,
                    square_width,
                    square_height});
}

void Snake::Apple::setApplePosition(std::pair<int, int> position)
{
    _position = position;
}

const std::pair<int, int> Snake::Apple::getPosition() const
{
    return _position;
}
