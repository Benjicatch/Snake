/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include "Display.hpp"

Snake::Display::Display() : _map(20, 20), _screen_width(800), _screen_height(450)
{
    InitWindow(_screen_width, _screen_height, "Snake");
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    _backg = LoadTexture("assets/background.png");
}

Snake::Display::~Display()
{
    UnloadTexture(_backg);
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

void Snake::Display::displayBackground()
{
    Rectangle srcRect = {0.0f, 0.0f, (float)_backg.width, (float)_backg.height};
    Rectangle destRect = {0.0f, 0.0f, _screen_width, _screen_height};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(_backg, srcRect, destRect, origin, 0.0f, WHITE);
}

void Snake::Display::display()
{
    while (!WindowShouldClose())
    {
        setScreenHeight(GetScreenHeight());
        setScreenWidth(GetScreenWidth());
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayBackground();
        EndDrawing();
    }
}
