/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/
// setWindow
#include "DisplayManager.hpp"

Snake::DisplayManager::DisplayManager(int x, int y) : _timer(TIMER), AViewDisplay(Snake::Status::MENU)
{
    InitWindow(_window->first, _window->second, "Snake");
    _map = std::make_shared<Map>(x, y);
    SetTargetFPS(FPS);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    _backg = LoadTexture("assets/background.png");
    _grass = LoadTexture("assets/grass.png");
    _pause = std::make_unique<Pause>(dynamic_cast<AViewDisplay&>(*this));
    _settings = std::make_unique<SettingsView>(dynamic_cast<AViewDisplay&>(*this));
    _menu = std::make_unique<Menu>(dynamic_cast<AViewDisplay&>(*this));
    _restart = std::make_unique<Restart>(dynamic_cast<AViewDisplay&>(*this));
}

Snake::DisplayManager::~DisplayManager()
{
    UnloadTexture(_backg);
    UnloadTexture(_grass);
    CloseWindow();
}

// -------------------------------- event --------------------------------

void Snake::DisplayManager::handleEvent()
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

void Snake::DisplayManager::getEvent()
{
    auto event = GetKeyPressed();
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    }
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

// -------------------------------- text display --------------------------------

void Snake::DisplayManager::displayGameOver()
{
    DrawText("Game Over", _window->first / 2 - 50, _window->second / 2 - 100, 20, BLACK);
    displayScore();
    _restart->displayAndCheckButton();
}

void Snake::DisplayManager::displayScore()
{
    DrawText(("Score: " + std::to_string(_map->getScore())).c_str(), 100, 10, 20, BLACK);
}

// -------------------------------- display game --------------------------------

void Snake::DisplayManager::displayGrass(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_grass.width, (float)_grass.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_grass, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::DisplayManager::displayMap()
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

void Snake::DisplayManager::displayGame()
{
    getEvent();
    if (_timer <= 0) {
        _timer = TIMER;
        handleEvent();
    } else if (*_status != Snake::Status::PAUSE) {
        _timer--;
    }
    if (!_map->getPlayer()->isAlive())
        setStatus(Snake::Status::GAME_OVER);
    displayMap();
    displayScore();
    _pause->displayAndCheckButton();
}

// -------------------------------- display pause --------------------------------

void Snake::DisplayManager::displayPause()
{
    DrawText("Pause", _window->first / 2 - 50, _window->second / 2 - 10, 20, BLACK);
    // _settings->dlisplayAndCheckButton();
    // _play->dispayAndCheckButton();
}

// -------------------------------- display loop --------------------------------

void Snake::DisplayManager::displayBackground()
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_backg.width, (float)_backg.height};
    Rectangle destRect = {0.0f, 0.0f, _window->first, _window->second};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_backg, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::DisplayManager::chooseDisplay()
{
    switch (*_status) {
        case Snake::Status::MENU:
            _menu->display();
            break;
        case Snake::Status::GAME:
            displayGame();
            break;
        case Snake::Status::SETTINGS:
            _settings->display();
            break;
        case Snake::Status::PAUSE:
            displayPause();
            break;
        case Snake::Status::GAME_OVER:
            displayGameOver();
            break;
        case Snake::Status::RESTART:
            _map->restart();
            setStatus(Snake::Status::GAME);
            break;
        default:
            break;
    }
}

void Snake::DisplayManager::display()
{
    while (!WindowShouldClose()) {
        _window->first = GetScreenWidth();
        _window->second = GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayBackground();
        setWindowMap({ _window->first - (_window->first - 200), _window->second - (_window->second - 80), (_window->first - 400), (_window->second - 160) });
        chooseDisplay();
        EndDrawing();
    }
}
