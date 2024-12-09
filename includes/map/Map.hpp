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

namespace Snake {

    class Map {
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
            const int getScore() const;
            const Direction& getLastDirection() const;
            const bool& getWin() const;
            const int& getObstacles() const;
            void setObstacles(int obstacles);
            void placeObstacles();
    private:
        bool setApplePosition();
        int _score;
        Direction _last_direction;
        std::pair<int, int> _size_map;
        std::vector<std::vector<std::shared_ptr<ICase>>> _map;
        std::shared_ptr<Apple> _apple;
        std::shared_ptr<Player> _player;
        bool _win = false;
        int _nbObstacles = 0;
        std::deque<std::shared_ptr<Obstacle>> _obstacles;
    };
}
