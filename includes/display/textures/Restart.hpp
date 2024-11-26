/*
** CCU, 2024
** Restart.hpp
** File description:
** Restart
*/

#pragma once
#include "ADisplay.hpp"

namespace Snake {
    class Restart : public ADisplay {
        public:
            Restart(std::pair<float&, float&> &window, Status &status);
            ~Restart();
            void display() override;
            void displayAndCheckButton() override;
    };
}
