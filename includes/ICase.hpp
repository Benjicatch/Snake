/*
** CCU, 2024
** ICase.hpp
** File description:
** ICase
*/

#pragma once
#include <iostream>
#include <memory>
#include <raylib.h>

namespace Snake {

    class ICase
    {
        public:
            virtual ~ICase() = default;
            virtual void setPosition(std::pair<int, int> position) = 0;
            virtual const std::pair<int, int> getPosition() const = 0;
            virtual void displayObject(Rectangle destRect) = 0;
            virtual void display(Rectangle _window_map, std::pair<int, int> sizeMap) = 0;
    };
}