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

    class IObjectDisplay {
        public:
            virtual void display() = 0;
            virtual bool isMouseOverButtonClicked() = 0;
            virtual void displayObject(Rectangle destRect) = 0;
            virtual void displayAndCheckButton() = 0;
    };
}
