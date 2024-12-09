/*
** CCU, 2024
** InputBox.hpp
** File description:
** InputBox
*/

#include "InputBox.hpp"

Snake::InputBox::InputBox(AViewDisplay &view,
                          Rectangle rec,
                          float offsetX,
                          float offsetY,
                          const std::string text,
                          int maxInputChars) : AObjectDisplay(view),
                                               _rec(rec),
                                               _textShadow(text),
                                               _maxInputChars(maxInputChars),
                                               _offsetY(offsetY),
                                               _offsetX(offsetX)
{
    _btnBounds = rec;
}

Snake::InputBox::~InputBox()
{
}

void Snake::InputBox::display()
{
    // Calculate font size adaptively based on window height
    float fontSize = _window->second / 20; // Example: 1/20th of window height
    float textWidth = MeasureText(_textShadow.c_str(), fontSize);
    // Define the text box rectangle
    Rectangle textBox = { 
        _window->first / 2 - 100 + _offsetX, 
        (_window->second / (float)1.5) + _offsetY, 
        std::max(textWidth + 20, 225.0f), 
        50 
    };

    // Update the internal rectangle and button bounds
    _rec = textBox;
    _btnBounds = textBox;

    // Draw the rectangle and text
    DrawRectangleRec(_rec, LIGHTGRAY);
    DrawRectangleLines(_rec.x, _rec.y, _rec.width, _rec.height, GRAY);

    // Adjust the text position so it stays visually centered
    DrawText(
        _text.c_str(),
        _rec.x + 10, 
        _rec.y + _rec.height / 2 - fontSize / 2, 
        fontSize, 
        BLACK
    );
}

bool Snake::InputBox::displayAndCheckButton()
{
    int fontSize = _window->second / 20;
    auto textSize = MeasureText(_text.c_str(), fontSize);
    int key = getKey();

    display();
    checkClicked();
    if (_isClicked) {
        DrawText("_", _rec.x + 10 + textSize, _rec.y + _rec.height / 2 - fontSize / 2, fontSize, BLACK);
        if (key == KEY_BACKSPACE && _text.size() > 0)
            _text.pop_back();
        else if (_text.size() < _maxInputChars && (key >= KEY_ZERO && key <= KEY_NINE)) {
            std::cout << key << std::endl;
            if (key != 0 && key != KEY_BACKSPACE)
                _text.push_back(key);
        }
        return true;
    } else if (_text.empty() && !_isClicked)
        DrawText(_textShadow.c_str(), _rec.x + 10, _rec.y + _rec.height / 2 - fontSize / 2, fontSize, GRAY);
    return false;
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
