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

namespace Snake {

    class Map { // Correct public inheritance
        public:
            Map(int x, int y);
            Map(const Map &other) = delete; // Disable copy
            ~Map();
            void resize(int x, int y);
            std::pair<int, int> getSizeMap() const;
            std::vector<std::pair<int, int>> getFreeSlots() const;
            const std::vector<std::vector<std::shared_ptr<ICase>>>& getMap() const;
            const std::shared_ptr<Snake::Apple>& getApple() const; // Move unique pointer
            const std::shared_ptr<Snake::Player>& getPlayer() const; // Move unique pointer
            void checkSetApplePosition();
            bool setPlayerPosition(Direction direction);
    private:
        void setApplePosition();
        std::pair<int, int> _size_map;
        std::vector<std::vector<std::shared_ptr<ICase>>> _map;
        std::shared_ptr<Apple> _apple;
        std::shared_ptr<Player> _player;
    };
}
