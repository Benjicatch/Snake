/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include "Player.hpp"

Snake::Body::Body(int x, int y)
{
    _position = {x, y};
    _object = LoadTexture("assets/body.png");
    _type = CaseType::SNAKE_BODY;
}

Snake::Body::~Body()
{
    UnloadTexture(_object);
}

void Snake::Body::setOldPosition()
{
    _old_position = _position;
}

std::pair<int, int> Snake::Body::getOldPosition() const
{
    return _old_position;
}

Snake::Player::Player(int x, int y) : _isAlive(true), _initPosition({x, y})
{
    _position = {x, y};
    _object = LoadTexture("assets/head.png");
    _type = CaseType::SNAKE_HEAD;
    addBody(x + 1, y);
}

Snake::Player::~Player()
{
    UnloadTexture(_object);
}

void Snake::Player::moveBody(Direction direction)
{
    std::pair<int, int> tmp = _position;

    switch (direction) {
        case Direction::UP:
            _position.second -= 1;
            break;
        case Direction::DOWN:
            _position.second += 1;
            break;
        case Direction::LEFT:
            _position.first -= 1;
            break;
        case Direction::RIGHT:
            _position.first += 1;
            break;
    }
    for (auto &body : _body) {
        std::pair<int, int> tmp2 = body->getPosition();

        body->setOldPosition();
        body->setPosition(tmp);
        tmp = tmp2;
    }
}

void Snake::Player::addBody(int x, int y)
{
    std::shared_ptr<Snake::Body> new_body;

    new_body = std::make_shared<Body>(x, y);
    _body.push_front(new_body);
}

std::deque<std::shared_ptr<Snake::Body>> Snake::Player::getBody() const
{
    return _body;
}

void Snake::Player::setAlive(bool isAlive)
{
    _isAlive = isAlive;
}

bool Snake::Player::isAlive() const
{
    return _isAlive;
}

void Snake::Player::restart()
{
    _position = _initPosition;
    _body.clear();
    _isAlive = true;
    addBody(_position.first + 1, _position.second);
}
