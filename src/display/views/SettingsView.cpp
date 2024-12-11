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
    _width = std::make_unique<InputBox>(view, 40, 50, "Width", 3);
    _height = std::make_unique<InputBox>(view, 40, 60, "Height", 3);
    _obstacles = std::make_unique<InputBox>(view, 40,  70, "Obstacles", 2);
    _mirror = std::make_unique<InputBox>(view, 80, 60, "", 1);
    _mirror->setInputBoxStatus(InputBoxStatus::CLICKED);
}

Snake::SettingsView::~SettingsView()
{
}

void Snake::SettingsView::display()
{
    bool back = false;

    _goBack = true;
    drawText("Settings", 50, 10, BLACK);
    _width->displayAndCheckButton();
    _height->displayAndCheckButton();
    _obstacles->displayAndCheckButton();
    _mirror->displayAndCheckButton();
    drawText("Mirror mode", 75, 63, BLACK);
    back = _back->displayAndCheckButton();

    if (checkWidthHeight() == false || checkObstacles() == false)
        _goBack = false;
    if (_goBack == true && back == true) {
        checkChanges();
    }
    if (!_goBack) {
        _goBack = false;
        if (back == true)
            setStatus(Snake::Status::SETTINGS);
    }
}

void Snake::SettingsView::checkChanges()
{
    bool changes = false;
    auto sizeMap = _map->getSizeMap();
    auto mode = _map->getMode();

    if (sizeMap->first != std::stoi(_width->getText()) ||
        sizeMap->second != std::stoi(_height->getText())) {
        changes = true;
        _map->setSizeMap(std::stoi(_width->getText()), std::stoi(_height->getText()));
    }
    if ((_obstacles->getText().empty() && _map->getObstacles() != 0)) {
        changes = true;
        _map->setObstacles(0);
    } else if (!_obstacles->getText().empty() && _map->getObstacles() != std::stoi(_obstacles->getText())) {
        changes = true;
        _map->setObstacles(std::stoi(_obstacles->getText()));
    }
    if (_mirror->getText().empty() && *mode != Mode::NORMAL) {
        changes = true;
        _map->setMode(Mode::NORMAL);
    } else if (!_mirror->getText().empty() && *mode != Mode::MIRROR) {
        changes = true;
        _map->setMode(Mode::MIRROR);
    }
    if (changes == true) {
        _map->restart();
    }
}

bool Snake::SettingsView::checkObstacles()
{
    int witdh = _width->getText().empty() ? 0 : std::stoi(_width->getText());
    int height = _height->getText().empty() ? 0 : std::stoi(_height->getText());

    if (_obstacles->getText().size() > 0 && std::stoi(_obstacles->getText()) < 0) {
        drawText("Obstacles must be positive", 50, 50, RED);
        return false;
    }
    if (_obstacles->getText().size() > 0 && std::stoi(_obstacles->getText()) > (witdh * height) - 2) {
        drawText("Obstacles must be less than the size of the map", 50, 40, RED);
        return false;
    }
    return true;
}

bool Snake::SettingsView::checkWidthHeight()
{
    if (_width->getText().size() == 0 || _height->getText().size() == 0) {
        drawText("Width and Height must be filled", 50, 40, RED);
        return false;
    }
    if (_width->getText().size() > 0 && std::stoi(_width->getText()) < 5) {
        drawText("Width must be greater than 5", 50, 40, RED);
        return false;
    }
    if (_height->getText().size() > 0 && std::stoi(_height->getText()) < 5) {
        drawText("Height must be greater than 5", 50, 40, RED);
        return false;
    }
    return true;
}
