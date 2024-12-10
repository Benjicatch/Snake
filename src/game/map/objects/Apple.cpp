/*
** CCU, 2024
** Apple.cpp
** File description:
** Apple
*/
#include "Apple.hpp"

Snake::Apple::Apple()
{
    _object = LoadTexture("assets/apple.png");
    _type = CaseType::APPLE;
}

Snake::Apple::~Apple()
{
    UnloadTexture(_object);
}
