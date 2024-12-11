/*
** CCU, 2024
** AGame.cpp
** File description:
** AGame
*/

#include "AGame.hpp"

Snake::AGame::AGame()
{
    _mode = std::make_shared<Mode>(Mode::NORMAL);
    _size_map = std::make_shared<std::pair<int, int>>(std::pair<int, int>(0, 0));
}

Snake::AGame::AGame(const Snake::AGame &other)
{
    _score = other.getScore();
    _win = other.getWin();
    _mode = other.getMode();
    _size_map = other.getSizeMap();
    _map = other.getMap();
}

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

const std::shared_ptr<Snake::Mode> Snake::AGame::getMode() const
{
    return _mode;
}

void Snake::AGame::setMode(Mode mode)
{
    _mode = std::make_shared<Mode>(mode);
}

const std::vector<std::vector<std::shared_ptr<Snake::ICase>>>& Snake::AGame::getMap() const
{
    return _map;
}

void Snake::AGame::setMap(int x, int y, std::shared_ptr<Snake::ICase> map)
{
    _map[x][y] = map;
}

const std::shared_ptr<std::pair<int, int>> Snake::AGame::getSizeMap() const
{
    return _size_map;
}

void Snake::AGame::setSizeMap(int x, int y)
{
    *_size_map = {x, y};
    _map = std::vector<std::vector<std::shared_ptr<ICase>>>(x, std::vector<std::shared_ptr<ICase>>(y, nullptr));
}
