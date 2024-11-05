/*
** CCU, 2024
** Apple.hpp
** File description:
** Apple
*/

#pragma once
#include "ACase.hpp"

namespace Snake {

    class Apple : public ACase { // Correct public inheritance
    public:
        Apple();
        ~Apple();
        Apple &operator=(const Apple &apple);
        void displayApple(Rectangle destRect);
        void display(Rectangle _window_map, std::pair<int, int> sizeMap) override;
        void setApplePosition(std::pair<int, int> position);
        const std::pair<int, int> getPosition() const;
    private:
        Texture2D _apple;
        std::pair<int, int> _position;
    };
}
