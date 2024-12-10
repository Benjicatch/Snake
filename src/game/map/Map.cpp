/*
** CCU, 2024
** map.cpp
** File description:
** map
*/
#include "Map.hpp"

Snake::Map::Map(int x, int y) : _last_direction(Direction::LEFT), _score(0)
{
    _size_map = {x, y};
    _map = std::vector<std::vector<std::shared_ptr<Snake::ICase>>>(x);
    srand(time(NULL));
    restart();
}

Snake::Map::~Map()
{
}

void Snake::Map::resize(int x, int y)
{
    _size_map = {x, y};
    _map = std::vector<std::vector<std::shared_ptr<ICase>>>(x, std::vector<std::shared_ptr<ICase>>(y, nullptr));
}

void Snake::Map::restart()
{
    resize(_size_map.first, _size_map.second);
    _player = std::make_shared<Player>(_size_map.first / 2, _size_map.second / 2);
    _apple = std::make_shared<Apple>();
    _map[_player->getPosition().first][_player->getPosition().second] = _player;
    for (auto body : _player->getBody()) {
        _map[body->getPosition().first][body->getPosition().second] = body;
    }
    setApplePosition();
    placeObstacles();
    _score = 0;
    _last_direction = Direction::LEFT;
}

std::pair<int, int> Snake::Map::getSizeMap() const
{
    return _size_map;
}

const std::vector<std::vector<std::shared_ptr<Snake::ICase>>>& Snake::Map::getMap() const
{
    return _map;
}

std::vector<std::pair<int, int>> Snake::Map::getFreeSlots() const
{
    std::vector<std::pair<int, int>> free_slots;

    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == nullptr) {
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

    // Check if the player won
    if (free_slots.size() <= _size_map.first * _size_map.second / 2) {
        _win = true;
        return false;
    }
    index = rand() % free_slots.size();
    _score += 1;
    _apple->setPosition(free_slots[index]);
    _map[free_slots[index].first][free_slots[index].second] = _apple;
    return true;
}

bool Snake::Map::setPlayerPosition(Direction direction)
{
    std::pair<int, int> new_position = _player->getPosition();
    std::shared_ptr<Snake::ICase> case_game;
    bool eat_apple = false;
    std::pair<int, int> player_position = _player->getPosition();

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
    if (checkMirror(new_position) == false) {
        return false;
    }
    _map[_player->getPosition().first][_player->getPosition().second] = nullptr;
    for (auto body : _player->getBody()) {
        _map[body->getPosition().first][body->getPosition().second] = nullptr;
    }
    case_game = _map[new_position.first][new_position.second];
    if (case_game != nullptr && case_game->getType() == Snake::CaseType::APPLE) {
        _player->addBody(player_position.first, player_position.second);
        eat_apple = true;
    } else {
        _player->moveBody(direction);
    }
    for (auto body : _player->getBody()) {
        _map[body->getPosition().first][body->getPosition().second] = body;
    }
    case_game = _map[new_position.first][new_position.second];
    if (case_game != nullptr &&
        (case_game->getType() == Snake::CaseType::SNAKE_BODY ||
        case_game->getType() == Snake::CaseType::OBSTACLE)) {
        _player->setAlive(false);
        return false;
    }
    _player->setPosition(new_position);
    _map[new_position.first][new_position.second] = _player;
    if (eat_apple) {
        setApplePosition();
    }
    return true;
}

const int Snake::Map::getScore() const
{
    return _score;
}

const Snake::Direction& Snake::Map::getLastDirection() const
{
    return _last_direction;
}

const bool& Snake::Map::getWin() const
{
    return _win;
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

    _obstacles.clear();
    if (free_slots.size() < _nbObstacles)
        return;
    for (int i = 0; i < _nbObstacles; i++) {
        index = rand() % free_slots.size();
        _obstacles.push_back(std::make_shared<Obstacle>());
        _map[free_slots[index].first][free_slots[index].second] = _obstacles[i];
        _obstacles[i]->setPosition(free_slots[index]);
        free_slots.erase(free_slots.begin() + index);
    }
}

bool Snake::Map::checkMirror(std::pair<int, int> new_position)
{
    if (_mode == Mode::NORMAL &&
        (new_position.first < 0 ||
        new_position.first >= _size_map.first ||
        new_position.second < 0 ||
        new_position.second >= _size_map.second)) {
        _player->setAlive(false);
        return false;
    } else if (_mode == Mode::MIRROR) {
        if (new_position.first < 0)
            new_position.first = _size_map.first - 1;
        if (new_position.first >= _size_map.first)
            new_position.first = 0;
        if (new_position.second < 0)
            new_position.second = _size_map.second - 1;
        if (new_position.second >= _size_map.second)
            new_position.second = 0;
    }
    return true;
}
