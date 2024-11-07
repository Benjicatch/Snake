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
#include "Empty.hpp"

namespace Snake {

    class Map { // Correct public inheritance
        public:
            Map(int x, int y);
            Map(const Map &other) = delete; // Disable copy
            ~Map();
            void resize(int x, int y);
            std::pair<int, int> getSizeMap() const;
            std::vector<std::pair<int, int>> getFreeSlots() const;
            const std::vector<std::vector<std::shared_ptr<ACase>>>& getMap() const;
            const std::shared_ptr<Snake::Apple>& getApple() const; // Move unique pointer
            void setApplePosition();
    private:
        std::pair<int, int> _size_map;
        std::vector<std::vector<std::shared_ptr<ACase>>> _map;
        std::shared_ptr<Apple> _apple;
    };
}
