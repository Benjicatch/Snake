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

namespace Snake {

    enum class TypeCase {
        EMPTY,
        SNAKE,
        BODY,
        APPLE
    };

    class Map { // Correct public inheritance
        public:
            Map(int x, int y);
            Map(const Map &other) = delete; // Disable copy
            ~Map();
            void resize(int x, int y);
            std::pair<int, int> getSizeMap() const;
            std::vector<std::pair<int, int>> getFreeSlots() const;
            const std::vector<std::vector<TypeCase>>& getMap() const;
            const std::unique_ptr<Snake::Apple>& getApple() const; // Move unique pointer
            void setApplePosition();
    private:
        std::pair<int, int> _size_map;
        std::vector<std::vector<TypeCase>> _map;
        std::unique_ptr<Apple> _apple; // Unique pointer to manage Apple
    };
}
