/*
** CCU, 2024
** Map.hpp
** File description:
** Map
*/

#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Apple.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "AGame.hpp"

namespace Snake {

    class Map : public AGame {
        public:
            Map(int x, int y);
            Map(const Map &other) = delete;
            ~Map();
            void resize(int x, int y);
            void restart();
            std::pair<int, int> getSizeMap() const;
            std::vector<std::pair<int, int>> getFreeSlots() const;
            const std::vector<std::vector<std::shared_ptr<ICase>>>& getMap() const;
            const std::shared_ptr<Snake::Apple>& getApple() const; // Move unique pointer
            const std::shared_ptr<Snake::Player>& getPlayer() const; // Move unique pointer
            bool setPlayerPosition(Direction direction);
            const Direction& getLastDirection() const;
            const int& getObstacles() const;
            void setObstacles(int obstacles);
            void placeObstacles();
        private:
            bool setApplePosition();
            bool checkMirror(std::pair<int, int> new_position);
            Direction _last_direction;
            std::pair<int, int> _size_map;
            std::vector<std::vector<std::shared_ptr<ICase>>> _map;
            std::shared_ptr<Apple> _apple;
            std::shared_ptr<Player> _player;
            int _nbObstacles = 0;
            std::deque<std::shared_ptr<Obstacle>> _obstacles;
    };
}
