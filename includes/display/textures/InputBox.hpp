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
            InputBox(AViewDisplay &view, Rectangle rec, float offsetX, float offsetY, const std::string text, int maxInputChars);
            ~InputBox();
            void display() override;
            bool displayAndCheckButton() override;
            const std::string& getText() const { return _text; }
        private:
            void checkClicked();
            Rectangle _rec;
            std::string _textShadow;
            std::string _text;
            int _maxInputChars;
            float _offsetX;
            float _offsetY;
            bool _isClicked = false;
    };
}
