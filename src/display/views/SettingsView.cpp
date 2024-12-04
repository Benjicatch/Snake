/*
** CCU, 2024
** SettingsView.hpp
** File description:
** SettingsView
*/

#include "SettingsView.hpp"

Snake::SettingsView::SettingsView(AViewDisplay &view) : AViewDisplay(view)
{
    _back = std::make_unique<Back>(view);
}

Snake::SettingsView::~SettingsView()
{
}

void Snake::SettingsView::display()
{
    _back->displayAndCheckButton();
    DrawText("Settings", _window->first / 2 - 50, _window->second / 2 - 10, 20, BLACK);
}
