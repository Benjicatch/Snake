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
            virtual void display(Rectangle _window_map, std::pair<int, int> sizeMap) = 0;
    };
}
