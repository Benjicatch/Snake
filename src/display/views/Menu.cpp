/*
** CCU, 2024
** Menu.hpp
** File description:
** Menu
*/

#include "Menu.hpp"

Snake::Menu::Menu(std::pair<float&, float&> &window, Status &status)
{
    _settings = std::make_unique<Settings>(window, status);
    _play = std::make_unique<Play>(window, status);
}

Snake::Menu::~Menu()
{
}

void Snake::Menu::display()
{
    _settings->displayAndCheckButton();
    _play->displayAndCheckButton();
}
