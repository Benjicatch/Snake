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

    _goBack = true;
    drawText("Settings", 0, -_window->second / 8, BLACK);
    _width->displayAndCheckButton();
    _height->displayAndCheckButton();
    _obstacles->displayAndCheckButton();
    back = _back->displayAndCheckButton();
    if (checkWidthHeight() == false || checkObstacles() == false)
        _goBack = false;
    if (_goBack == true && back == true &&
        (_map->getSizeMap().first != std::stoi(_width->getText()) ||
        _map->getSizeMap().second != std::stoi(_height->getText()) ||
        _map->getObstacles() != std::stoi(_obstacles->getText()))) {
        _map->setObstacles(_obstacles->getText().empty() ? 0 : std::stoi(_obstacles->getText()));
        _map->resize(std::stoi(_width->getText()), std::stoi(_height->getText()));
        _map->restart();
    }
    if (!_goBack) {
        _goBack = false;
        if (back == true)
            setStatus(Snake::Status::SETTINGS);
    }
}

bool Snake::SettingsView::checkObstacles()
{
    int witdh = _width->getText().empty() ? 0 : std::stoi(_width->getText());
    int height = _height->getText().empty() ? 0 : std::stoi(_height->getText());

    if (_obstacles->getText().size() > 0 && std::stoi(_obstacles->getText()) < 0) {
        drawText("Obstacles must be positive", 0, _window->second / 12, RED);
        return false;
    }
    if (_obstacles->getText().size() > 0 && std::stoi(_obstacles->getText()) > (witdh * height) - 2) {
        drawText("Obstacles must be less than the size of the map", 0, _window->second / 12, RED);
        return false;
    }
    return true;
}

bool Snake::SettingsView::checkWidthHeight()
{
    if (_width->getText().size() == 0 || _height->getText().size() == 0) {
        drawText("Width and Height must be filled", 0, _window->second / 12, RED);
        return false;
    }
    if (_width->getText().size() > 0 && std::stoi(_width->getText()) < 5) {
        drawText("Width must be greater than 5", 0, _window->second / 30, RED);
        return false;
    }
    if (_height->getText().size() > 0 && std::stoi(_height->getText()) < 5) {
        drawText("Height must be greater than 5", 0, _window->second / 30, RED);
        return false;
    }
    return true;
}
