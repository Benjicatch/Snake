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
    };
}
