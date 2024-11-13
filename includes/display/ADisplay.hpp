/*
** CCU, 2024
** ADisplay.hpp
** File description:
** ADisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>
#include "IDisplay.hpp"

namespace Snake {
    class ADisplay {
        public:
            ADisplay(float &screen_width, float &screen_height, Status &status);
            ~ADisplay() = default;
            virtual void display() = 0;
            bool isMouseOverButtonClicked();
            void displayObject(Rectangle destRect);
            virtual void displayAndCheckButton() = 0;
        protected:
            Texture2D _object;
            std::pair<float&, float&> _window;
            Vector2 _mousePoint;
            Rectangle _btnBounds;
            Status &_status;
    };
}
