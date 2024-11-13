/*
** CCU, 2024
** IDisplay.hpp
** File description:
** IDisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>

namespace Snake {

    enum Status {
        MENU,
        GAME,
        SETTINGS,
        PAUSE,
        GAME_OVER
    };

    class IDisplay {
        public:
            virtual ~IDisplay() = 0;
            virtual void display() = 0;
            virtual bool isMouseOverButtonClicked() = 0;
            virtual void displayObject(Rectangle destRect) = 0;
            virtual void displayAndCheckButton() = 0;
    };
}
