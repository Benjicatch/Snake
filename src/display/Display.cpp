/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include "Display.hpp"

Snake::Display::Display() : _screen_width(800), _screen_height(450)
{
    InitWindow(_screen_width, _screen_height, "Snake");
    _map = std::make_shared<Map>(10, 5);
    SetTargetFPS(FPS);
    _timer = TIMER;
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    _backg = LoadTexture("assets/background.png");
    _grass = LoadTexture("assets/grass.png");
}

Snake::Display::~Display()
{
    UnloadTexture(_backg);
    UnloadTexture(_grass);
    CloseWindow();
}

float Snake::Display::getScreenHeight()
{
    return _screen_height;
}

float Snake::Display::getScreenWidth()
{
    return _screen_width;
}

void Snake::Display::setScreenHeight(float screen_height)
{
    _screen_height = screen_height;
}

void Snake::Display::setScreenWidth(float screen_width)
{
    _screen_width = screen_width;
}

void Snake::Display::displayGrass(Rectangle destRect)
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_grass.width, (float)_grass.height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_grass, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::Display::displayBackground()
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_backg.width, (float)_backg.height};
    Rectangle destRect = {0.0f, 0.0f, _screen_width, _screen_height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_backg, srcRect, destRect, origin, 0.0f, WHITE);
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

void Snake::Display::handleEvent()
{
    switch (_last_direction) {
        case Snake::Direction::UP:
            _map->setPlayerPosition(Direction::UP);
            break;
        case Snake::Direction::DOWN:
            _map->setPlayerPosition(Direction::DOWN);
            break;
        case Snake::Direction::LEFT:
            _map->setPlayerPosition(Direction::LEFT);
            break;
        case Snake::Direction::RIGHT:
            _map->setPlayerPosition(Direction::RIGHT);
            break;
        default:
            _map->setPlayerPosition(_last_direction);
            break;
    }
}

void Snake::Display::getEvent()
{
    auto event = GetKeyPressed();
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    }
    switch (event) {
        case KEY_UP:
            _last_direction = Direction::UP;
            break;
        case KEY_DOWN:
            _last_direction = Direction::DOWN;
            break;
        case KEY_LEFT:
            _last_direction = Direction::LEFT;
            break;
        case KEY_RIGHT:
            _last_direction = Direction::RIGHT;
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
        getEvent();
        _window_map = { _screen_width - (_screen_width - 200), _screen_height - (_screen_height - 80), (_screen_width - 400), (_screen_height - 160) };
        if (_timer <= 0) {
            _timer = TIMER;
            handleEvent();
        } else {
            _timer--;
        }
        displayMap();
        EndDrawing();
    }
}
