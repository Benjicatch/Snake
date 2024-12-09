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
    _width = std::make_unique<InputBox>(view, textBox, 0, -20, "Width", 3);
    _height = std::make_unique<InputBox>(view, textBox, 0, 40, "Height", 3);
    _obstacles = std::make_unique<InputBox>(view, textBox, 0, 100, "Obstacles", 2);
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
    _obstacles->displayAndCheckButton();
    back = _back->displayAndCheckButton();
    if (_width->getText().size() > 0 && _height->getText().size() > 0 &&
        std::stoi(_width->getText()) >= 5 && std::stoi(_height->getText()) >= 5) {
        _goBack = true;
    }
    if (_goBack == true && back == true &&
        (_map->getSizeMap().first != std::stoi(_width->getText()) ||
        _map->getSizeMap().second != std::stoi(_height->getText()) ||
        _map->getObstacles() != std::stoi(_obstacles->getText()))) {
        _map->setObstacles(_obstacles->getText().empty() ? 0 : std::stoi(_obstacles->getText()));
        _map->resize(std::stoi(_width->getText()), std::stoi(_height->getText()));
        _map->restart();
    }
    if (!_goBack || (_width->getText().size() == 0 || _height->getText().size() == 0)) {
        _goBack = false;
        if (back == true)
            setStatus(Snake::Status::SETTINGS);
        drawText("Please enter the width and height", 0, _window->second / 12, RED);
    }
}
