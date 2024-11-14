/*
** CCU, 2024
** Pause.hpp
** File description:
** Pause
*/

#pragma once
#include "ADisplay.hpp"

namespace Snake {
    class Pause : public ADisplay {
        public:
            Pause(std::pair<float&, float&> &window, Status &status);
            ~Pause();
            void display() override;
            void displayAndCheckButton() override;
    };
}
