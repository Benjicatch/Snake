/*
** CCU, 2024
** Menu.hpp
** File description:
** Menu
*/

#include "Menu.hpp"

Snake::Menu::Menu(AViewDisplay &view) : AViewDisplay(view)
{
    _settings = std::make_unique<Settings>(view);
    _play = std::make_unique<Play>(view);
}

Snake::Menu::~Menu()
{
}

void Snake::Menu::display()
{
    bool canplay = true;

    _settings->displayAndCheckButton();
    canplay = _play->displayAndCheckButton();
    if (canplay && (_map->getSizeMap().first < 5 || _map->getSizeMap().second < 5)) {
        setStatus(Status::SETTINGS);
    }
}
