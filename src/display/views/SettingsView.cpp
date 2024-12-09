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
    bool back = false;

    DrawText("Settings", _window->first / 2 - 50, _window->second / 2 - 10, 20, BLACK);
    _width->displayAndCheckButton();
    _height->displayAndCheckButton();
    back = _back->displayAndCheckButton();
    if (_width->getText().size() > 0 && _height->getText().size() > 0) {
        _goBack = true;
    }
    if (_goBack == true && back == true) {
        _map->resize(std::stoi(_width->getText()), std::stoi(_height->getText()));
        _map->restart();
    }
    if (!_goBack || (_width->getText().size() == 0 || _height->getText().size() == 0)) {
        _goBack = false;
        if (back == true)
            setStatus(Snake::Status::SETTINGS);
        DrawText("Please enter a valid number", _window->first / 2 - 100, _window->second / 2 + 50, 20, RED);
    }
}
