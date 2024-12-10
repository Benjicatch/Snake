/*
** CCU, 2024
** PauseView.hpp
** File description:
** PauseView
*/

#include "PauseView.hpp"

Snake::PauseView::PauseView(AViewDisplay &view) : AViewDisplay(view)
{
    _settings = std::make_unique<Settings>(view);
    _play = std::make_unique<Play>(view);
    _back = std::make_unique<Back>(view);
}

Snake::PauseView::~PauseView()
{
}

void Snake::PauseView::display()
{
    _settings->displayAndCheckButton();
    _play->displayAndCheckButton();
    _back->displayAndCheckButton();
    drawText(("Score: " + std::to_string(_map->getScore())).c_str(), 15, 3, BLACK);
}
