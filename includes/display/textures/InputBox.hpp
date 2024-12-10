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

    enum class InputBoxStatus {
        NORMAL,
        CLICKED
    };

    class InputBox: public AObjectDisplay {
        public:
            InputBox(AViewDisplay &view, float offsetX, float offsetY, const std::string text, int maxInputChars);
            ~InputBox();
            void display() override;
            bool displayAndCheckButton() override;
            const std::string& getText() const { return _text; }
            void setInputBoxStatus(InputBoxStatus status) { _inputBoxStatus = status; }
            const InputBoxStatus& getInputBoxStatus() const { return _inputBoxStatus; }
        private:
            void checkClicked();
            Rectangle _rec;
            std::string _textShadow;
            std::string _text;
            int _maxInputChars;
            float _offsetX;
            float _offsetY;
            bool _isClicked = false;
            InputBoxStatus _inputBoxStatus = InputBoxStatus::NORMAL;
    };
}
