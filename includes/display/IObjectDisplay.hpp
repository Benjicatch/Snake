/*
** CCU, 2024
** IObjectDisplay.hpp
** File description:
** IObjectDisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>

namespace Snake {

    enum MouseState {
        MOUSE_IDLE,
        MOUSE_IDLE_PRESSED,
        MOUSE_HOVER,
        MOUSE_HOVER_PRESSED,
    };

    class IObjectDisplay {
        public:
            virtual void display() = 0;
            virtual MouseState isMouseOverButtonClicked() = 0;
            virtual void displayObject(Rectangle destRect) = 0;
            virtual bool displayAndCheckButton() = 0;
    };
}
