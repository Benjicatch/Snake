/*
** CCU, 2024
** map.cpp
** File description:
** map
*/
#include "Map.hpp"

Snake::Map::Map(int x, int y) : _last_direction(Direction::LEFT)
{
    setSizeMap(x, y);
    srand(time(NULL));
    restart();
}

Snake::Map::~Map()
{
}

void Snake::Map::restart()
{
    auto size_map = getSizeMap();
    auto &map = getMap();

    setSizeMap(size_map->first, size_map->second);
    setScore(0);
    _player = std::make_shared<Player>(size_map->first / 2, size_map->second / 2, *this);
    _apple = std::make_shared<Apple>();
    setMap(_player->getPosition().first, _player->getPosition().second, _player);
    for (auto &body : _player->getBody()) {
        setMap(body->getPosition().first, body->getPosition().second, body);
    }
    setApplePosition();
    placeObstacles();
    setScore(0);
    _last_direction = Direction::LEFT;
    setWin(false);
}

std::vector<std::pair<int, int>> Snake::Map::getFreeSlots() const
{
    std::vector<std::pair<int, int>> free_slots;
    auto &map = getMap();

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == nullptr) {
                free_slots.push_back({i, j});
            }
        }
    }
    return free_slots;
}

const std::shared_ptr<Snake::Apple>& Snake::Map::getApple() const
{
    return _apple;
}

const std::shared_ptr<Snake::Player>& Snake::Map::getPlayer() const
{
    return _player;
}

bool Snake::Map::setApplePosition()
{
    std::vector<std::pair<int, int>> free_slots = this->getFreeSlots();
    int index = 0;
    auto &map = getMap();
    auto _size_map = getSizeMap();

    // Check if the player won
    setScore(getScore() + 1);
    if (getScore() >= ((_size_map->first * _size_map->second) - getObstacles()) / 2) {
        setWin(true);
        return false;
    }
    index = rand() % free_slots.size();
    _apple->setPosition(free_slots[index]);
    setMap(free_slots[index].first, free_slots[index].second, _apple);
    return true;
}

bool Snake::Map::setPlayerPosition(Direction direction)
{
    std::pair<int, int> new_position = _player->getPosition();
    std::shared_ptr<Snake::ICase> case_game;
    bool eat_apple = false;
    std::pair<int, int> player_position = _player->getPosition();
    auto &map = getMap();
    std::cout << _apple->getPosition().first << " " << _apple->getPosition().second << std::endl;

    if (direction == Direction::NONE)
        direction = _last_direction;
    else
        _last_direction = direction;
    switch (direction) {
        case Direction::UP:
            new_position.second -= 1;
            break;
        case Direction::DOWN:
            new_position.second += 1;
            break;
        case Direction::LEFT:
            new_position.first -= 1;
            break;
        case Direction::RIGHT:
            new_position.first += 1;
            break;
        default:
            break;
    }
    new_position = checkMirror(new_position);
    if (!_player->isAlive())
        return false;
    setMap(_player->getPosition().first, _player->getPosition().second, nullptr);
    for (auto body : _player->getBody()) {
        setMap(body->getPosition().first, body->getPosition().second, nullptr);
    }
    case_game = map[new_position.first][new_position.second];
    if (case_game != nullptr && case_game->getType() == Snake::CaseType::APPLE) {
        _player->addBody(player_position.first, player_position.second);
        eat_apple = true;
    } else {
        _player->moveBody(direction);
    }
    for (auto body : _player->getBody()) {
        setMap(body->getPosition().first, body->getPosition().second, body);
    }
    case_game = map[new_position.first][new_position.second];
    if (case_game != nullptr &&
        (case_game->getType() == Snake::CaseType::SNAKE_BODY ||
        case_game->getType() == Snake::CaseType::OBSTACLE)) {
        _player->setAlive(false);
        return false;
    }
    _player->setPosition(new_position);
    setMap(new_position.first, new_position.second, _player);
    if (eat_apple) {
        setApplePosition();
    }
    return true;
}

const Snake::Direction& Snake::Map::getLastDirection() const
{
    return _last_direction;
}

const int& Snake::Map::getObstacles() const
{
    return _nbObstacles;
}

void Snake::Map::setObstacles(int obstacles)
{
    if (obstacles < 0)
        _nbObstacles = 0;
    else
        _nbObstacles = obstacles;
}

void Snake::Map::placeObstacles()
{
    std::vector<std::pair<int, int>> free_slots = this->getFreeSlots();
    int index = 0;
    auto &map = getMap();

    _obstacles.clear();
    if (free_slots.size() < _nbObstacles)
        return;
    for (int i = 0; i < _nbObstacles; i++) {
        index = rand() % free_slots.size();
        _obstacles.push_back(std::make_shared<Obstacle>());
        setMap(free_slots[index].first, free_slots[index].second, _obstacles[i]);
        _obstacles[i]->setPosition(free_slots[index]);
        free_slots.erase(free_slots.begin() + index);
    }
}

std::pair<int, int> Snake::Map::checkMirror(std::pair<int, int> new_position)
{
    Mode mode = *getMode();
    auto _size_map = getSizeMap();

    if (mode == Mode::NORMAL &&
        (new_position.first < 0 ||
        new_position.first >= _size_map->first ||
        new_position.second < 0 ||
        new_position.second >= _size_map->second)) {
        _player->setAlive(false);
        return new_position;
    } else if (mode == Mode::MIRROR) {
        if (new_position.first < 0)
            new_position.first = _size_map->first - 1;
        if (new_position.first >= _size_map->first)
            new_position.first = 0;
        if (new_position.second < 0)
            new_position.second = _size_map->second - 1;
        if (new_position.second >= _size_map->second)
            new_position.second = 0;
    }
    return new_position;
}
