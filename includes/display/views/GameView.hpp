/*
** CCU, 2024
** GameView.hpp
** File description:
** GameView
*/

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include "Pause.hpp"
#include "raylib.h"
#include "AViewDisplay.hpp"

namespace Snake {
    class GameView : public AViewDisplay {
        public:
            GameView(AViewDisplay &view);
            ~GameView();
            void display() override;
            void displayMap();
            void handleEvent();
            void getEvent();
            void displayGrass(Rectangle destRect);
        private:
            std::unique_ptr<Pause> _pause;
            std::deque<Direction> _directions = { Direction::LEFT };
            Texture2D _grass;
            int _timer;
    };
}
