/*
** CCU, 2024
** AGame.hpp
** File description:
** AGame
*/

#pragma once
#include <iostream>
#include <raylib.h>
#include "IGame.hpp"

namespace Snake {

    class AGame : public IGame {
        public:
            ~AGame();
            const int& getScore() const;
            void setScore(int score);
            const bool& getWin() const;
            void setWin(bool win);
            const Mode& getMode() const;
            void setMode(Mode mode);
        private:
            int _score = 0;
            bool _win = false;
            Mode _mode = Mode::NORMAL;
    };
}
