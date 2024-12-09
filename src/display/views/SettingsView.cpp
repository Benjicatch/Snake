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
    _width = std::make_unique<InputBox>(view, textBox, 0, 0, "Width", 3);
    _height = std::make_unique<InputBox>(view, textBox, 0, 60, "Height", 3);
}

Snake::SettingsView::~SettingsView()
{
}

void Snake::SettingsView::display()
{
    bool back = false;

    drawText("Settings", 0, -_window->second / 8, BLACK);
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
        drawText("Please enter the width and height", 0, _window->second / 10, RED);
    }
}
