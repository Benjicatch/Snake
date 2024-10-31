/*
** CCU, 2024
** map.cpp
** File description:
** map
*/
#include "Map.hpp"

Map::Map(int x, int y) : _x(x), _y(y)
{
}

Map::~Map()
{
}

void Map::resize(int x, int y)
{
    _x = x;
    _y = y;
}
