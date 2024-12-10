/*
** CCU, 2024
** AGame.cpp
** File description:
** AGame
*/

#include "AGame.hpp"

Snake::AGame::~AGame()
{
}

const int& Snake::AGame::getScore() const
{
    return _score;
}

void Snake::AGame::setScore(int score)
{
    _score = score;
}

const bool& Snake::AGame::getWin() const
{
    return _win;
}

void Snake::AGame::setWin(bool win)
{
    _win = win;
}

const Snake::Mode& Snake::AGame::getMode() const
{
    return _mode;
}

void Snake::AGame::setMode(Mode mode)
{
    _mode = mode;
}
