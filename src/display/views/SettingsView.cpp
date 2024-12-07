/*
** CCU, 2024
** SettingsView.hpp
** File description:
** SettingsView
*/

#include "SettingsView.hpp"

Snake::SettingsView::SettingsView(AViewDisplay &view) : AViewDisplay(view)
{
    Rectangle textBox = { _window->first / 2 - 100, _window->second / (float)1.5, 225, 50 };
    _back = std::make_unique<Back>(view);
    _width = std::make_unique<InputBox>(view, textBox, 0, "Width", 20, 3);
    _height = std::make_unique<InputBox>(view, textBox, 60, "Height", 20, 3);
}

Snake::SettingsView::~SettingsView()
{
}

void Snake::SettingsView::display()
{
    _back->displayAndCheckButton();
    DrawText("Settings", _window->first / 2 - 50, _window->second / 2 - 10, 20, BLACK);
    _width->displayAndCheckButton();
    _height->displayAndCheckButton();
}
