/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#pragma once
#include <iostream>
#include "ACase.hpp"

namespace Snake {

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class Body
    {
        public:
            Body();
            ~Body();
            void move(Direction direction);

        private:
            std::pair<int, int> _position;
    };

    class Player : public ACase
    {
        public:
            Player();
            ~Player();
            void move(Direction direction);
            void eat();

        private:
            std::pair<int, int> _position;
    };
}
