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
    drawText("Game Over", 0, -_window->second / 3, BLACK);
    drawText(("Score: " + std::to_string(_map->getScore())).c_str(), 0, -_window->second / 6, BLACK);
    _settings->displayAndCheckButton();
    _restart->displayAndCheckButton();
    _back->displayAndCheckButton();
}
