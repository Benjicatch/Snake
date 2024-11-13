/*
** CCU, 2024
** Play.hpp
** File description:
** Play
*/

#pragma once
#include "ADisplay.hpp"

namespace Snake {
    class Play : public ADisplay {
        public:
            Play(std::pair<float&, float&> &window, Status &status);
            ~Play();
            void display() override;
            void displayAndCheckButton() override;
    };
}
