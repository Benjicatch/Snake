/*
** CCU, 2024
** Map.hpp
** File description:
** Map
*/

#pragma once
#include "ICase.hpp"

namespace Snake {

    class ACase : public ICase
    {
        public:
            ~ACase();
            void display(Rectangle _window_map, std::pair<int, int> sizeMap);
        private:
            std::pair<int, int> _position;
    };
}
