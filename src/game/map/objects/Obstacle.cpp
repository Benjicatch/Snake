/*
** CCU, 2024
** Obstacle.cpp
** File description:
** Obstacle
*/
#include "Obstacle.hpp"

Snake::Obstacle::Obstacle()
{
    _object = LoadTexture("assets/obstacle.png");
    _type = CaseType::OBSTACLE;
}

Snake::Obstacle::~Obstacle()
{
    UnloadTexture(_object);
}
