/*
** CCU, 2024
** map.cpp
** File description:
** map
*/
#include "Map.hpp"

Snake::Map::Map(int x, int y) : _size_map({x, y}), _map()
{
    srand(time(NULL));
    this->resize(x, y);
    _apple = std::make_unique<Apple>();
    setApplePosition();
}

Snake::Map::~Map()
{
}

void Snake::Map::resize(int x, int y)
{
    _size_map = {x, y};
    _map.clear();
    _map.resize(x);
    for (int i = 0; i < x; ++i) {
        _map[i].resize(y);
        for (int j = 0; j < y; ++j) {
            _map[i][j] = Snake::TypeCase::EMPTY;
        }
    }
}

std::pair<int, int> Snake::Map::getSizeMap() const
{
    return _size_map;
}

const std::vector<std::vector<Snake::TypeCase>>& Snake::Map::getMap() const
{
    return _map;
}

std::vector<std::pair<int, int>> Snake::Map::getFreeSlots() const
{
    std::vector<std::pair<int, int>> free_slots;

    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == Snake::TypeCase::EMPTY) {
                std::cout << "Free slot: " << i << " " << j << std::endl;
                free_slots.push_back({i, j});
            }
        }
    }
    return free_slots;
}

const std::unique_ptr<Snake::Apple>& Snake::Map::getApple() const
{
    return _apple;
}

void Snake::Map::setApplePosition()
{
    std::vector<std::pair<int, int>> free_slots = this->getFreeSlots();
    int index = rand() % free_slots.size();

    if (_map[_apple->getPosition().first][_apple->getPosition().second] != Snake::TypeCase::APPLE) {
        _apple->setPosition(free_slots[index]);
        _map[free_slots[index].first][free_slots[index].second] = Snake::TypeCase::APPLE;
    }
}
