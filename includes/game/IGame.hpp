/*
** CCU, 2024
** IGame.hpp
** File description:
** IGame
*/

#pragma once
#include <iostream>
#include <raylib.h>

namespace Snake {

    enum Mode {
        NORMAL,
        MIRROR
    };

    class IGame {
        public:
            virtual ~IGame() = default;
            virtual const int& getScore() const = 0;
            virtual void setScore(int score) = 0;
            virtual const bool& getWin() const = 0;
            virtual void setWin(bool win) = 0;
            virtual const std::shared_ptr<Mode> getMode() const = 0;
            virtual void setMode(Mode mode) = 0;
    };
}
