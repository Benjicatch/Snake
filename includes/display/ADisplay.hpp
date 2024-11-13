/*
** CCU, 2024
** ADisplay.hpp
** File description:
** ADisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>

namespace Snake {
    class ADisplay {
        public:
            ADisplay(float &screen_width, float &screen_height);
            ~ADisplay() = default;
            virtual void display() = 0;
            bool isMouseOverButtonClicked();
            void displayObject(Rectangle destRect);
        protected:
            Texture2D _object;
            std::pair<float&, float&> _window;
            Vector2 _mousePoint;
            Rectangle _btnBounds;
    };
}
