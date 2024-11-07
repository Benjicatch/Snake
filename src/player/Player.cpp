/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include "Player.hpp"

Snake::Player::Player()
{
    _position = {5, 5};
    _object = LoadTexture("assets/head.png");
}

Snake::Player::~Player()
{
    UnloadTexture(_object);
}

void Snake::Player::move(Direction direction)
{
    switch (direction) {
    case UP:
        _position.second -= 1;
        break;
    case DOWN:
        _position.second += 1;
        break;
    case LEFT:
        _position.first -= 1;
        break;
    case RIGHT:
        _position.first += 1;
        break;
    default:
        break;
    }
}