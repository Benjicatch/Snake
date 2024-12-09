/*
** CCU, 2024
** GameView.hpp
** File description:
** GameView
*/

#include "GameView.hpp"

Snake::GameView::GameView(AViewDisplay &view) : AViewDisplay(view)
{
    _pause = std::make_unique<Pause>(view);
    _timer = TIMER;
    _grass = LoadTexture("assets/grass.png");
}

Snake::GameView::~GameView()
{
    UnloadTexture(_grass);
}

void Snake::GameView::display()
{
    setWindowMap({ _window->first - (_window->first - 200), _window->second - (_window->second - 80), (_window->first - 400), (_window->second - 160) });
    getEvent();
    if (_timer <= 0) {
        _timer = TIMER;
        handleEvent();
    } else if (*_status == Snake::Status::GAME) {
        _timer--;
    }
    if (!_map->getPlayer()->isAlive())
        setStatus(Snake::Status::GAME_OVER);
    if (_map->getWin())
        setStatus(Snake::Status::WINNING);
    displayMap();
    _pause->displayAndCheckButton();
    drawText(("Score: " + std::to_string(_map->getScore())).c_str(), -_window->first / 2.4, -_window->second / 2.2, BLACK);
}

void Snake::GameView::handleEvent()
{
    Direction direction = _map->getLastDirection();
    bool isRecursing = false;

    // check if direction are opposite
    if (direction == Direction::UP && _directions.front() == Direction::DOWN ||
        direction == Direction::DOWN && _directions.front() == Direction::UP ||
        direction == Direction::LEFT && _directions.front() == Direction::RIGHT ||
        direction == Direction::RIGHT && _directions.front() == Direction::LEFT) {
        _directions.pop_front();
        isRecursing = true;
        handleEvent();
    }
    if (_directions.size() != 0 && isRecursing == false) {
        _map->setPlayerPosition(_directions.front());
        _directions.pop_front();
    } else if (isRecursing == false) {
        _map->setPlayerPosition(direction);
    }
}

void Snake::GameView::getEvent()
{
    auto event = getKey();
    switch (event) {
        case KEY_UP:
        case KEY_W:
            _directions.push_back(Direction::UP);
            break;
        case KEY_DOWN:
        case KEY_S:
            _directions.push_back(Direction::DOWN);
            break;
        case KEY_LEFT:
        case KEY_A:
            _directions.push_back(Direction::LEFT);
            break;
        case KEY_RIGHT:
        case KEY_D:
            _directions.push_back(Direction::RIGHT);
            break;
        default:
            _directions.push_back(Direction::NONE);
            break;
    }
    if (_directions.size() > 1)
        _directions.erase(std::remove(_directions.begin(), _directions.end(), Direction::NONE), _directions.end());
    else
        _directions.erase(unique( _directions.begin(), _directions.end() ), _directions.end());
}

void Snake::GameView::displayMap()
{
    float square_width = _window_map.width / _map->getSizeMap().first;
    float square_height = _window_map.height / _map->getSizeMap().second;
    auto map = _map->getMap();

    for (int i = 0; i < _map->getSizeMap().first; i++) {
        for (int j = 0; j < _map->getSizeMap().second; j++) {
            displayGrass({ _window_map.x + i * square_width,
                           _window_map.y + j * square_height,
                           square_width,
                           square_height });
            if (map[i][j] != nullptr)
                map[i][j]->display(_window_map, _map->getSizeMap());
        }
    }
}

void Snake::GameView::displayGrass(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_grass.width, (float)_grass.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_grass, srcRect, destRect, origin, 0.0f, WHITE);
}
