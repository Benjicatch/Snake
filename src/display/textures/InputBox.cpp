/*
** CCU, 2024
** InputBox.hpp
** File description:
** InputBox
*/

#include "InputBox.hpp"

Snake::InputBox::InputBox(AViewDisplay &view,
                          Rectangle rec,
                          float y,
                          const std::string text,
                          int fontSize,
                          int maxInputChars) : AObjectDisplay(view),
                                               _rec(rec),
                                               _textShadow(text),
                                               _fontSize(fontSize),
                                               _maxInputChars(maxInputChars),
                                               _y(y)
{
    _btnBounds = rec;
}

Snake::InputBox::~InputBox()
{
}

void Snake::InputBox::display()
{
    Rectangle textBox = { _window->first / 2 - 100, (_window->second / (float)1.5) + _y, 225, 50 };

    _rec = textBox;
    _btnBounds = textBox;
    DrawRectangleRec(_rec, LIGHTGRAY);
    DrawRectangleLines(_rec.x, _rec.y, _rec.width, _rec.height, GRAY);
    DrawText(_text.c_str(), _rec.x + 10, _rec.y + _rec.height / 2 - _fontSize / 2, _fontSize, BLACK);
}

void Snake::InputBox::displayAndCheckButton()
{
    auto textSize = MeasureText(_text.c_str(), _fontSize);
    int key = getKey();

    display();
    checkClicked();
    if (_isClicked) {
        DrawText("_", _rec.x + 10 + textSize, _rec.y + _rec.height / 2 - _fontSize / 2, _fontSize, BLACK);
        if (key == KEY_BACKSPACE && _text.size() > 0)
            _text.pop_back();
        else if (_text.size() < _maxInputChars) {
            if (key != 0 && key != KEY_BACKSPACE)
                _text.push_back(key);
        }
    } else if (_text.empty() && !_isClicked)
        DrawText(_textShadow.c_str(), _rec.x + 10, _rec.y + _rec.height / 2 - _fontSize / 2, _fontSize, GRAY);
}

void Snake::InputBox::checkClicked()
{
    if (isMouseOverButtonClicked() == MOUSE_HOVER_PRESSED) {
        _isClicked = true;
    } else if (_isClicked && isMouseOverButtonClicked() == MOUSE_IDLE_PRESSED ||
             GetKeyPressed() == KEY_ENTER) {
        _isClicked = false;
    }
}
