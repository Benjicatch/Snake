/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include "ACase.hpp"

namespace Snake {

    class Body : public ACase {
        public:
            Body(int x, int y);
            ~Body();
            void setOldPosition();
            std::pair<int, int> getOldPosition() const;
        private:
            std::pair<int, int> _old_position;
    };

    class Player : public ACase
    {
        public:
            Player(int x, int y);
            ~Player();
            void moveBody(Direction direction);
            void addBody();
            std::deque<std::shared_ptr<Body>> getBody() const;
            Direction getDirection() const;
        private:
            std::deque<std::shared_ptr<Body>> _body;
            Direction _direction = Direction::LEFT;
    };
}
