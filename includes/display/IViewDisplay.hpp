/*
** CCU, 2024
** IViewDisplay.hpp
** File description:
** IViewDisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>
#include <memory>

namespace Snake {

    #define FPS 60
    #define TIMER 15

    enum Status {
        MENU,
        GAME,
        SETTINGS,
        PAUSE,
        GAME_OVER,
        RESTART,
        WINNING,
    };

    class IViewDisplay {
        public:
            virtual void display() = 0;
            virtual const std::shared_ptr<Status> &getStatus() const = 0;
            virtual void setStatus(const Status &status) = 0;
    };
}
