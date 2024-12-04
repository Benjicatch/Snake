/*
** CCU, 2024
** GameOverView.hpp
** File description:
** GameOverView
*/

#include "GameOverView.hpp"

Snake::GameOverView::GameOverView(AViewDisplay &view) : AViewDisplay(view)
{
    _settings = std::make_unique<Settings>(view);
    _restart = std::make_unique<Restart>(view);
    _back = std::make_unique<Back>(view);
}

Snake::GameOverView::~GameOverView()
{
}

void Snake::GameOverView::display()
{
    DrawText("Game Over", _window->first / 2 - 50, _window->second / 2 - 100, 20, BLACK);
    DrawText(("Score: " + std::to_string(_map->getScore())).c_str(), 100, 10, 20, BLACK);
    _settings->displayAndCheckButton();
    _restart->displayAndCheckButton();
    _back->displayAndCheckButton();
}
