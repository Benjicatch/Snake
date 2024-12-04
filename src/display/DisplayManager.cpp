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
    _pause = std::make_unique<Pause>(dynamic_cast<AViewDisplay&>(*this));
    _settings = std::make_unique<SettingsView>(dynamic_cast<AViewDisplay&>(*this));
    _menu = std::make_unique<Menu>(dynamic_cast<AViewDisplay&>(*this));
    _restart = std::make_unique<Restart>(dynamic_cast<AViewDisplay&>(*this));
    _pauseView = std::make_unique<PauseView>(dynamic_cast<AViewDisplay&>(*this));
    _gameView = std::make_unique<GameView>(dynamic_cast<AViewDisplay&>(*this));
}

Snake::DisplayManager::~DisplayManager()
{
    UnloadTexture(_backg);
    CloseWindow();
}

void Snake::DisplayManager::displayGameOver()
{
    DrawText("Game Over", _window->first / 2 - 50, _window->second / 2 - 100, 20, BLACK);
    _restart->displayAndCheckButton();
}

// -------------------------------- display pause --------------------------------

void Snake::DisplayManager::displayPause()
{
    DrawText("Pause", _window->first / 2 - 50, _window->second / 2 - 10, 20, BLACK);
    // _settings->dlisplayAndCheckButton();
    // _play->dispayAndCheckButton();
}

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
            _gameView->display();
            break;
        case Snake::Status::SETTINGS:
            _settings->display();
            break;
        case Snake::Status::PAUSE:
            _pauseView->display();
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
        chooseDisplay();
        EndDrawing();
    }
}
