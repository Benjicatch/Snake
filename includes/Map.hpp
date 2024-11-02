/*
** CCU, 2024
** Map.hpp
** File description:
** Map
*/

#include <iostream>

namespace Snake {
    class Map
    {
        public:
            Map(int x, int y);
            ~Map();
            void resize(int x, int y);
            std::pair<int, int> getSizeMap();

        private:
            std::pair<int, int> _size_map;
            std::pair<int, int> _apple_position;
    };
}
