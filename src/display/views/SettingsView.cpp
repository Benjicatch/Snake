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

void Snake::SettingsView::drawText(const std::string &text, int offsetX, int offsetY, Color color)
{
    // Use default font size if not provided
    int fontSize = _window->second / 20;

    // Measure text width and adjust positioning
    float textWidth = MeasureText(text.c_str(), fontSize); // Use library function to get actual text width
    int textX = (_window->first - textWidth) / 2 + offsetX;

    // Calculate Y position based on the font size
    int textHeight = fontSize; // Font height is approximately equal to the font size
    int textY = (_window->second - textHeight) / 2 + offsetY;

    // Draw the text
    DrawText(text.c_str(), textX, textY, fontSize, color);
}
