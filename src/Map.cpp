/*
** CCU, 2024
** map.cpp
** File description:
** map
*/
#include "Map.hpp"

Snake::Map::Map(int x, int y) : _size_map(x, y)
{
}

Snake::Map::~Map()
{
}

void Snake::Map::resize(int x, int y)
{
    _size_map.first = x;
    _size_map.second = y;
}

std::pair<int, int> Snake::Map::getSizeMap()
{
    return _size_map;
}
