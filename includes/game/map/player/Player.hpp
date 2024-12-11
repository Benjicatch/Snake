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
#include "AGame.hpp"

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

    class Player : public ACase, public AGame {
        public:
            Player(int x, int y, AGame &game);
            ~Player();
            void moveBody(Direction direction);
            void addBody(int x, int y);
            std::deque<std::shared_ptr<Body>> getBody() const;
            void setAlive(bool isAlive);
            bool isAlive() const;
            void restart();
        private:
            std::deque<std::shared_ptr<Body>> _body;
            bool _isAlive;
            std::pair<int, int> _initPosition;
    };
}
