/*
** CCU, 2024
** Empty.hpp
** File description:
** Empty
*/

#pragma once
#include "ACase.hpp"

namespace Snake {

    class Empty : public ACase { // Correct public inheritance
    public:
        Empty();
        ~Empty();
        void display(Rectangle _window_map, std::pair<int, int> sizeMap) override;
    };
}
