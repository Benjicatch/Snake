/*
** CCU, 2024
** InputBox.hpp
** File description:
** InputBox
*/

#pragma once
#include <iostream>
#include <memory>
#include "Back.hpp"
#include "raylib.h"

namespace Snake {
    class InputBox: public AObjectDisplay {
        public:
            InputBox(AViewDisplay &view, Rectangle rec, float y, const std::string text, int fontSize, int maxInputChars);
            ~InputBox();
            void display() override;
            void displayAndCheckButton() override;
        private:
            void checkClicked();
            Rectangle _rec;
            std::string _textShadow;
            std::string _text;
            int _fontSize;
            int _maxInputChars;
            float _y;
            bool _isClicked = false;
            int _key = 0;
    };
}
