/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include "Display.hpp"

Snake::Display::Display(int x, int y) : _screen_width(800), _screen_height(450)
{
    std::pair<float&, float&> window = { _screen_width, _screen_height };
    InitWindow(_screen_width, _screen_height, "Snake");
    _map = std::make_shared<Map>(x, y);
    SetTargetFPS(FPS);
    _timer = TIMER;
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    _backg = LoadTexture("assets/background.png");
    _grass = LoadTexture("assets/grass.png");
    _pause = std::make_unique<Pause>(window, _status);
    _settings = std::make_unique<SettingsView>(window, _status);
    _menu = std::make_unique<Menu>(window, _status);
    _restart = std::make_unique<Restart>(window, _status);
}

Snake::Display::~Display()
{
    UnloadTexture(_backg);
    UnloadTexture(_grass);
    CloseWindow();
}

void Snake::Display::setScreenHeight(float screen_height)
{
    _screen_height = screen_height;
}

void Snake::Display::setScreenWidth(float screen_width)
{
    _screen_width = screen_width;
}

// -------------------------------- event --------------------------------

void Snake::Display::handleEvent()
{
    _map->setPlayerPosition(_last_direction.front());
    _last_direction.pop_front();
}

void Snake::Display::getEvent()
{
    auto event = GetKeyPressed();
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    }
    switch (event) {
        case KEY_UP:
        case KEY_W:
            _last_direction.push_back(Direction::UP);
            break;
        case KEY_DOWN:
        case KEY_S:
            _last_direction.push_back(Direction::DOWN);
            break;
        case KEY_LEFT:
        case KEY_A:
            _last_direction.push_back(Direction::LEFT);
            break;
        case KEY_RIGHT:
        case KEY_D:
            _last_direction.push_back(Direction::RIGHT);
            break;
        default:
            _last_direction.push_back(Direction::NONE);
            break;
    }
    if (_last_direction.size() > 1)
        _last_direction.erase(std::remove(_last_direction.begin(), _last_direction.end(), Direction::NONE), _last_direction.end());
    else
        _last_direction.erase(unique( _last_direction.begin(), _last_direction.end() ), _last_direction.end());
}

// -------------------------------- text display --------------------------------

void Snake::Display::displayGameOver()
{
    DrawText("Game Over", _screen_width / 2 - 50, _screen_height / 2 - 100, 20, BLACK);
    displayScore();
    _restart->displayAndCheckButton();
}

void Snake::Display::displayScore()
{
    DrawText(("Score: " + std::to_string(_map->getScore())).c_str(), 100, 10, 20, BLACK);
}

// -------------------------------- display game --------------------------------

void Snake::Display::displayGrass(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_grass.width, (float)_grass.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_grass, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::Display::displayMap()
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

void Snake::Display::displayGame()
{
    getEvent();
    if (_timer <= 0) {
        _timer = TIMER;
        handleEvent();
    } else if (_status != Snake::Status::PAUSE) {
        _timer--;
    }
    if (!_map->getPlayer()->isAlive())
        _status = Snake::Status::GAME_OVER;
    displayMap();
    displayScore();
    _pause->displayAndCheckButton();
}

// -------------------------------- display pause --------------------------------

void Snake::Display::displayPause()
{
    DrawText("Pause", _screen_width / 2 - 50, _screen_height / 2 - 10, 20, BLACK);
    // _settings->dlisplayAndCheckButton();
    // _play->dispayAndCheckButton();
}

// -------------------------------- display loop --------------------------------

void Snake::Display::displayBackground()
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_backg.width, (float)_backg.height};
    Rectangle destRect = {0.0f, 0.0f, _screen_width, _screen_height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_backg, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::Display::chooseDisplay()
{
    switch (_status) {
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
            _status = Snake::Status::GAME;
            break;
        default:
            break;
    }
}

void Snake::Display::display()
{
    while (!WindowShouldClose()) {
        setScreenHeight(GetScreenHeight());
        setScreenWidth(GetScreenWidth());
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayBackground();
        _window_map = { _screen_width - (_screen_width - 200), _screen_height - (_screen_height - 80), (_screen_width - 400), (_screen_height - 160) };
        chooseDisplay();
        EndDrawing();
    }
}
