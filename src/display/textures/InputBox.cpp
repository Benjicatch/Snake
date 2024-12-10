/*
** CCU, 2024
** InputBox.hpp
** File description:
** InputBox
*/

#include "InputBox.hpp"

Snake::InputBox::InputBox(AViewDisplay &view,
                          float offsetX,
                          float offsetY,
                          const std::string text,
                          int maxInputChars) : AObjectDisplay(view),
                                               _textShadow(text),
                                               _maxInputChars(maxInputChars),
                                               _offsetY(offsetY),
                                               _offsetX(offsetX)
{
}

Snake::InputBox::~InputBox()
{
}

void Snake::InputBox::display()
{
    // Calculate font size adaptively based on window height
    float fontSize = _window->second / 20.0f; // Example: 1/20th of window height
    float textWidth = MeasureText(_textShadow.c_str(), fontSize);

    // Define rectangle dimensions dynamically
    float minWidth = 0.0f;
    float padding = _window->second / 15.0f; // Example: 1/20th of window height
    float width = std::max(textWidth + padding, minWidth); // Minimum width or text width
    float height = _window->second / 15.0f;               // Height relative to window height
    float dynamicOffsetX = _window->first * (_offsetX / 100.0f);
    float dynamicOffsetY = _window->second * (_offsetY / 100.0f);

    // Define the text box rectangle with given offsets
    Rectangle textBox = {
        dynamicOffsetX, // Center horizontally with offset
        dynamicOffsetY,               // Position vertically based on offset
        width,
        height
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
    if (_isClicked && _inputBoxStatus == InputBoxStatus::NORMAL) {
        DrawText("_", _rec.x + 10 + textSize, _rec.y + _rec.height / 2 - fontSize / 2, fontSize, BLACK);
        if (key == KEY_BACKSPACE && _text.size() > 0)
            _text.pop_back();
        else if (_text.size() < _maxInputChars && (key >= KEY_ZERO && key <= KEY_NINE)) {
            std::cout << key << std::endl;
            if (key != 0 && key != KEY_BACKSPACE)
                _text.push_back(key);
        }
        return true;
    } else if (_isClicked && _inputBoxStatus == InputBoxStatus::CLICKED) {
        if (_text.empty())
            _text.push_back('X');
        else
            _text.pop_back();
    } else if (_text.empty() && !_isClicked) {
        DrawText(_textShadow.c_str(), _rec.x + 10, _rec.y + _rec.height / 2 - fontSize / 2, fontSize, GRAY);
    }
    return false;
}

void Snake::InputBox::checkClicked()
{
    if (isMouseOverButtonClicked() == MOUSE_HOVER_PRESSED) {
        _isClicked = true;
    } else if (_isClicked && isMouseOverButtonClicked() == MOUSE_IDLE_PRESSED ||
             GetKeyPressed() == KEY_ENTER) {
        _isClicked = false;
    } else if (_inputBoxStatus == InputBoxStatus::CLICKED) {
        _isClicked = false;
    }
}
