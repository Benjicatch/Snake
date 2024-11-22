/*
** CCU, 2024
** SettingsView.hpp
** File description:
** SettingsView
*/

#include "SettingsView.hpp"

Snake::SettingsView::SettingsView(std::pair<float&, float&> &window, Status &status) : _window(window)
{
    _back = std::make_unique<Back>(window, status);
}

Snake::SettingsView::~SettingsView()
{
}

void Snake::SettingsView::display()
{
    _back->displayAndCheckButton();
    DrawText("Settings", _window.first / 2 - 50, _window.second / 2 - 10, 20, BLACK);
}
